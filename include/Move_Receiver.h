//
// Created by peter on 12/01/2025.
//

#ifndef MOVE_RECEIVER_H
#define MOVE_RECEIVER_H

#include "Board_Status.h"
#include "Chess_Board.h"


namespace Kangaroo::Move_Receiver {
    template<Board_Status status, Chess_Pieces chess_piece>
    _ForceInline constexpr static void evaluate_and_perform_pawn_promotion(
        Chess_Board &board, const CallbackType &callback, const Bitboard from, const Bitboard to, const Move move) {
        using enum Color;
        using enum Chess_Pieces;

        static_assert(chess_piece != Pawn);
        static_assert(status.color_to_move == White || status.color_to_move == Black);


        bitboard_for(board, status.color_to_move, Pawn) ^= from;
        all_pieces_for(board, status.color_to_move) ^= move;
        total_pieces_for(board) ^= move;

        bitboard_for(board, status.color_to_move, chess_piece) ^= to;
        callback(board, move, status.color_to_move, chess_piece);
        bitboard_for(board, status.color_to_move, chess_piece) ^= to;

        total_pieces_for(board) ^= move;
        all_pieces_for(board, status.color_to_move) ^= move;
        bitboard_for(board, status.color_to_move, Pawn) ^= from;
    }

    template<Board_Status status, Chess_Pieces chess_piece>

    _ForceInline constexpr static void evaluate_and_perform_pawn_capture_promotion(
        Chess_Board &board, const CallbackType &callback, const Bitboard from, const Bitboard to, const Move move) {
        using enum Color;
        using enum Chess_Pieces;

        static_assert(
            chess_piece == Chess_Pieces::Rook || chess_piece == Chess_Pieces::Knight ||
            chess_piece == Chess_Pieces::Bishop || chess_piece == Chess_Pieces::Queen);
        static_assert(status.color_to_move == Color::White || status.color_to_move == Color::Black);


        bitboard_for(board, status.color_to_move, Pawn) ^= from;
        all_pieces_for(board, status.color_to_move) ^= move;
        all_pieces_for(board, enemy(status.color_to_move)) ^= to;
        total_pieces_for(board) ^= from;

        bitboard_for(board, status.color_to_move, chess_piece) ^= to;

        for (const auto p: All_Pieces) {
            if (bitboard_for(board, enemy(status.color_to_move), p) & to) {
                bitboard_for(board, enemy(status.color_to_move), p) ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                bitboard_for(board, enemy(status.color_to_move), p) ^= to;
                break;
            }
        }

        bitboard_for(board, status.color_to_move, chess_piece) ^= to;

        bitboard_for(board, status.color_to_move, Pawn) ^= from;
        all_pieces_for(board, status.color_to_move) ^= move;
        all_pieces_for(board, enemy(status.color_to_move)) ^= to;
        total_pieces_for(board) ^= from;
    }

