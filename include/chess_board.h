//
// Created by peter on 01/12/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <memory>

#include "types.h"
#include "bitboard.h"
#include "Board_Status.h"
#include "colors.h"
#include "constants.h"
#include "../cpm_source_cache/googletest/c89ee04fa01138c2db034b2627b51a145ba09878/googletest/googletest/include/gtest/gtest_prod.h"

inline constexpr std::string_view fen_empty_board = "8/8/8/8/8/8/8/8 w - - 0 1 ";
inline constexpr std::string_view fen_start_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 ";
inline constexpr std::string_view fen_tricky_position_w =
        "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 ";
inline constexpr std::string_view fen_tricky_position_b =
        "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R b KQkq - 0 1 ";

inline constexpr std::string_view fen_killer_position =
        "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
inline constexpr std::string_view fen_cmk_position =
        "r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 b - - 0 9 ";


namespace Kangaroo {
    template<Color color>
    constexpr Bitboard regular_pawn_push(const Bitboard mask) {
        Bitboard pawn_move;

        if constexpr (color == Color::white) {
            pawn_move = mask << 8;
        } else {
            pawn_move = mask >> 8;
        }

        return pawn_move;
    }

    template<Color color>
    constexpr Bitboard double_pawn_push(const Bitboard mask) {
        Bitboard pawn_move;

        if constexpr (color == Color::white) {
            pawn_move = mask << 16;
        } else {
            pawn_move = mask >> 16;
        }

        return pawn_move;
    }

    template<Color color>
    constexpr Bitboard pawn_base_row() {
        if constexpr (color == Color::white) {
            return 0x000000000000FF00ULL;
        } else {
            return 0x00FF000000000000ULL;
        }
    }

    template<Color color>
    [[nodiscard]] constexpr bool is_double_pawn_push_admissible(const Bitboard pawn, const Bitboard pawn_move,
                                                                const Bitboard &occupied_squares) {
        if (pawn & pawn_base_row<color>()) {
            return (pawn_move & occupied_squares) == 0;
        }

        return false;
    }

    [[nodiscard]] constexpr bool is_pawn_push_admissible(Bitboard pawn_move, const Bitboard &occupied_squares) {
        const bool ret = (pawn_move & occupied_squares) == 0;
        return ret;
    }

    [[nodiscard]] constexpr Bitboard make_move(const Bitboard from, const Bitboard to) {
        const Bitboard ret = from | to;
        return ret;
    }

    class ReadFENException final : public std::exception {
        [[nodiscard]] const char *what() const noexcept override {
            return "Invalid FEN string";
        }
    };


