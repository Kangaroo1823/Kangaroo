//
// Created by peter on 12/01/2025.
//

#ifndef MOVE_RECEIVER_H
#define MOVE_RECEIVER_H

#include <bits/fs_fwd.h>

#include "../Board_Status.h"
#include "../Chess_Board.h"
#include "Pin_And_Check_Mask_Generator.h"

/**
*  The Move_Receiver and Move_Receiver_Base classes handle board modification.
*  When a move is generated the board and status needs to be modified accordingly.
*
*
*/

namespace Kangaroo::Move_Generator {
    template<Board_Status status, Move_Type move_type, Chess_Pieces piece, template<Board_Status, Move_Type,
        Chess_Pieces, typename... Args_> class CallbackType, typename... Args>
    class Check_For_Check {
    public:
        _ForceInline static constexpr void check_for_check(Chess_Board *board, const Bitboard move, const Bitboard from,
                                                           const Bitboard to, Args... args) {
            Pin_And_Check_Mask_Generator<enemy(status.color_to_move)> gen(board);
            if (gen.get_check_mask()) {
                CallbackType<status.copy_and_prep_for_next_player().copy_and_set_check(true), move_type,
                    piece>::callback(&gen, move, from, to, args...);
            } else {
                CallbackType<status.copy_and_prep_for_next_player().copy_and_set_check(false), move_type,
                    piece>::callback(&gen, move, from, to, args...);
            }
        }
    };


    template<Board_Status status, Move_Type move_type, Chess_Pieces chess_piece, template<Board_Status, Move_Type,
        Chess_Pieces, typename... Args> class CallbackType, typename... Args>
    class Status_Converter {
    public:
        _ForceInline static constexpr auto handle_en_passant(Chess_Board *board, const Bitboard move,
                                                             const Bitboard from, const Bitboard to, Args... args) {
            if constexpr (status.en_passant_p) {
                const auto en_passant_square = en_passant_square_for(*board);
                en_passant_square_for(*board) = 0ULL;
                Check_For_Check<status.copy_and_set_en_passant(false), move_type, chess_piece, CallbackType, Args
                    ...>::check_for_check(board, move, from, to, args...);
                en_passant_square_for(*board) = en_passant_square;
            } else {
                Check_For_Check<status, move_type, chess_piece, CallbackType, Args...>::check_for_check(
                    board, move, from, to, args...);
            }
        }
    };


    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args> class CallbackType,
        typename... Args>
    class Status_Converter<status, Move_Type::Double_Push, Chess_Pieces::Pawn, CallbackType, Args...> {
    public:
        _ForceInline static constexpr auto handle_en_passant(
            Chess_Board *board,
            const Bitboard move,
            const Bitboard from,
            const Bitboard to,
            Args... args) {
            if constexpr (status.en_passant_p) {
                const auto en_passant_square = en_passant_square_for(*board);
                en_passant_square_for(*board) = regular_pawn_push<status.color_to_move>(from);
                Check_For_Check<status.copy_and_set_en_passant(true), Move_Type::Double_Push, Chess_Pieces::Pawn,
                    CallbackType, Args...>::check_for_check(board, move, from, to, args...);
                en_passant_square_for(*board) = en_passant_square;
            } else {
                Check_For_Check<status, Move_Type::Double_Push, Chess_Pieces::Pawn, CallbackType, Args
                    ...>::check_for_check(board, move, from, to, args...);
            }
        }
    };

    template<Board_Status status, Move_Type move_type, Chess_Pieces chess_piece, template<Board_Status, Move_Type,
        Chess_Pieces, typename... Args_> class CallbackType, typename... Args>
    class Board_Converter {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move([[maybe_unused]] Chess_Board *board,
                                                                     [[maybe_unused]] const Bitboard from,
                                                                     [[maybe_unused]] const Bitboard to,
                                                                     [[maybe_unused]] Args... args) {
            throw std::runtime_error(
                "This version of Move_Receiver::evaluate_and_perform_move() is not implemented yet.");
        }
    };


    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename...
        Args_> class CallbackType, typename... Args>
    class Board_Converter<status, Move_Type::Promotion, chess_piece, CallbackType, Args...> {
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
            Status_Converter<status, Move_Type::Promotion, chess_piece, CallbackType, Args...>::handle_en_passant(
                board, move, from, to, args...);
            bitboard_for(*board, status.color_to_move, chess_piece) ^= to;

