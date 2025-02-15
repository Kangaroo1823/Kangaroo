//
// Created by U439644 on 2/13/2025.
//

#ifndef CALLBACK_HANDLER_H
#define CALLBACK_HANDLER_H
#include "Board_Status.h"
#include "Move_Receiver.h"


namespace Kangaroo::Move_Generator {
    /**
      * This class takes care of the callbacks of the move generator.
      *
      * A name of a template class that defines a method named "callback", here CallbackType is given as a type parameter to this class. This method is called
      * during evaluation of the method "handle_callback". The parameters of this method are given (unchanged!) to the method callback of CallbackType.
      */
    template<Board_Status status, Move_Type move_type, Chess_Pieces piece, template<Board_Status, Move_Type,
        Chess_Pieces, typename... Args_> class CallbackType, typename... Args>
    class Callback_Handler {
    public:
        _ForceInline static constexpr void handle_callback(
            Chess_Board *board,
            const Bitboard from,
            const Bitboard to,
            Args... args) {
            Move_Receiver<status, move_type, piece, CallbackType, Args...>::evaluate_and_perform_move(board, from, to, args...);
        }
    };


    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class CallbackType,
        typename... Args>
    class Callback_Handler<status, Move_Type::Promotion, Chess_Pieces::Pawn, CallbackType, Args...> {
    public:
        _ForceInline static constexpr void handle_callback(Chess_Board *board, const Bitboard from,
                                                           const Bitboard to, Args... args) {
            Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Queen, CallbackType, Args...>::evaluate_and_perform_move(board, from, to, args...);
            Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Rook, CallbackType, Args...>::evaluate_and_perform_move(board, from, to, args...);
            Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Bishop, CallbackType, Args...>::evaluate_and_perform_move(board, from, to, args...);
            Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Knight, CallbackType, Args...>::evaluate_and_perform_move(board, from, to, args...);
        }
    };

    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class CallbackType,
        typename... Args>
    class Callback_Handler<status, Move_Type::Capture_Promotion, Chess_Pieces::Pawn, CallbackType, Args...> {
    public:
        _ForceInline static constexpr void handle_callback(Chess_Board *board, const Bitboard from,
                                                           const Bitboard to, Args... args) {
            Move_Receiver<status, Move_Type::Capture_Promotion, Chess_Pieces::Queen, CallbackType, Args...>::evaluate_and_perform_move(
                board, from, to, args...);
            Move_Receiver<status, Move_Type::Capture_Promotion, Chess_Pieces::Rook, CallbackType, Args...>::evaluate_and_perform_move(
                board, from, to, args...);
            Move_Receiver<status, Move_Type::Capture_Promotion, Chess_Pieces::Bishop, CallbackType, Args...>::evaluate_and_perform_move(
                board, from, to, args...);
            Move_Receiver<status, Move_Type::Capture_Promotion, Chess_Pieces::Knight, CallbackType, Args...>::evaluate_and_perform_move(
                board, from, to, args...);
        }
    };
}

#endif //CALLBACK_HANDLER_H