    template<Board_Status status, Chess_Pieces chess_piece>
    _ForceInline constexpr static void evaluate_and_perform_capture(Chess_Board &board, const CallbackType &callback,
                                                                    const Bitboard from, const Bitboard to,
                                                                    const Move move) {
        static_assert(status.color_to_move == Color::White || status.color_to_move == Color::Black);
        static_assert(
            chess_piece == Chess_Pieces::Pawn || chess_piece == Chess_Pieces::Rook ||
            chess_piece == Chess_Pieces::Knight || chess_piece == Chess_Pieces::Bishop ||
            chess_piece == Chess_Pieces::Queen || chess_piece == Chess_Pieces::King);

        if constexpr (status.color_to_move == Color::White) {
            if constexpr (chess_piece == Chess_Pieces::Pawn) {
                board.white_pawns ^= move; // -V1051
            } else if constexpr (chess_piece == Chess_Pieces::Rook) {
                board.white_rooks ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Knight) {
                board.white_knights ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Bishop) {
                board.white_bishops ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Queen) {
                board.white_queens ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::King) {
                board.white_king ^= move;
            }

            board.white_pieces ^= move;
            board.black_pieces ^= to;
            board.all_pieces ^= from;

            if (board.black_pawns & to) {
                board.black_pawns ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.black_pawns ^= to;
            }
            if (board.black_bishops & to) {
                board.black_bishops ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.black_bishops ^= to;
            }
            if (board.black_knights & to) {
                board.black_knights ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.black_knights ^= to;
            }
            if (board.black_rooks & to) {
                board.black_rooks ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.black_rooks ^= to;
            }
            if (board.black_queens & to) {
                board.black_queens ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.black_queens ^= to;
            }

            if constexpr (chess_piece == Chess_Pieces::Pawn) {
                board.white_pawns ^= move; // -V1051
            } else if constexpr (chess_piece == Chess_Pieces::Rook) {
                board.white_rooks ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Knight) {
                board.white_knights ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Bishop) {
                board.white_bishops ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Queen) {
                board.white_queens ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::King) {
                board.white_king ^= move;
            }

            board.white_pieces ^= move;
            board.black_pieces ^= to;
            board.all_pieces ^= from;
        } else if constexpr (status.color_to_move == Color::Black) {
            if constexpr (chess_piece == Chess_Pieces::Pawn) {
                board.black_pawns ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Rook) {
                board.black_rooks ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Knight) {
                board.black_knights ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Bishop) {
                board.black_bishops ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Queen) {
                board.black_queens ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::King) {
                board.black_king ^= move;
            }

            board.black_pieces ^= move;
            board.white_pieces ^= to;
            board.all_pieces ^= from;

            if (board.white_pawns & to) {
                board.white_pawns ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.white_pawns ^= to;
            }
            if (board.white_bishops & to) {
                board.white_bishops ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.white_bishops ^= to;
            }
            if (board.white_knights & to) {
                board.white_knights ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.white_knights ^= to;
            }
            if (board.white_rooks & to) {
                board.white_rooks ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.white_rooks ^= to;
            }
            if (board.white_queens & to) {
                board.white_queens ^= to;
                callback(board, move, status.color_to_move, chess_piece);
                board.white_queens ^= to;
            }

            if constexpr (chess_piece == Chess_Pieces::Pawn) {
                board.black_pawns ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Rook) {
                board.black_rooks ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Knight) {
                board.black_knights ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Bishop) {
                board.black_bishops ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::Queen) {
                board.black_queens ^= move;
            } else if constexpr (chess_piece == Chess_Pieces::King) {
                board.black_king ^= move;
            }

            board.black_pieces ^= move;
            board.white_pieces ^= to;
            board.all_pieces ^= from;
        }
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
            evaluate_and_perform_pawn_promotion<status, chess_piece>(board, callback, from, to, move);
        } else if constexpr (move_type == Move_Type::Capture_Promotion) {
            evaluate_and_perform_pawn_capture_promotion<status, chess_piece>(board, callback, from, to, move);
        } else if constexpr (move_type == Move_Type::Capture) {
            evaluate_and_perform_capture<status, chess_piece>(board, callback, from, to, move);
        }
    }
};


template<Board_Status status>
class Move_Receiver<status, Move_Type::Normal, Chess_Pieces::Pawn> {
public:
    _ForceInline static constexpr void evaluate_and_perform_move(const Chess_Board &board,
                                                                 const CallbackType &callback,
                                                                 const Bitboard from,
                                                                 const Bitboard to) {
        using enum Color;

        static_assert(status.color_to_move == White || status.color_to_move == Black);

        const Bitboard move = from | to;

        Chess_Board new_board = board;
        if constexpr (status.color_to_move == White) {
            new_board.white_pawns ^= move;
            new_board.white_pieces ^= move;
            new_board.all_pieces ^= move;
        } else if constexpr (status.color_to_move == Black) {
            new_board.black_pawns ^= move;
            new_board.black_pieces ^= move;
            new_board.all_pieces ^= move;
        }

        callback(new_board, move, status.color_to_move, Chess_Pieces::Pawn);
    }
};

}


#endif //MOVE_RECIEVER_H
