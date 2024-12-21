//
// Created by peter on 01/12/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "bitboard.h"
#include <memory>

using Castle_Flags = enum class Castle_Flags_t : uint64_t {
    white_kingside = 1ULL << 0,
    white_queenside = 1ULL << 1,
    black_kingside = 1ULL << 2,
    black_queenside = 1ULL << 3,
};

using En_Passant_Flags = enum class En_Passant_Flags_t : uint64_t {
    en_passant_possible = 1ULL << 0,
    en_passant_impossible = 1ULL << 1,
};


using Chess_Board = struct Chess_Board_t {

    Bitboard white_king     = 0ULL;
    Bitboard white_queens   = 0ULL;
    Bitboard white_rooks    = 0ULL;
    Bitboard white_knights  = 0ULL;
    Bitboard white_bishops  = 0ULL;
    Bitboard white_pawns    = 0ULL;

    Bitboard black_king     = 0ULL;
    Bitboard black_queens   = 0ULL;
    Bitboard black_rooks    = 0ULL;
    Bitboard black_knights  = 0ULL;
    Bitboard black_bishops  = 0ULL;
    Bitboard black_pawns    = 0ULL;

    Bitboard black_pieces   = 0ULL;
    Bitboard white_pieces   = 0ULL;
    Bitboard all_pieces     = 0ULL;

    std::size_t en_passant_square   = 0;
    std::size_t half_move_number    = 0;
    std::size_t full_move_number    = 0;
};


std::unique_ptr<Chess_Board> create_chess_board_from_fen(const std::string_view &fen);


std::unique_ptr<Chess_Board> create_chess_board();
void print_chess_board(const Chess_Board *board);

#endif //CHESS_BOARD_H
