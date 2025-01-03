//
// Created by peter on 01/12/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <memory>
#include <ostream>
#include <print>

#include "types.h"

#include "base.h"
#include "bitboard.h"
#include "Board_Status.h"
#include "colors.h"

inline constexpr std::string_view fen_empty_board = "8/8/8/8/8/8/8/8 w - - 0 1 ";
inline constexpr std::string_view fen_start_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 ";
inline constexpr std::string_view fen_tricky_position =
        "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 ";
inline constexpr std::string_view fen_killer_position =
        "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
inline constexpr std::string_view fen_cmk_position =
        "r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 b - - 0 9 ";


namespace Kangaroo {
    template<Color color>
    constexpr _Inline Bitboard regular_pawn_move(const Bitboard mask) {
        Bitboard pawn_move;

        if constexpr (color == Color::white) {
            pawn_move = mask << 8;
        } else {
            pawn_move = mask >> 8;
        }

        return pawn_move;
    }

    constexpr _Inline bool is_pawn_mode_admissible(Bitboard pawn_move, const Bitboard &occupied_squares) {
        bool ret = (pawn_move & occupied_squares) == 0;
        return ret;
    }

    constexpr _Inline Bitboard make_move(const Bitboard from, const Bitboard to) {
        const Bitboard ret = from | to;
        return ret;
    }

    class ReadFENException final : public std::exception {
        [[nodiscard]] const char *what() const noexcept override {
            return "Invalid FEN string";
        }
    };


    class Chess_Board {
    public:
        explicit Chess_Board(const std::string_view &fen);

        [[nodiscard]] Bitboard white_king() const { return white_king_p; }
        void set_white_king(const Bitboard &white_king) { white_king_p = white_king; };

        [[nodiscard]] Bitboard white_queens() const { return white_queens_p; }
        void set_white_queens(const Bitboard &white_queens) { white_queens_p = white_queens; };

        [[nodiscard]] Bitboard white_rooks() const { return white_rooks_p; }
        void set_white_rooks(const Bitboard &white_rooks) { white_rooks_p = white_rooks; };

        [[nodiscard]] Bitboard white_knights() const { return white_knights_p; }
        void set_white_knights(const Bitboard &white_knights) { white_knights_p = white_knights; };

        [[nodiscard]] Bitboard white_bishops() const { return white_bishops_p; }
        void set_white_bishops(const Bitboard &white_bishops) { white_bishops_p = white_bishops; };

        [[nodiscard]] Bitboard white_pawns() const { return white_pawns_p; }
        void set_white_pawns(const Bitboard &white_pawns) { white_pawns_p = white_pawns; };


        [[nodiscard]] Bitboard black_king() const { return black_king_p; }
        void set_black_king(const Bitboard &black_king) { black_king_p = black_king; };

        [[nodiscard]] Bitboard black_queens() const { return black_queens_p; }
        void set_black_queens(const Bitboard &black_queens) { black_queens_p = black_queens; };

        [[nodiscard]] Bitboard black_rooks() const { return black_rooks_p; }
        void set_black_rooks(const Bitboard &black_rooks) { black_rooks_p = black_rooks; };

        [[nodiscard]] Bitboard black_knights() const { return black_knights_p; }
        void set_black_knights(const Bitboard &black_knights) { black_knights_p = black_knights; };

        [[nodiscard]] Bitboard black_bishops() const { return black_bishops_p; }
        void set_black_bishops(const Bitboard &black_bishops) { black_bishops_p = black_bishops; };

        [[nodiscard]] Bitboard black_pawns() const { return black_pawns_p; }
        void set_black_pawns(const Bitboard &black_pawns) { black_pawns_p = black_pawns; };


        [[nodiscard]] Bitboard black_pieces() const { return black_pieces_p; }
        void set_black_pieces(const Bitboard &black_pieces) { black_pieces_p = black_pieces; };

        [[nodiscard]] Bitboard white_pieces() const { return white_pieces_p; }
        void set_white_pieces(const Bitboard &white_pieces) { white_pieces_p = white_pieces; };

        [[nodiscard]] Bitboard all_pieces() const { return all_pieces_p; }
        void set_all_pieces(const Bitboard &all_pieces) { all_pieces_p = all_pieces; };


        [[nodiscard]] const Position &en_passant_square() const { return en_passant_square_p; }
        void set_en_passant_square(const Position &en_passant_square) { en_passant_square_p = en_passant_square; };

        [[nodiscard]] std::size_t half_move_number() const { return half_move_number_p; }
        void set_half_move_number(std::size_t half_move_number) { half_move_number_p = half_move_number; };

        [[nodiscard]] std::size_t full_move_number() const { return full_move_number_p; }
        void set_full_move_number(const std::size_t &full_move_number) { full_move_number_p = full_move_number; };

        void set_color_to_move(const Color &color) {
            if (color == Color::white) {
                flags |= 0x1;
            } else {
                flags &= ~0x1;
            }
        };

        [[nodiscard]] Color color_to_move() const {
            return (flags & 0x1) ? Color::white : Color::black;
        }

