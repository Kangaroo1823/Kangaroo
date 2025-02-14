//
// Created by U439644 on 2/13/2025.
//

#ifndef CALLBACK_HANDLER_H
#define CALLBACK_HANDLER_H
#include "Board_Status.h"



namespace Kangaroo::Move_Generator {

    T/**
      * This class takes care of the callbacks of the move generator.
      *
      * A name of a template class that defines a method named "callback", here CallbackType is given as a type parameter to this class. This method is called
      * during evaluation of the method "handle_callback". The parameters of this method are given (unchanged!) to the method callback of CallbackType.
      */
    template<Board_Status status, Move_Type move_type, Chess_Pieces piece, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Callback_Handler {
        public:
        _ForceInline static constexpr void handle_callback(
            [[maybe_unused]] Chess_Board *board,
            [[maybe_unused]] const Bitboard move,
            [[maybe_unused]] const Bitboard from, [[maybe_unused]] const Bitboard to, Args... args) {
            throw std::exception("This version of Callback_Handler::handle_callback() is not implemented yet.");
        }
    };

    template<Board_Status status, Chess_Pieces piece, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Callback_Handler<status, Move_Type::Normal, piece, CallbackType, Args...> {
        public:
        _ForceInline static constexpr void handle_callback(Chess_Board *board, const Bitboard move, const Bitboard from, const Bitboard to, Args... args) {
            return CallbackType<status, Move_Type::Normal, piece, Args...>::callback(board, move, from, to, args...);
        }
    };

    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Callback_Handler<status, Move_Type::Promotion, Chess_Pieces::Pawn, CallbackType, Args...> {
        public:
        _ForceInline static constexpr void handle_callback(Chess_Board *board, const Bitboard move, const Bitboard from, const Bitboard to, Args... args) {
            CallbackType<status, Move_Type::Promotion, Chess_Pieces::Queen, Args...>::callback(board, move, from, to, args...);
            CallbackType<status, Move_Type::Promotion, Chess_Pieces::Rook, Args...>::callback(board, move, from, to, args...);
            CallbackType<status, Move_Type::Promotion, Chess_Pieces::Bishop, Args...>::callback(board, move, from, to, args...);
            CallbackType<status, Move_Type::Promotion, Chess_Pieces::Knight, Args...>::callback(board, move, from, to, args...);
        }
    };

    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Callback_Handler<status, Move_Type::Capture_Promotion, Chess_Pieces::Pawn, CallbackType, Args...> {
        public:
        _ForceInline static constexpr void handle_callback(Chess_Board *board, const Bitboard move, const Bitboard from, const Bitboard to, Args... args) {
            CallbackType<status, Move_Type::Capture_Promotion, Chess_Pieces::Queen, Args...>::callback(board, move, from, to, args...);
            CallbackType<status, Move_Type::Capture_Promotion, Chess_Pieces::Rook, Args...>::callback(board, move, from, to, args...);
            CallbackType<status, Move_Type::Capture_Promotion, Chess_Pieces::Bishop, Args...>::callback(board, move, from, to, args...);
            CallbackType<status, Move_Type::Capture_Promotion, Chess_Pieces::Knight, Args...>::callback(board, move, from, to, args...);
        }
    };


}

#endif //CALLBACK_HANDLER_H
