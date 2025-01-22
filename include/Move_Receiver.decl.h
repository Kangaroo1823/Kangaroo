//
// Created by U439644 on 1/20/2025.
//

#ifndef MOVE_RECEIVER_DECL_H
#define MOVE_RECEIVER_DECL_H

#include "types.h"
#include "Board_Status.h"

namespace Kangaroo {
    class Chess_Board;

    template<Board_Status status, Move_Type move_type, Chess_Pieces chess_piece>
    class Move_Receiver {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move([[maybe_unused]] Chess_Board &board,
                                                                     [[maybe_unused]] const CallbackType &callback,
                                                                     [[maybe_unused]] const Bitboard from,
                                                                     [[maybe_unused]] const Bitboard to) {
            // dummy implementation. If we end up here, we forgot to implement a specialization.
            callback(board, from | to, status.color_to_move, chess_piece);
        }
    };

    template<Board_Status status, Chess_Pieces chess_piece>
    class Move_Receiver<status, Move_Type::Promotion, chess_piece> {
        _ForceInline static constexpr void helper(Chess_Board &board, Move move, Bitboard from, Bitboard to);

    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board &board,
                                                                     const CallbackType &callback,
                                                                     Bitboard from,
                                                                     Bitboard to);
    };

    template<Board_Status status, Chess_Pieces chess_piece>
    class Move_Receiver<status, Move_Type::Capture_Promotion, chess_piece> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board &board,
                                                                     const CallbackType &callback,
                                                                     Bitboard from,
                                                                     Bitboard to);
    };

    template<Board_Status status>
    class Move_Receiver<status, Move_Type::Capture, Chess_Pieces::Pawn> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board &board,
                                                                     const CallbackType &callback,
                                                                     Bitboard from,
                                                                     Bitboard to);
    };

    template<Board_Status status>
    class Move_Receiver<status, Move_Type::Normal, Chess_Pieces::Pawn> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board &board,
                                                                     const CallbackType &callback,
                                                                     Bitboard from,
                                                                     Bitboard to);
    };
}

#endif //MOVE_RECEIVER_DECL_H