        void set_en_passant(const bool &en_passant) {
            if (en_passant) {
                flags |= 0x2;
            } else {
                flags &= ~0x2;
            }
        };

        [[nodiscard]] bool en_passant() const {
            return (flags & 0x2) != 0;
        }

        void set_white_queen_castle(const bool &white_queen_castle) {
            if (white_queen_castle) {
                flags |= 0x04;
            } else {
                flags &= ~0x04;
            }
        };

        [[nodiscard]] bool white_queen_castle() const {
            return (flags & 0x04) != 0;
        }

        void set_white_king_castle(const bool &white_king_castle) {
            if (white_king_castle) {
                flags |= 0x08;
            } else {
                flags &= ~0x08;
            }
        };

        [[nodiscard]] bool white_king_castle() const {
            return (flags & 0x08) != 0;
        }

        void set_black_queen_castle(const bool &black_queen_castle) {
            if (black_queen_castle) {
                flags |= 0x10;
            } else {
                flags &= ~0x10;
            }
        };

        [[nodiscard]] bool black_queen_castle() const {
            return (flags & 0x10) != 0;
        }


        void set_black_king_castle(const bool &black_king_castle) {
            if (black_king_castle) {
                flags |= 0x20;
            } else {
                flags &= ~0x20;
            }
        };

        [[nodiscard]] bool black_king_castle() const {
            return (flags & 0x20) != 0;
        }

        void set_check(const bool &check) {
            if (check) {
                flags |= 0x40;
            } else {
                flags &= ~0x40;
            }
        };

        [[nodiscard]] bool check() const {
            return (flags & 0x40) != 0;
        }


        template<Kangaroo::Board_Status status, typename CallBackType>
        constexpr uint64_t generate_pawn_moves([[maybe_unused]] CallBackType callback) {
            using enum Color_t;
            using enum Chess_Pieces;

            const Bitboard pawns = status.color == white ? white_pawns() : black_pawns();

            Bitloop(pawns, [&](Bitboard pawns_remaining) {
                const Bitboard pawn = 1ULL << square_of(pawns_remaining);

                const Bitboard moved_pawn = regular_pawn_move<status.color>(pawn);

                if (is_pawn_mode_admissible(moved_pawn, all_pieces())) {
                    callback(status.color == white ? white_pawn : black_pawn,
                             make_move(pawn, moved_pawn));
                }
            });

            return 0ULL;
        }

        template<Kangaroo::Board_Status status, typename CallBackType>
        constexpr uint64_t generate_moves(CallBackType callback) {
            uint64_t moves = 0ULL;

            moves += generate_pawn_moves<status>(callback);

            return moves;
        }

