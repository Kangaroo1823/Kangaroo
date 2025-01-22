//
// Created by peter on 01/12/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <memory>

#include "Base.h"
#include "Types.h"
#include "Bit_Board.h"
#include "Board_Status.h"
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

#define bitboard_for(obj, color, piece) (obj).chess_board[static_cast<std::size_t>(piece) + All_Pieces.size() * static_cast<std::size_t>(color)]
#define all_pieces_for(obj, color) (obj).chess_board[2*All_Pieces.size() + static_cast<std::size_t>(color)]
#define total_pieces_for(obj) (obj).chess_board[14]
#define en_passant_square_for(obj) (obj).chess_board[15]

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
        [[nodiscard]] constexpr bool is_state_consistent() const {
            using enum Chess_Pieces;
            using enum Color;

            auto b1 = (bitboard_for((*this), White, Pawn) | bitboard_for(*this, White, Knight) |
                       bitboard_for(*this, White, Bishop) | bitboard_for(*this, White, Rook) |
                       bitboard_for(*this, White, Queen) | bitboard_for(*this, White, King)) ==
                      all_pieces_for(*this, White);
            auto b2 = (bitboard_for(*this, Black, Pawn) | bitboard_for(*this, Black, Knight) |
                       bitboard_for(*this, Black, Bishop) | bitboard_for(*this, Black, Rook) |
                       bitboard_for(*this, Black, Queen) | bitboard_for(*this, Black, King)) ==
                      all_pieces_for(*this, Black);
            auto b3 = (all_pieces_for(*this, White) | all_pieces_for(*this, Black)) == total_pieces_for(*this);

            return b1 && b2 && b3;
        }


        explicit Chess_Board(std::string_view fen = "8/8/8/8/8/8/8/8 w - - 0 1");

        explicit constexpr Chess_Board(const std::array<Bitboard, 15> &data) {
            for (auto it = chess_board.begin(); const auto &d: data) {
                *it = d;
                ++it;
            }
            chess_board[15] = 0ULL;
            half_move_number = static_cast<std::size_t>(data[13]);
            full_move_number = static_cast<std::size_t>(data[14]);

            update_collectors();
        }

        _ForceInline constexpr void update_collectors() {
            using enum Color;

            for (const auto c: All_Colors) {
                Bitboard b = 0ULL;
                for (const auto p: All_Pieces) {
                    b |= bitboard_for(*this, c, p);
                }
                all_pieces_for(*this, c) = b;
            }

            total_pieces_for(*this) = all_pieces_for(*this, White) | all_pieces_for(*this, Black);
        }

        Chess_Board(const Chess_Board &) = default;

        [[nodiscard]] std::unique_ptr<Board_Status> reset_board(std::string_view fen);

        bool operator==(const Chess_Board &b) const {
            return b.chess_board == chess_board &&
                   b.half_move_number == half_move_number &&
                   b.full_move_number == full_move_number;
        }

        bool operator!=(const Chess_Board &b) const {
            return !(*this == b);
        };


        std::array<Bitboard, 16> chess_board = {
            0ULL, 0ULL, 0ULL, 0ULL,
            0ULL, 0ULL, 0ULL, 0ULL,
            0ULL, 0ULL, 0ULL, 0ULL,
            0ULL, 0ULL, 0ULL, 0ULL
        };

        /*        Bitboard white_king = 0ULL;
                Bitboard white_queens = 0ULL;
                Bitboard white_rooks = 0ULL;
                Bitboard white_knights = 0ULL;
                Bitboard white_bishops = 0ULL;
                Bitboard white_pawns = 0ULL;

                Bitboard black_king = 0ULL;
                Bitboard black_queens = 0ULL;
                Bitboard black_rooks = 0ULL;
                Bitboard black_knights = 0ULL;
                Bitboard black_bishops = 0ULL;
                Bitboard black_pawns = 0ULL;

                Bitboard black_pieces = 0ULL;
                Bitboard white_pieces = 0ULL;
                Bitboard all_pieces = 0ULL;

                Bitboard en_passant_square = 0ULL; */

        std::size_t half_move_number = 0;
        std::size_t full_move_number = 0;

    private:
        void process_fen_board_setup(std::string_view str);

        static std::unique_ptr<Board_Status> parse_fen_player_to_move(std::unique_ptr<Board_Status> &&status,
                                                                      std::string_view str);

        static std::unique_ptr<Board_Status> parse_fen_castling_information(std::unique_ptr<Board_Status> &&status,
                                                                            std::string_view fen);

        std::unique_ptr<Board_Status> parce_fen_en_passant_notation(std::unique_ptr<Board_Status> &&status,
                                                                    std::string_view str);

        void parse_fen_half_move_number(std::string_view fen);

        void parse_fen_full_move_number(std::string_view fen);
    };

    std::ostream &operator<<(std::ostream &os, const Chess_Board &board);

    [[nodiscard]] std::string format_chess_board(const Chess_Board &board, bool output_data,
                                                 const std::optional<Board_Status> &status = std::nullopt);

    void print_chess_board(const Chess_Board &board, bool output_data = false);
}

#endif //CHESS_BOARD_H
