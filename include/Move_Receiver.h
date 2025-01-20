//
// Created by peter on 12/01/2025.
//

#ifndef MOVE_RECEIVER_H
#define MOVE_RECEIVER_H

#include "Move_Receiver.decl.h"
#include "Board_Status.h"
#include "chess_board.h"


namespace Kangaroo {
    template<Board_Status status, Chess_Pieces chess_piece>
    _ForceInline constexpr void Move_Receiver<status, Move_Type::Promotion, chess_piece>::helper(
        Chess_Board &board, const Move move, const Bitboard from,
        const Bitboard to) {
        using enum Color;
        using enum Chess_Pieces;

        if constexpr (status.color_to_move == White) {
            board.white_pawns ^= from;
            board.white_pieces ^= move;
            board.all_pieces ^= move;

            if constexpr (chess_piece == Rook) {
                board.white_rooks ^= to;
            } else if constexpr (chess_piece == Knight) {
                board.white_knights ^= to;
            } else if constexpr (chess_piece == Bishop) {
                board.white_bishops ^= to;
            } else if constexpr (chess_piece == Queen) {
                board.white_queens ^= to;
            }
        } else if constexpr (status.color_to_move == Black) {
            board.black_pawns ^= from;
            board.black_pieces ^= move;
            board.all_pieces ^= move;

            if constexpr (chess_piece == Rook) {
                board.black_rooks ^= to;
            } else if constexpr (chess_piece == Knight) {
                board.black_knights ^= to;
            } else if constexpr (chess_piece == Bishop) {
                board.black_bishops ^= to;
            } else if constexpr (chess_piece == Queen) {
                board.black_queens ^= to;
            }
        }
    }

    template<Board_Status status, Chess_Pieces chess_piece>
    _ForceInline constexpr void Move_Receiver<status, Move_Type::Promotion, chess_piece>::evaluate_and_perform_move(
        Chess_Board &board,
        const CallbackType &callback,
        const Bitboard from,
        const Bitboard to) {
        const Move move = to | from;

        helper(board, move, from, to);
        callback(board, move, status.color_to_move, chess_piece);
        helper(board, move, from, to);
    }

    template<Board_Status status, Chess_Pieces chess_piece>
    _ForceInline constexpr void Move_Receiver<status, Move_Type::Capture_Promotion,
        chess_piece>::evaluate_and_perform_move(Chess_Board &board,
                                                const CallbackType &callback,
                                                const Bitboard from,
                                                const Bitboard to) {
        using enum Color;
        using enum Chess_Pieces;

        const Move move = to | from;

        if constexpr (status.color_to_move == White) {
            board.white_pawns ^= from;
            board.white_pieces ^= move;
            board.black_pieces ^= to;
            board.all_pieces ^= from;

            if constexpr (chess_piece == Rook) {
                board.white_rooks ^= to;
            } else if constexpr (chess_piece == Knight) {
                board.white_knights ^= to;
            } else if constexpr (chess_piece == Bishop) {
                board.white_bishops ^= to;
            } else if constexpr (chess_piece == Queen) {
                board.white_queens ^= to;
            }

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


            board.white_pawns ^= from;
            board.white_pieces ^= move;
            board.black_pieces ^= to;
            board.all_pieces ^= from;

            if constexpr (chess_piece == Rook) {
                board.white_rooks ^= to;
            } else if constexpr (chess_piece == Knight) {
                board.white_knights ^= to;
            } else if constexpr (chess_piece == Bishop) {
                board.white_bishops ^= to;
            } else if constexpr (chess_piece == Queen) {
                board.white_queens ^= to;
            }
        } else if constexpr (status.color_to_move == Black) {
            board.black_pawns ^= from;
            board.black_pieces ^= move;
            board.white_pieces ^= to;
            board.all_pieces ^= from;

            if constexpr (chess_piece == Rook) {
                board.black_rooks ^= to;
            } else if constexpr (chess_piece == Knight) {
                board.black_knights ^= to;
            } else if constexpr (chess_piece == Bishop) {
                board.black_bishops ^= to;
            } else if constexpr (chess_piece == Queen) {
                board.black_queens ^= to;
            }

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

            board.black_pawns ^= from;
            board.black_pieces ^= move;
            board.white_pieces ^= to;
            board.all_pieces ^= from;

            if constexpr (chess_piece == Rook) {
                board.black_rooks ^= to;
            } else if constexpr (chess_piece == Knight) {
                board.black_knights ^= to;
            } else if constexpr (chess_piece == Bishop) {
                board.black_bishops ^= to;
            } else if constexpr (chess_piece == Queen) {
                board.black_queens ^= to;
            }
        }
    }

