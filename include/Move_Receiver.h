//
// Created by peter on 12/01/2025.
//

#ifndef MOVE_RECEIVER_H
#define MOVE_RECEIVER_H

#include <filesystem>

#include "Board_Status.h"
#include "Chess_Board.h"
#include "Movement_Generator.h"

namespace Kangaroo::Movement_Generator {

    template<Board_Status status>
    [[nodiscard]] constexpr std::size_t generate_moves(const CallbackType &callback);

}

namespace Kangaroo::Move_Receiver {
    template<Board_Status status, Chess_Pieces chess_piece>
    _ForceInline constexpr static bool evaluate_and_perform_pawn_promotion(
        Chess_Board &board, const CallbackType &callback, const Bitboard from, const Bitboard to, const Move move) {
        using enum Color;
        using enum Chess_Pieces;

        static_assert(chess_piece != Pawn);
        static_assert(status.color_to_move == White || status.color_to_move == Black);
        static_assert(status.en_passant_p == false);


        bitboard_for(board, status.color_to_move, Pawn) ^= from;
        all_pieces_for(board, status.color_to_move) ^= move;
        total_pieces_for(board) ^= move;

        bitboard_for(board, status.color_to_move, chess_piece) ^= to;
        const bool ret = callback(board, move, status.color_to_move, chess_piece);
        bitboard_for(board, status.color_to_move, chess_piece) ^= to;

        total_pieces_for(board) ^= move;
        all_pieces_for(board, status.color_to_move) ^= move;
        bitboard_for(board, status.color_to_move, Pawn) ^= from;

        return ret;
    }

    template<Board_Status status, Chess_Pieces chess_piece>

    _ForceInline constexpr static bool evaluate_and_perform_pawn_capture_promotion(
        Chess_Board &board, const CallbackType &callback, const Bitboard from, const Bitboard to, const Move move) {
        using enum Color;
        using enum Chess_Pieces;

        static_assert(
            chess_piece == Chess_Pieces::Rook || chess_piece == Chess_Pieces::Knight ||
            chess_piece == Chess_Pieces::Bishop || chess_piece == Chess_Pieces::Queen);
        static_assert(status.color_to_move == Color::White || status.color_to_move == Color::Black);
        static_assert(status.en_passant_p == false);


        bitboard_for(board, status.color_to_move, Pawn) ^= from;
        all_pieces_for(board, status.color_to_move) ^= move;
        all_pieces_for(board, enemy(status.color_to_move)) ^= to;
        total_pieces_for(board) ^= from;

        bitboard_for(board, status.color_to_move, chess_piece) ^= to;

        bool ret = false;
        for (const auto p: All_Pieces) {
            if (bitboard_for(board, enemy(status.color_to_move), p) & to) {
                bitboard_for(board, enemy(status.color_to_move), p) ^= to;
                ret = callback(board, move, status.color_to_move, chess_piece);
                bitboard_for(board, enemy(status.color_to_move), p) ^= to;
                break;
            }
        }

        bitboard_for(board, status.color_to_move, chess_piece) ^= to;

        bitboard_for(board, status.color_to_move, Pawn) ^= from;
        all_pieces_for(board, status.color_to_move) ^= move;
        all_pieces_for(board, enemy(status.color_to_move)) ^= to;
        total_pieces_for(board) ^= from;

        return ret;
    }

    template<Board_Status status, Chess_Pieces chess_piece>
    _ForceInline constexpr static bool evaluate_and_perform_capture(Chess_Board &board, const CallbackType &callback,
                                                                    const Bitboard from, const Bitboard to,
                                                                    const Move move) {
        static_assert(status.color_to_move == Color::White || status.color_to_move == Color::Black);
        static_assert(
            chess_piece == Chess_Pieces::Pawn || chess_piece == Chess_Pieces::Rook ||
            chess_piece == Chess_Pieces::Knight || chess_piece == Chess_Pieces::Bishop ||
            chess_piece == Chess_Pieces::Queen || chess_piece == Chess_Pieces::King);
        static_assert(status.en_passant_p == false);


        bitboard_for(board, status.color_to_move, chess_piece) ^= move;
        all_pieces_for(board, status.color_to_move) ^= move;
        all_pieces_for(board, enemy(status.color_to_move)) ^= to;
        total_pieces_for(board) ^= from;

        bool ret = false;
        for (const auto p: All_Pieces) {
            if (bitboard_for(board, enemy(status.color_to_move), p) & to) {
                bitboard_for(board, enemy(status.color_to_move), p) ^= to;
                ret = callback(board, move, status.color_to_move, chess_piece);
                bitboard_for(board, enemy(status.color_to_move), p) ^= to;
                break;
            }
        }

        bitboard_for(board, status.color_to_move, chess_piece) ^= move;
        all_pieces_for(board, status.color_to_move) ^= move;
        all_pieces_for(board, enemy(status.color_to_move)) ^= to;
        total_pieces_for(board) ^= from;

        return ret;
    }

