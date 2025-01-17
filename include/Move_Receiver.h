//
// Created by peter on 12/01/2025.
//

#ifndef MOVE_RECIEVER_H
#define MOVE_RECIEVER_H
#include "Board_Status.h"
#include "chess_board.h"


namespace Kangaroo {
    template<Board_Status status, Move_Type move_type, Chess_Pieces chess_piece, typename Callback>
    class Move_Receiver {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move([[maybe_unused]] const Chess_Board *board,
                                                                     [[maybe_unused]] Callback callback,
                                                                     [[maybe_unused]] const Bitboard from,
                                                                     [[maybe_unused]] const Bitboard to) {

            // dummy implementation. If we end up here, we forgot to implement a specialization.
            callback(board, from | to, status.color_to_move, chess_piece);
        }
    };


    template<Board_Status status, typename Callback>
    class Move_Receiver<status, Move_Type::Capture, Chess_Pieces::Pawn, Callback>  {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(const Chess_Board *board,
                                                                     Callback callback,
                                                                     const Bitboard from,
                                                                     const Bitboard to) {
            using enum Color;

            static_assert(status.color_to_move == White || status.color_to_move == Black);
            const Bitboard move = from | to;
            Chess_Board new_board = *board;

            if constexpr (status.color_to_move == White) {
                new_board.white_pawns = new_board.white_pawns ^ move; // -V1051

                if (new_board.black_pawns & to) { new_board.black_pawns = new_board.black_pawns ^ to; } // -V1051
                if (new_board.black_bishops & to) { new_board.black_bishops = new_board.black_bishops ^ to; }
                if (new_board.black_knights & to) { new_board.black_knights = new_board.black_knights ^ to; }
                if (new_board.black_rooks & to) { new_board.black_rooks = new_board.black_rooks ^ to; }
                if (new_board.black_queens & to) { new_board.black_queens = new_board.black_queens ^ to; }

            } else if constexpr (status.color_to_move == Black) {
                new_board.black_pawns = new_board.black_pawns ^ move; // -V1051

                if (new_board.white_pawns & to) { new_board.white_pawns = new_board.white_pawns ^ to; } // -V1051
                if (new_board.white_bishops & to) { new_board.white_bishops = new_board.white_bishops ^ to; }
                if (new_board.white_knights & to) { new_board.white_knights = new_board.white_knights ^ to; }
                if (new_board.white_rooks & to) { new_board.white_rooks = new_board.white_rooks ^ to; }
                if (new_board.white_queens & to) { new_board.white_queens = new_board.white_queens ^ to; }
            }

            callback(&new_board, move, status.color_to_move, Chess_Pieces::Pawn);
        }
    };

    template<Board_Status status, typename Callback>
    class Move_Receiver<status, Move_Type::Normal, Chess_Pieces::Pawn, Callback> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(const Chess_Board *board,
                                                                     Callback callback,
                                                                     const Bitboard from,
                                                                     const Bitboard to) {
            using enum Color;

            static_assert(status.color_to_move == White || status.color_to_move == Black);

            const Bitboard move = from | to;

            Chess_Board new_board = *board;
            if constexpr (status.color_to_move == White) {
                new_board.white_pawns = new_board.white_pawns ^ move;
            } else if constexpr (status.color_to_move == Black) {
                new_board.black_pawns = new_board.black_pawns ^ move;
            }

            callback(&new_board, move, status.color_to_move, Chess_Pieces::Pawn);
        }
    };
}


#endif //MOVE_RECIEVER_H