    class Chess_Board {
        FRIEND_TEST(Pawn_Move_Generator, pawn_move_generator_black_pawn_capture);
        FRIEND_TEST(Pawn_Move_Generator, pawn_move_generator_white_pawn_capture);
        FRIEND_TEST(Pawn_Move_Generator, pawn_move_generator_black_pawns_base);
        FRIEND_TEST(Pawn_Move_Generator, pawn_move_generator_white_pawns_base);

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
                flags |= 0x1ULL;
            } else {
                flags &= ~0x1ULL;
            }
        };

        [[nodiscard]] Color color_to_move() const {
            return (flags & 0x1ULL) ? Color::white : Color::black;
        }

        void set_en_passant(const bool &en_passant) {
            if (en_passant) {
                flags |= 0x2ULL;
            } else {
                flags &= ~0x2ULL;
            }
        };

        [[nodiscard]] bool en_passant() const {
            return (flags & 0x2ULL) != 0;
        }

        void set_white_queen_castle(const bool &white_queen_castle) {
            if (white_queen_castle) {
                flags |= 0x04ULL;
            } else {
                flags &= ~0x04ULL;
            }
        };

        [[nodiscard]] bool white_queen_castle() const {
            return (flags & 0x04ULL) != 0;
        }

        void set_white_king_castle(const bool &white_king_castle) {
            if (white_king_castle) {
                flags |= 0x08ULL;
            } else {
                flags &= ~0x08ULL;
            }
        };

        [[nodiscard]] bool white_king_castle() const {
            return (flags & 0x08ULL) != 0;
        }

        void set_black_queen_castle(const bool &black_queen_castle) {
            if (black_queen_castle) {
                flags |= 0x10ULL;
            } else {
                flags &= ~0x10ULL;
            }
        };

        [[nodiscard]] bool black_queen_castle() const {
            return (flags & 0x10ULL) != 0;
        }


        void set_black_king_castle(const bool &black_king_castle) {
            if (black_king_castle) {
                flags |= 0x20ULL;
            } else {
                flags &= ~0x20ULL;
            }
        };

        [[nodiscard]] bool black_king_castle() const {
            return (flags & 0x20ULL) != 0;
        }

        void set_check(const bool &check) {
            if (check) {
                flags |= 0x40ULL;
            } else {
                flags &= ~0x40ULL;
            }
        };

        [[nodiscard]] bool check() const {
            return (flags & 0x40ULL) != 0;
        }

        template<Kangaroo::Board_Status status, typename CallBackType>
        constexpr uint64_t generate_pawn_moves(CallBackType callback) const {
            using enum Color_t;
            using enum Chess_Pieces;

            uint64_t moves = 0ULL;

            Bitboard pawns = status.color_p == white ? white_pawns() : black_pawns();

            Bitloop(pawns, pawns_remaining) {
                using enum Color_t;
                using enum Chess_Pieces;

                const std::size_t pawn_square = square_of(pawns_remaining);
                const Bitboard pawn = 1ULL << pawn_square;

                // single move for pawns
                if (const Bitboard moved_pawn = regular_pawn_push<status.color_p>(pawn); is_pawn_push_admissible(
                    moved_pawn, all_pieces())) {
                    callback(status.color_p == white ? white_pawn : black_pawn,
                             make_move(pawn, moved_pawn));
                    ++moves;

                    // double move for pawns in base row
                    if (pawn & pawn_base_row<status.color_p>()) {
                        if (const Bitboard moved_pawn_2 = double_pawn_push<status.color_p>(pawn); is_pawn_push_admissible(
                            moved_pawn_2, all_pieces())) {
                            callback(status.color_p == white ? white_pawn : black_pawn,
                                     make_move(pawn, moved_pawn_2));
                            ++moves;
                        }
                    }
                }

                Bitboard mask = (status.color_p == white
                                     ? Constants::white_pawn_attacks[pawn_square] & black_pieces()
                                     : Constants::black_pawn_attacks[pawn_square] & white_pieces());

                // see if we can capture anything
                Bitloop(mask, pawn_attacks) {
                    Bitboard pawn_attack = 1ULL << square_of(pawn_attacks);
                    callback(status.color_p == white ? white_pawn : black_pawn, make_move(pawn, pawn_attack));
                    ++moves;
                }
            }
            return moves;
        }

        template<Kangaroo::Board_Status status, typename CallBackType>
        constexpr uint64_t generate_moves(CallBackType callback) {
            uint64_t moves = 0ULL;

            moves += generate_pawn_moves<status>(callback);

            return moves;
        }

        template<typename CallBack>
        constexpr uint64_t run_move_generation(CallBack callback) {
            switch (flags) {
                case 0x00: return generate_moves<Board_Status(0x00)>(callback);
                case 0x01: return generate_moves<Board_Status(0x01)>(callback);
                case 0x02: return generate_moves<Board_Status(0x02)>(callback);
                case 0x03: return generate_moves<Board_Status(0x03)>(callback);
                case 0x04: return generate_moves<Board_Status(0x04)>(callback);
                case 0x05: return generate_moves<Board_Status(0x05)>(callback);
                case 0x06: return generate_moves<Board_Status(0x06)>(callback);
                case 0x07: return generate_moves<Board_Status(0x07)>(callback);
                case 0x08: return generate_moves<Board_Status(0x08)>(callback);
                case 0x09: return generate_moves<Board_Status(0x09)>(callback);
                case 0x0a: return generate_moves<Board_Status(0x0a)>(callback);
                case 0x0b: return generate_moves<Board_Status(0x0b)>(callback);
                case 0x0c: return generate_moves<Board_Status(0x0c)>(callback);
                case 0x0d: return generate_moves<Board_Status(0x0d)>(callback);
                case 0x0e: return generate_moves<Board_Status(0x0e)>(callback);
                case 0x0f: return generate_moves<Board_Status(0x0f)>(callback);
                case 0x10: return generate_moves<Board_Status(0x10)>(callback);
                case 0x11: return generate_moves<Board_Status(0x11)>(callback);
                case 0x12: return generate_moves<Board_Status(0x12)>(callback);
                case 0x13: return generate_moves<Board_Status(0x13)>(callback);
                case 0x14: return generate_moves<Board_Status(0x14)>(callback);
                case 0x15: return generate_moves<Board_Status(0x15)>(callback);
                case 0x16: return generate_moves<Board_Status(0x16)>(callback);
                case 0x17: return generate_moves<Board_Status(0x17)>(callback);
                case 0x18: return generate_moves<Board_Status(0x18)>(callback);
                case 0x19: return generate_moves<Board_Status(0x19)>(callback);
                case 0x1a: return generate_moves<Board_Status(0x1a)>(callback);
                case 0x1b: return generate_moves<Board_Status(0x1b)>(callback);
                case 0x1c: return generate_moves<Board_Status(0x1c)>(callback);
                case 0x1d: return generate_moves<Board_Status(0x1d)>(callback);
                case 0x1e: return generate_moves<Board_Status(0x1e)>(callback);
                case 0x1f: return generate_moves<Board_Status(0x1f)>(callback);
                case 0x20: return generate_moves<Board_Status(0x20)>(callback);
                case 0x21: return generate_moves<Board_Status(0x21)>(callback);
                case 0x22: return generate_moves<Board_Status(0x22)>(callback);
                case 0x23: return generate_moves<Board_Status(0x23)>(callback);
                case 0x24: return generate_moves<Board_Status(0x24)>(callback);
                case 0x25: return generate_moves<Board_Status(0x25)>(callback);
                case 0x26: return generate_moves<Board_Status(0x26)>(callback);
                case 0x27: return generate_moves<Board_Status(0x27)>(callback);
                case 0x28: return generate_moves<Board_Status(0x28)>(callback);
                case 0x29: return generate_moves<Board_Status(0x29)>(callback);
                case 0x2a: return generate_moves<Board_Status(0x2a)>(callback);
                case 0x2b: return generate_moves<Board_Status(0x2b)>(callback);
                case 0x2c: return generate_moves<Board_Status(0x2c)>(callback);
                case 0x2d: return generate_moves<Board_Status(0x2d)>(callback);
                case 0x2e: return generate_moves<Board_Status(0x2e)>(callback);
                case 0x2f: return generate_moves<Board_Status(0x2f)>(callback);
                case 0x30: return generate_moves<Board_Status(0x30)>(callback);
                case 0x31: return generate_moves<Board_Status(0x31)>(callback);
                case 0x32: return generate_moves<Board_Status(0x32)>(callback);
                case 0x33: return generate_moves<Board_Status(0x33)>(callback);
                case 0x34: return generate_moves<Board_Status(0x34)>(callback);
                case 0x35: return generate_moves<Board_Status(0x35)>(callback);
                case 0x36: return generate_moves<Board_Status(0x36)>(callback);
                case 0x37: return generate_moves<Board_Status(0x37)>(callback);
                case 0x38: return generate_moves<Board_Status(0x38)>(callback);
                case 0x39: return generate_moves<Board_Status(0x39)>(callback);
                case 0x3a: return generate_moves<Board_Status(0x3a)>(callback);
                case 0x3b: return generate_moves<Board_Status(0x3b)>(callback);
                case 0x3c: return generate_moves<Board_Status(0x3c)>(callback);
                case 0x3d: return generate_moves<Board_Status(0x3d)>(callback);
                case 0x3e: return generate_moves<Board_Status(0x3e)>(callback);
                case 0x3f: return generate_moves<Board_Status(0x3f)>(callback);
                case 0x40: return generate_moves<Board_Status(0x40)>(callback);
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