            total_pieces_for(*board) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            bitboard_for(*board, status.color_to_move, Pawn) ^= from;
        }
    };

    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename...
        Args_> class CallbackType, typename... Args>
    class Board_Converter<status, Move_Type::Capture_Promotion, chess_piece, CallbackType, Args...> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board *board,
                                                                     const Bitboard from,
                                                                     const Bitboard to, [[maybe_unused]] Args... args) {
            using enum Color;
            using enum Chess_Pieces;
            Bitboard move = to | from;

            static_assert(
                chess_piece == Rook || chess_piece == Knight ||
                chess_piece == Bishop || chess_piece == Queen);
            static_assert(status.color_to_move == White || status.color_to_move == Black);
            static_assert(chess_piece != Pawn);
            // static_assert(status.en_passant_p == false);


            bitboard_for(*board, status.color_to_move, Pawn) ^= from;
            all_pieces_for(*board, status.color_to_move) ^= move;
            all_pieces_for(*board, enemy(status.color_to_move)) ^= to;
            total_pieces_for(*board) ^= from;

            bitboard_for(*board, status.color_to_move, chess_piece) ^= to;


            for (const auto p: All_Pieces) {
                if (bitboard_for(*board, enemy(status.color_to_move), p) & to) {
                    bitboard_for(*board, enemy(status.color_to_move), p) ^= to;
                    Status_Converter<status, Move_Type::Capture_Promotion, chess_piece, CallbackType, Args
                        ...>::handle_en_passant(board, move, from, to, args...);
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


    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename...
        Args_> class CallbackType, typename... Args>
    class Board_Converter<status, Move_Type::Capture, chess_piece, CallbackType, Args...> {
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
                    Status_Converter<status, Move_Type::Capture, chess_piece, CallbackType, Args...>::handle_en_passant(
                        board, move, from, to, args...);
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


    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename...
        Args_> class CallbackType, typename... Args>
    class Board_Converter<status, Move_Type::Normal, chess_piece, CallbackType, Args...> {
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

            Status_Converter<status, Move_Type::Normal, chess_piece, CallbackType, Args...>::handle_en_passant(
                board, move, from, to, args...);

            bitboard_for(*board, status.color_to_move, chess_piece) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            total_pieces_for(*board) ^= move;
        }
    };

    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class CallbackType,
        typename... Args>
    class Board_Converter<status, Move_Type::Double_Push, Chess_Pieces::Pawn, CallbackType, Args...> {
    public:
        _ForceInline static constexpr void evaluate_and_perform_move(Chess_Board *board,
                                                                     const Bitboard from,
                                                                     const Bitboard to,
                                                                     Args... args) {
            using enum Color;
            using enum Chess_Pieces;
            const Bitboard move = to | from;

            static_assert(status.color_to_move == White || status.color_to_move == Black);
            //            static_assert(status.en_passant_p == false);


            bitboard_for(*board, status.color_to_move, Pawn) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            total_pieces_for(*board) ^= move;


            Status_Converter<status, Move_Type::Double_Push, Pawn, CallbackType, Args...>::handle_en_passant(
                board, move, from, to, args...);

            bitboard_for(*board, status.color_to_move, Pawn) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            total_pieces_for(*board) ^= move;
        }
    };


    template<Board_Status status, Chess_Pieces chess_piece, template<Board_Status, Move_Type, Chess_Pieces, typename...
        Args_> class CallbackType, typename... Args>
    class Board_Converter<status, Move_Type::En_Passant, chess_piece, CallbackType, Args...> {
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

            Status_Converter<status, Move_Type::En_Passant, chess_piece, CallbackType, Args...>::handle_en_passant(
                board, move, from, to, args...);

            bitboard_for(*board, status.color_to_move, chess_piece) ^= move;
            all_pieces_for(*board, status.color_to_move) ^= move;
            total_pieces_for(*board) ^= move | capture;
            all_pieces_for(*board, enemy(status.color_to_move)) ^= capture;
            bitboard_for(*board, enemy(status.color_to_move), chess_piece) ^= capture;
        }
    };
};


#endif //MOVE_RECEIVER_H
