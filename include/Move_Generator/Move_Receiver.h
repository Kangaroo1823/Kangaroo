//
// Created by peter on 12/01/2025.
//

#ifndef MOVE_RECEIVER_H
#define MOVE_RECEIVER_H

#include "../Board_Status.h"
#include "../Chess_Board.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, Move_Type move_type, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Move_Receiver {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move([[maybe_unused]] Chess_Board *board,
                                                                     [[maybe_unused]] const Bitboard from,
                                                                     [[maybe_unused]] const Bitboard to) {
            throw std::exception("This version of Move_Receiver::evaluate_and_perform_move() is not implemented yet.");
        }
    };


    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Move_Receiver<status, Move_Type::Promotion, chess_piece, CallbackType, Args...> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board *board,
                                                                     const Bitboard from,
                                                                     const Bitboard to, Args... args) {
            using enum Color;
            using enum Chess_Pieces;
            Bitboard move = to | from;

            // check if the template was called with correct template parameters.
            static_assert(chess_piece != Pawn);
            static_assert(status.color_to_move == White || status.color_to_move == Black);
        //    static_assert(status.en_passant_p == false);


            bitboard_for(*board, status.color_to_move, Pawn) ^= from;
            all_pieces_for(*board, status.color_to_move) ^= move;
            total_pieces_for(*board) ^= move;

            bitboard_for(*board, status.color_to_move, chess_piece) ^= to;
            CallbackType<status, Move_Type::Promotion, chess_piece>::callback(board, move, from, to, args...);
            bitboard_for(*board, status.color_to_move, chess_piece) ^= to;

            total_pieces_for(*board) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            bitboard_for(*board, status.color_to_move, Pawn) ^= from;
        }
    };

    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Move_Receiver<status, Move_Type::Capture_Promotion, chess_piece, CallbackType, Args...> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board *board,
                                                                     const Bitboard from,
                                                                     const Bitboard to, [[maybe_unused]] Args ...args) {
            using enum Color;
            using enum Chess_Pieces;
            Bitboard move = to | from;

            static_assert(
                chess_piece == Rook || chess_piece == Knight ||
                chess_piece == Bishop || chess_piece == Queen);
            static_assert(status.color_to_move == White || status.color_to_move == Black);
            // static_assert(status.en_passant_p == false);


            bitboard_for(*board, status.color_to_move, Pawn) ^= from;
            all_pieces_for(*board, status.color_to_move) ^= move;
            all_pieces_for(*board, enemy(status.color_to_move)) ^= to;
            total_pieces_for(*board) ^= from;

            bitboard_for(*board, status.color_to_move, chess_piece) ^= to;


            for (const auto p: All_Pieces) {
                if (bitboard_for(*board, enemy(status.color_to_move), p) & to) {
                    bitboard_for(*board, enemy(status.color_to_move), p) ^= to;
                    CallbackType<status, Move_Type::Capture_Promotion, chess_piece>::callback(board, move, from, to, args...);
                    bitboard_for(*board, enemy(status.color_to_move), p) ^= to;
                    break;
                }
            }


            bitboard_for(*board, status.color_to_move, chess_piece) ^= to;

            bitboard_for(*board, status.color_to_move, Pawn) ^= from;
            all_pieces_for(*board, status.color_to_move) ^= move;
            all_pieces_for(*board, enemy(status.color_to_move)) ^= to;
            total_pieces_for(*board) ^= from;
        }
    };


    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Move_Receiver<status, Move_Type::Capture, chess_piece, CallbackType, Args...> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board *board,
                                                                     const Bitboard from,
                                                                     const Bitboard to, Args... args) {
            using enum Color;
            using enum Chess_Pieces;
            const Bitboard move = to | from;

            static_assert(status.color_to_move == White || status.color_to_move == Black);
            static_assert(
                chess_piece == Pawn || chess_piece == Rook ||
                chess_piece == Knight || chess_piece == Bishop ||
                chess_piece == Queen || chess_piece == King);
           // static_assert(status.en_passant_p == false);


            bitboard_for(*board, status.color_to_move, chess_piece) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            all_pieces_for(*board, enemy(status.color_to_move)) ^= to;
            total_pieces_for(*board) ^= from;

            for (const auto p: All_Pieces) {
                if (bitboard_for(*board, enemy(status.color_to_move), p) & to) {
                    bitboard_for(*board, enemy(status.color_to_move), p) ^= to;
                    CallbackType<status, Move_Type::Capture, chess_piece>::callback(board, move, from, to, args...);
                    bitboard_for(*board, enemy(status.color_to_move), p) ^= to;
                    break;
                }
            }

            bitboard_for(*board, status.color_to_move, chess_piece) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            all_pieces_for(*board, enemy(status.color_to_move)) ^= to;
            total_pieces_for(*board) ^= from;
        }
    };


    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Move_Receiver<status, Move_Type::Normal, chess_piece, CallbackType, Args...> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board *board,
                                                                     const Bitboard from,
                                                                     const Bitboard to, Args... args) {
            using enum Color;
            using enum Chess_Pieces;
            Bitboard move = to | from;

            static_assert(status.color_to_move == White || status.color_to_move == Black);
//            static_assert(status.en_passant_p == false);


            bitboard_for(*board, status.color_to_move, chess_piece) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            total_pieces_for(*board) ^= move;

            CallbackType<status, Move_Type::Normal, chess_piece>::callback(board, move, from, to, args...);

            bitboard_for(*board, status.color_to_move, chess_piece) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            total_pieces_for(*board) ^= move;
        }
    };


    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType, typename ...Args>
    class Move_Receiver<status, Move_Type::En_Passant, chess_piece, CallbackType, Args...> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board *board,
                                                                     const Bitboard from,
                                                                     const Bitboard to, Args... args) {
            using enum Color;
            using enum Chess_Pieces;
            Bitboard move = to | from;

            static_assert(status.color_to_move == White || status.color_to_move == Black);
            static_assert(chess_piece == Chess_Pieces::Pawn);
            static_assert(status.en_passant_p == true);

            const Bitboard capture = status.color_to_move == White ? to >> 8 : to << 8;

            bitboard_for(*board, status.color_to_move, chess_piece) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            total_pieces_for(*board) ^= move | capture;
            all_pieces_for(*board, enemy(status.color_to_move)) ^= capture;
            bitboard_for(*board, enemy(status.color_to_move), chess_piece) ^= capture;
            const Bitboard en_passant_square = en_passant_square_for(*board);
            en_passant_square_for(*board) = 0ULL;

            CallbackType<status, Move_Type::En_Passant, chess_piece>::callback(board, move, from, to, args...);

            en_passant_square_for(*board) = en_passant_square;
            bitboard_for(*board, status.color_to_move, chess_piece) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            total_pieces_for(*board) ^= move | capture;
            all_pieces_for(*board, enemy(status.color_to_move)) ^= capture;
            bitboard_for(*board, enemy(status.color_to_move), chess_piece) ^= capture;
        }
    };


    /*
        template<Board_Status status, Move_Type move_type, Chess_Pieces chess_piece>
        _ForceInline static constexpr void evaluate_and_perform_move([[maybe_unused]] Chess_Board &board,
                                                                     [[maybe_unused]] const CallbackType &callback,
                                                                     [[maybe_unused]] const Bitboard from,
                                                                     [[maybe_unused]] const Bitboard to) {
            using enum Color;
            using enum Chess_Pieces;

            const Move move = to | from;

            if constexpr (move_type == Move_Type::Promotion) {
                if constexpr (status.en_passant_p) {
                    Bitboard en_passant_square = en_passant_square_for(board);
                    en_passant_square_for(board) = 0ULL;
                    evaluate_and_perform_pawn_promotion<status.copy_and_set_en_passant(false), chess_piece>(
                        board, callback, from, to, move);
                    en_passant_square_for(board) = en_passant_square;
                } else {
                    evaluate_and_perform_pawn_promotion<status, chess_piece>(board, callback, from, to, move);
                }
            } else if constexpr (move_type == Move_Type::Capture_Promotion) {
                if constexpr (status.en_passant_p) {
                    Bitboard en_passant_square = en_passant_square_for(board);
                    en_passant_square_for(board) = 0ULL;
                    evaluate_and_perform_pawn_capture_promotion<status.copy_and_set_en_passant(false), chess_piece>(
                        board, callback, from, to, move);
                    en_passant_square_for(board) = en_passant_square;
                } else {
                    evaluate_and_perform_pawn_capture_promotion<status, chess_piece>(board, callback, from, to, move);
                }
            } else if constexpr (move_type == Move_Type::Capture) {
                if constexpr (status.en_passant_p) {
                    Bitboard en_passant_square = en_passant_square_for(board);
                    en_passant_square_for(board) = 0ULL;
                    evaluate_and_perform_capture<status.copy_and_set_en_passant(false), chess_piece>(
                        board, callback, from, to, move);
                    en_passant_square_for(board) = en_passant_square;
                } else {
                    evaluate_and_perform_capture<status, chess_piece>(board, callback, from, to, move);
                }
            } else if constexpr (move_type == Move_Type::Normal) {
                if constexpr (status.en_passant_p) {
                    Bitboard en_passant_square = en_passant_square_for(board);
                    en_passant_square_for(board) = 0ULL;
                    evaluate_and_perform_normal_move<status.copy_and_set_en_passant(false), chess_piece>(
                        board, callback, move);
                    en_passant_square_for(board) = en_passant_square;
                } else {
                    evaluate_and_perform_normal_move<status, chess_piece>(board, callback, move);
                }
            } else if constexpr (move_type == Move_Type::En_Passant) {
                evaluate_and_perform_en_passant<status, chess_piece>(board, callback, to, move);
            }
        }

        */
};


#endif //MOVE_RECEIVER_H