        template<typename CallBack>
        constexpr void run_move_generation(CallBack callback) {
            switch (flags) {
                case 0x00: generate_moves<Board_Status(0x00)>(callback);
                    break;
                case 0x01: generate_moves<Board_Status(0x01)>(callback);
                    break;
                case 0x02: generate_moves<Board_Status(0x02)>(callback);
                    break;
                case 0x03: generate_moves<Board_Status(0x03)>(callback);
                    break;
                case 0x04: generate_moves<Board_Status(0x04)>(callback);
                    break;
                case 0x05: generate_moves<Board_Status(0x05)>(callback);
                    break;
                case 0x06: generate_moves<Board_Status(0x06)>(callback);
                    break;
                case 0x07: generate_moves<Board_Status(0x07)>(callback);
                    break;
                case 0x08: generate_moves<Board_Status(0x08)>(callback);
                    break;
                case 0x09: generate_moves<Board_Status(0x09)>(callback);
                    break;
                case 0x0a: generate_moves<Board_Status(0x0a)>(callback);
                    break;
                case 0x0b: generate_moves<Board_Status(0x0b)>(callback);
                    break;
                case 0x0c: generate_moves<Board_Status(0x0c)>(callback);
                    break;
                case 0x0d: generate_moves<Board_Status(0x0d)>(callback);
                    break;
                case 0x0e: generate_moves<Board_Status(0x0e)>(callback);
                    break;
                case 0x0f: generate_moves<Board_Status(0x0f)>(callback);
                    break;
                case 0x10: generate_moves<Board_Status(0x10)>(callback);
                    break;
                case 0x11: generate_moves<Board_Status(0x11)>(callback);
                    break;
                case 0x12: generate_moves<Board_Status(0x12)>(callback);
                    break;
                case 0x13: generate_moves<Board_Status(0x13)>(callback);
                    break;
                case 0x14: generate_moves<Board_Status(0x14)>(callback);
                    break;
                case 0x15: generate_moves<Board_Status(0x15)>(callback);
                    break;
                case 0x16: generate_moves<Board_Status(0x16)>(callback);
                    break;
                case 0x17: generate_moves<Board_Status(0x17)>(callback);
                    break;
                case 0x18: generate_moves<Board_Status(0x18)>(callback);
                    break;
                case 0x19: generate_moves<Board_Status(0x19)>(callback);
                    break;
                case 0x1a: generate_moves<Board_Status(0x1a)>(callback);
                    break;
                case 0x1b: generate_moves<Board_Status(0x1b)>(callback);
                    break;
                case 0x1c: generate_moves<Board_Status(0x1c)>(callback);
                    break;
                case 0x1d: generate_moves<Board_Status(0x1d)>(callback);
                    break;
                case 0x1e: generate_moves<Board_Status(0x1e)>(callback);
                    break;
                case 0x1f: generate_moves<Board_Status(0x1f)>(callback);
                    break;
                case 0x20: generate_moves<Board_Status(0x20)>(callback);
                    break;
                case 0x21: generate_moves<Board_Status(0x21)>(callback);
                    break;
                case 0x22: generate_moves<Board_Status(0x22)>(callback);
                    break;
                case 0x23: generate_moves<Board_Status(0x23)>(callback);
                    break;
                case 0x24: generate_moves<Board_Status(0x24)>(callback);
                    break;
                case 0x25: generate_moves<Board_Status(0x25)>(callback);
                    break;
                case 0x26: generate_moves<Board_Status(0x26)>(callback);
                    break;
                case 0x27: generate_moves<Board_Status(0x27)>(callback);
                    break;
                case 0x28: generate_moves<Board_Status(0x28)>(callback);
                    break;
                case 0x29: generate_moves<Board_Status(0x29)>(callback);
                    break;
                case 0x2a: generate_moves<Board_Status(0x2a)>(callback);
                    break;
                case 0x2b: generate_moves<Board_Status(0x2b)>(callback);
                    break;
                case 0x2c: generate_moves<Board_Status(0x2c)>(callback);
                    break;
                case 0x2d: generate_moves<Board_Status(0x2d)>(callback);
                    break;
                case 0x2e: generate_moves<Board_Status(0x2e)>(callback);
                    break;
                case 0x2f: generate_moves<Board_Status(0x2f)>(callback);
                    break;
                case 0x30: generate_moves<Board_Status(0x30)>(callback);
                    break;
                case 0x31: generate_moves<Board_Status(0x31)>(callback);
                    break;
                case 0x32: generate_moves<Board_Status(0x32)>(callback);
                    break;
                case 0x33: generate_moves<Board_Status(0x33)>(callback);
                    break;
                case 0x34: generate_moves<Board_Status(0x34)>(callback);
                    break;
                case 0x35: generate_moves<Board_Status(0x35)>(callback);
                    break;
                case 0x36: generate_moves<Board_Status(0x36)>(callback);
                    break;
                case 0x37: generate_moves<Board_Status(0x37)>(callback);
                    break;
                case 0x38: generate_moves<Board_Status(0x38)>(callback);
                    break;
                case 0x39: generate_moves<Board_Status(0x39)>(callback);
                    break;
                case 0x3a: generate_moves<Board_Status(0x3a)>(callback);
                    break;
                case 0x3b: generate_moves<Board_Status(0x3b)>(callback);
                    break;
                case 0x3c: generate_moves<Board_Status(0x3c)>(callback);
                    break;
                case 0x3d: generate_moves<Board_Status(0x3d)>(callback);
                    break;
                case 0x3e: generate_moves<Board_Status(0x3e)>(callback);
                    break;
                case 0x3f: generate_moves<Board_Status(0x3f)>(callback);
                    break;
                case 0x40: generate_moves<Board_Status(0x40)>(callback);
                    break;
                default: throw std::runtime_error("Invalid board status");
            }
        }

    private:
        uint64_t parce_fen_en_passant_notation(const std::string_view &fen);

        void process_fen_board_setup(const std::string_view &str);

        void parse_fen_player_to_move(const std::string_view &fen);

        void parse_fen_castling_information(const std::string_view &fen);

        void parse_fen_half_move_number(const std::string_view &fen);

        void parse_fen_full_move_number(const std::string_view &fen);

        Bitboard white_king_p = 0ULL;
        Bitboard white_queens_p = 0ULL;
        Bitboard white_rooks_p = 0ULL;
        Bitboard white_knights_p = 0ULL;
        Bitboard white_bishops_p = 0ULL;
        Bitboard white_pawns_p = 0ULL;

        Bitboard black_king_p = 0ULL;
        Bitboard black_queens_p = 0ULL;
        Bitboard black_rooks_p = 0ULL;
        Bitboard black_knights_p = 0ULL;
        Bitboard black_bishops_p = 0ULL;
        Bitboard black_pawns_p = 0ULL;

        Bitboard black_pieces_p = 0ULL;
        Bitboard white_pieces_p = 0ULL;
        Bitboard all_pieces_p = 0ULL;

        Position en_passant_square_p = Position::A1;
        std::size_t half_move_number_p = 0;
        std::size_t full_move_number_p = 0;

        uint64_t flags = 0;
    };


    std::unique_ptr<Chess_Board> create_chess_board_from_fen(const std::string_view &fen);


    std::unique_ptr<Chess_Board> create_chess_board();

    void print_chess_board(const Chess_Board *board);
}
#endif //CHESS_BOARD_H
