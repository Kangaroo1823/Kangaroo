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
        }
    };


    template<Board_Status status, typename Callback>
    class Move_Receiver<status, Move_Type::Capture, Chess_Pieces::pawn, Callback>  {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(const Chess_Board *board,
                                                                     Callback callback,
                                                                     const Bitboard from,
                                                                     const Bitboard to) {
            static_assert(status.color_p == Color::white || status.color_p == Color::black);
            const Bitboard move = from | to;
            Chess_Board new_board = *board;

            if constexpr (status.color_p == Color::white) {
                new_board.set_white_pawns(new_board.white_pawns() ^ move);

                if (new_board.black_pawns() & to) { new_board.set_black_pawns(new_board.black_pawns() ^ to); }
                if (new_board.black_bishops() & to) { new_board.set_black_bishops(new_board.black_bishops() ^ to); }
                if (new_board.black_knights() & to) { new_board.set_black_knights(new_board.black_knights() ^ to); }
                if (new_board.black_rooks() & to) { new_board.set_black_rooks(new_board.black_rooks() ^ to); }
                if (new_board.black_queens() & to) { new_board.set_black_queens(new_board.black_queens() ^ to); }

            } else if constexpr (status.color_p == Color::black) {
                new_board.set_black_pawns(new_board.black_pawns() ^ move);

                if (new_board.white_pawns() & to) { new_board.set_white_pawns(new_board.white_pawns() ^ to); }
                if (new_board.white_bishops() & to) { new_board.set_white_bishops(new_board.white_bishops() ^ to); }
                if (new_board.white_knights() & to) { new_board.set_white_knights(new_board.white_knights() ^ to); }
                if (new_board.white_rooks() & to) { new_board.set_white_rooks(new_board.white_rooks() ^ to); }
                if (new_board.white_queens() & to) { new_board.set_white_queens(new_board.white_queens() ^ to); }
            }

            callback(&new_board, move, status.color_p, Chess_Pieces::pawn);
        }
    };

    template<Board_Status status, typename Callback>
    class Move_Receiver<status, Move_Type::Normal, Chess_Pieces::pawn, Callback> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(const Chess_Board *board,
                                                                     Callback callback,
                                                                     const Bitboard from,
                                                                     const Bitboard to) {
            static_assert(status.color_p == Color::white || status.color_p == Color::black);

            const Bitboard move = from | to;

            Chess_Board new_board = *board;
            if constexpr (status.color_p == Color::white) {
                new_board.set_white_pawns(new_board.white_pawns() ^ move);
            } else if constexpr (status.color_p == Color::black) {
                new_board.set_black_pawns(new_board.black_pawns() ^ move);
            }

            callback(&new_board, move, status.color_p, Chess_Pieces::pawn);
        }
    };
}


#endif //MOVE_RECIEVER_H