    template<Board_Status status>
    _ForceInline constexpr void Move_Receiver<status, Move_Type::Capture,
        Chess_Pieces::Pawn>::evaluate_and_perform_move(Chess_Board &board,
                                                       const CallbackType &callback,
                                                       const Bitboard from,
                                                       const Bitboard to) {
        using enum Color;

        static_assert(status.color_to_move == White || status.color_to_move == Black);
        const Bitboard move = from | to;


        if constexpr (status.color_to_move == White) {
            board.white_pawns ^= move; // -V1051
            board.white_pieces ^= move;
            board.black_pieces ^= to;
            board.all_pieces ^= from;

            if (board.black_pawns & to) {
                board.black_pawns ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.black_pawns ^= to;
            }
            if (board.black_bishops & to) {
                board.black_bishops ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.black_bishops ^= to;
            }
            if (board.black_knights & to) {
                board.black_knights ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.black_knights ^= to;
            }
            if (board.black_rooks & to) {
                board.black_rooks ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.black_rooks ^= to;
            }
            if (board.black_queens & to) {
                board.black_queens ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.black_queens ^= to;
            }

            board.white_pawns ^= move; // -V1051
            board.white_pieces ^= move;
            board.black_pieces ^= to;
            board.all_pieces ^= from;
        } else if constexpr (status.color_to_move == Black) {
            board.black_pawns ^= move;
            board.black_pieces ^= move;
            board.white_pieces ^= to;
            board.all_pieces ^= from;

            if (board.white_pawns & to) {
                board.white_pawns ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.white_pawns ^= to;
            }
            if (board.white_bishops & to) {
                board.white_bishops ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.white_bishops ^= to;
            }
            if (board.white_knights & to) {
                board.white_knights ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.white_knights ^= to;
            }
            if (board.white_rooks & to) {
                board.white_rooks ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.white_rooks ^= to;
            }
            if (board.white_queens & to) {
                board.white_queens ^= to;
                callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
                board.white_queens ^= to;
            }

            board.white_pawns ^= move; // -V1051
            board.white_pieces ^= move;
            board.black_pieces ^= to;
            board.all_pieces ^= from;
        }
    }

    template<Board_Status status>
    _ForceInline constexpr void Move_Receiver<status, Move_Type::Normal, Chess_Pieces::Pawn>::evaluate_and_perform_move(
        Chess_Board &board,
        const CallbackType &callback,
        const Bitboard from,
        const Bitboard to) {
        using enum Color;

        static_assert(status.color_to_move == White || status.color_to_move == Black);

        const Bitboard move = from | to;

        if constexpr (status.color_to_move == White) {
            board.white_pawns ^= move;
            board.white_pieces ^= move;
            board.all_pieces ^= move;
            callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
            board.white_pawns ^= move;
            board.white_pieces ^= move;
            board.all_pieces ^= move;
        } else if constexpr (status.color_to_move == Black) {
            board.black_pawns ^= move;
            board.black_pieces ^= move;
            board.all_pieces ^= move;
            callback(board, move, status.color_to_move, Chess_Pieces::Pawn);
            board.black_pawns ^= move;
            board.black_pieces ^= move;
            board.all_pieces ^= move;
        }
    }
}


#endif //MOVE_RECEIVER_H
