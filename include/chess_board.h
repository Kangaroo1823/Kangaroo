//
// Created by peter on 01/12/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <memory>

#include "base.h"
#include "types.h"
#include "bitboard.h"
#include "Board_Status.h"
#include "colors.h"
#include "constants.h"
#include "gtest/gtest.h"

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

        if constexpr (color == Color::White) {
            pawn_move = mask << 8;
        } else {
            pawn_move = mask >> 8;
        }

        return pawn_move;
    }

    template<Color color>
    constexpr Bitboard double_pawn_push(const Bitboard mask) {
        Bitboard pawn_move;

        if constexpr (color == Color::White) {
            pawn_move = mask << 16;
        } else {
            pawn_move = mask >> 16;
        }

        return pawn_move;
    }

    template<Color color>
    constexpr Bitboard pawn_base_row() {
        if constexpr (color == Color::White) {
            return 0x000000000000FF00ULL;
        } else {
            return 0x00FF000000000000ULL;
        }
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
        explicit Chess_Board(std::string_view fen);

        void reset_board(std::string_view fen);

        [[nodiscard]] _ForceInline Bitboard white_king() const { return white_king_p; }
        _ForceInline void set_white_king(const Bitboard white_king) { white_king_p = white_king; };

        [[nodiscard]] _ForceInline Bitboard white_queens() const { return white_queens_p; }
        _ForceInline void set_white_queens(const Bitboard white_queens) { white_queens_p = white_queens; };

        [[nodiscard]] _ForceInline Bitboard white_rooks() const { return white_rooks_p; }
        _ForceInline void set_white_rooks(const Bitboard white_rooks) { white_rooks_p = white_rooks; };

        [[nodiscard]] _ForceInline Bitboard white_knights() const { return white_knights_p; }
        _ForceInline void set_white_knights(const Bitboard white_knights) { white_knights_p = white_knights; };

        [[nodiscard]] _ForceInline Bitboard white_bishops() const { return white_bishops_p; }
        _ForceInline void set_white_bishops(const Bitboard white_bishops) { white_bishops_p = white_bishops; };

        [[nodiscard]] _ForceInline Bitboard white_pawns() const { return white_pawns_p; }
        _ForceInline void set_white_pawns(const Bitboard white_pawns) { white_pawns_p = white_pawns; };


        [[nodiscard]] _ForceInline Bitboard black_king() const { return black_king_p; }
        _ForceInline void set_black_king(const Bitboard black_king) { black_king_p = black_king; };

        [[nodiscard]] _ForceInline Bitboard black_queens() const { return black_queens_p; }
        _ForceInline void set_black_queens(const Bitboard black_queens) { black_queens_p = black_queens; };

        [[nodiscard]] _ForceInline Bitboard black_rooks() const { return black_rooks_p; }
        _ForceInline void set_black_rooks(const Bitboard black_rooks) { black_rooks_p = black_rooks; };

        [[nodiscard]] _ForceInline Bitboard black_knights() const { return black_knights_p; }
        _ForceInline void set_black_knights(const Bitboard black_knights) { black_knights_p = black_knights; };

        [[nodiscard]] _ForceInline Bitboard black_bishops() const { return black_bishops_p; }
        _ForceInline void set_black_bishops(const Bitboard black_bishops) { black_bishops_p = black_bishops; };

        [[nodiscard]] _ForceInline Bitboard black_pawns() const { return black_pawns_p; }
        _ForceInline void set_black_pawns(const Bitboard black_pawns) { black_pawns_p = black_pawns; };


        [[nodiscard]] _ForceInline Bitboard black_pieces() const { return black_pieces_p; }
        _ForceInline void set_black_pieces(const Bitboard black_pieces) { black_pieces_p = black_pieces; };

        [[nodiscard]] _ForceInline Bitboard white_pieces() const { return white_pieces_p; }
        _ForceInline void set_white_pieces(const Bitboard white_pieces) { white_pieces_p = white_pieces; };

        [[nodiscard]] _ForceInline Bitboard all_pieces() const { return all_pieces_p; }
        _ForceInline void set_all_pieces(const Bitboard all_pieces) { all_pieces_p = all_pieces; };


        [[nodiscard]] _ForceInline const Bitboard &en_passant_square() const { return en_passant_square_p; }
        _ForceInline void set_en_passant_square(const Bitboard en_passant_square) {
            en_passant_square_p = en_passant_square;
        };

        [[nodiscard]] _ForceInline std::size_t half_move_number() const { return half_move_number_p; }
        _ForceInline void set_half_move_number(const std::size_t half_move_number) { half_move_number_p = half_move_number; };

        [[nodiscard]] _ForceInline std::size_t full_move_number() const { return full_move_number_p; }
        _ForceInline void set_full_move_number(const std::size_t full_move_number) {
            full_move_number_p = full_move_number;
        };

        _ForceInline void set_color_to_move(const Color color) {
            if (color == Color::White) {
                flags |= 0x1ULL;
            } else {
                flags &= ~0x1ULL;
            }
        };

        [[nodiscard]] _ForceInline Color color_to_move() const {
            return (flags & 0x1ULL) ? Color::White : Color::Black;
        }

        _ForceInline void set_en_passant(const bool en_passant) {
            if (en_passant) {
                flags |= 0x2ULL;
            } else {
                flags &= ~0x2ULL;
            }
        };

        [[nodiscard]] _ForceInline bool en_passant() const {
            return (flags & 0x2ULL) != 0;
        }

        _ForceInline void set_white_queen_castle(const bool white_queen_castle) {
            if (white_queen_castle) {

                // set the 4th bit of flags
                flags |= 0x04ULL; // -V112

            } else {

                // unset the 4th bit of flags
                flags &= ~0x04ULL; // -V112

            }
        };

        [[nodiscard]] _ForceInline bool white_queen_castle() const {
            return (flags & 0x04ULL) != 0;
        }

        _ForceInline void set_white_king_castle(const bool white_king_castle) {
            if (white_king_castle) {
                flags |= 0x08ULL;
            } else {
                flags &= ~0x08ULL;
            }
        };

        [[nodiscard]] _ForceInline bool white_king_castle() const {
            return (flags & 0x08ULL) != 0;
        }

        _ForceInline void set_black_queen_castle(const bool black_queen_castle) {
            if (black_queen_castle) {
                flags |= 0x10ULL;
            } else {
                flags &= ~0x10ULL;
            }
        };

        [[nodiscard]] _ForceInline bool black_queen_castle() const {
            return (flags & 0x10ULL) != 0;
        }


        _ForceInline void set_black_king_castle(const bool black_king_castle) {
            if (black_king_castle) {
                flags |= 0x20ULL; // -V112
            } else {
                flags &= ~0x20ULL; // -V112
            }
        };

        [[nodiscard]] _ForceInline bool black_king_castle() const {
            return (flags & 0x20ULL) != 0;
        }

        _ForceInline void set_check(const bool check) {
            if (check) {
                flags |= 0x40ULL;
            } else {
                flags &= ~0x40ULL;
            }
        };

        [[nodiscard]] _ForceInline bool check() const {
            return (flags & 0x40ULL) != 0;
        }

        [[nodiscard]] _ForceInline uint64_t get_flags() const { return flags; }

    private:
        uint64_t parce_fen_en_passant_notation(std::string_view str);

        void process_fen_board_setup(std::string_view str);

        void parse_fen_player_to_move(std::string_view str);

        void parse_fen_castling_information(std::string_view fen);

        void parse_fen_half_move_number(std::string_view fen);

        void parse_fen_full_move_number(std::string_view fen);


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

        Bitboard en_passant_square_p = 0ULL;
        std::size_t half_move_number_p = 0;
        std::size_t full_move_number_p = 0;


        uint64_t flags = 0;
    };


    std::unique_ptr<Chess_Board> create_chess_board_from_fen(const std::string_view &fen);


    std::unique_ptr<Chess_Board> create_chess_board();

    void print_chess_board(const Chess_Board *board);


}

#endif //CHESS_BOARD_H