    template<Board_Status status, Chess_Pieces chess_piece>
    _ForceInline constexpr static bool evaluate_and_perform_normal_move(
        Chess_Board &board, const CallbackType &callback, const Move move) {

        using enum Color;
        static_assert(status.color_to_move == White || status.color_to_move == Black);
        static_assert(status.en_passant_p == false);


        bitboard_for(board, status.color_to_move, chess_piece) ^= move;
        all_pieces_for(board, status.color_to_move) ^= move;
        total_pieces_for(board) ^= move;

        const bool ret = callback(board, move, status.color_to_move, chess_piece);

        bitboard_for(board, status.color_to_move, chess_piece) ^= move;
        all_pieces_for(board, status.color_to_move) ^= move;
        total_pieces_for(board) ^= move;

        return ret;
    }

    template<Board_Status status, Chess_Pieces chess_piece>
    _ForceInline constexpr static bool evaluate_and_perform_en_passant(Chess_Board &board, const CallbackType &callback,
                                                                       const Bitboard to, const Move move) {
        using enum Color;

        static_assert(status.color_to_move == White || status.color_to_move == Black);
        static_assert(chess_piece == Chess_Pieces::Pawn);
        static_assert(status.en_passant_p == true);

        const Bitboard capture = status.color_to_move == White ? to >> 8 : to << 8;

        bitboard_for(board, status.color_to_move, chess_piece) ^= move;
        all_pieces_for(board, status.color_to_move) ^= move;
        total_pieces_for(board) ^= move | capture;
        all_pieces_for(board, enemy(status.color_to_move)) ^= capture;
        bitboard_for(board, enemy(status.color_to_move), chess_piece) ^= capture;
        Bitboard en_passant_square = en_passant_square_for(board);
        en_passant_square_for(board) = 0ULL;

        const bool ret = callback(board, move, status.color_to_move, chess_piece);

        en_passant_square_for(board) = en_passant_square;
        bitboard_for(board, status.color_to_move, chess_piece) ^= move;
        all_pieces_for(board, status.color_to_move) ^= move;
        total_pieces_for(board) ^= move | capture;
        all_pieces_for(board, enemy(status.color_to_move)) ^= capture;
        bitboard_for(board, enemy(status.color_to_move), chess_piece) ^= capture;

        return ret;
    }

    template<Board_Status status, Move_Type move_type, Chess_Pieces chess_piece>
    _ForceInline static constexpr void evaluate_and_perform_move([[maybe_unused]] Chess_Board &board,
                                                                 [[maybe_unused]] const CallbackType &callback,
                                                                 [[maybe_unused]] const Bitboard from,
                                                                 [[maybe_unused]] const Bitboard to) {
        using enum Color;
        using enum Chess_Pieces;

        const Move move = to | from;

        if constexpr (move_type == Move_Type::Promotion) {
            bool go_deeper = false;
            if constexpr (status.en_passant_p) {
                Bitboard en_passant_square = en_passant_square_for(board);
                en_passant_square_for(board) = 0ULL;
                go_deeper = evaluate_and_perform_pawn_promotion<status.copy_and_set_en_passant(false), chess_piece>(board, callback, from, to, move);
                en_passant_square_for(board) = en_passant_square;
            } else {
                go_deeper = evaluate_and_perform_pawn_promotion<status, chess_piece>(board, callback, from, to, move);
            }
            if (go_deeper) {
                [[maybe_unused]] auto _ = Movement_Generator::generate_moves<status.copy_and_prep_for_next_player()>(callback);
            }
        } else if constexpr (move_type == Move_Type::Capture_Promotion) {
            if constexpr (status.en_passant_p) {
                Bitboard en_passant_square = en_passant_square_for(board);
                en_passant_square_for(board) = 0ULL;
                evaluate_and_perform_pawn_capture_promotion<status.copy_and_set_en_passant(false), chess_piece>(board, callback, from, to, move);
                en_passant_square_for(board) = en_passant_square;
            } else {
                evaluate_and_perform_pawn_capture_promotion<status, chess_piece>(board, callback, from, to, move);
            }
        } else if constexpr (move_type == Move_Type::Capture) {
            if constexpr (status.en_passant_p) {
                Bitboard en_passant_square = en_passant_square_for(board);
                en_passant_square_for(board) = 0ULL;
                evaluate_and_perform_capture<status.copy_and_set_en_passant(false), chess_piece>(board, callback, from, to, move);
                en_passant_square_for(board) = en_passant_square;
            } else {
                evaluate_and_perform_capture<status, chess_piece>(board, callback, from, to, move);
            }
        } else if constexpr (move_type == Move_Type::Normal) {
            if constexpr (status.en_passant_p) {
                Bitboard en_passant_square = en_passant_square_for(board);
                en_passant_square_for(board) = 0ULL;
                evaluate_and_perform_normal_move<status.copy_and_set_en_passant(false), chess_piece>(board, callback, move);
                en_passant_square_for(board) = en_passant_square;
            } else {
                evaluate_and_perform_normal_move<status, chess_piece>(board, callback, move);
            }
        } else if constexpr (move_type == Move_Type::En_Passant) {
            evaluate_and_perform_en_passant<status, chess_piece>(board, callback, to, move);
        }
    }
};


#endif //MOVE_RECIEVER_H
