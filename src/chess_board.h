//
// Created by peter on 01/12/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "Bitboard.h"

typedef struct {
    Bitboard white_king;
    Bitboard white_queens;
    Bitboard white_rooks;
    Bitboard white_knights;
    Bitboard white_bishops;
    Bitboard white_pawns;
    Bitboard white_pieces;

    Bitboard black_king;
    Bitboard black_queens;
    Bitboard black_rooks;
    Bitboard black_knights;
    Bitboard black_bishops;
    Bitboard black_pawns;
    Bitboard black_pieces;
} Chess_Board;


Chess_Board *create_chess_board();

void print_chess_board(const Chess_Board* board);

#endif //CHESS_BOARD_H
