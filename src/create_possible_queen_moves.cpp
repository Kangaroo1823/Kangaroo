//
// Created by peter on 02/12/2024.
//

#include "../include/bitboard.h"
#include "../include/create_possible_queen_moves.h"
#include "../include/create_possible_rook_moves.h"
#include "../include/create_possible_bishop_moves.h"

Bitboard create_possible_queen_moves( const Bitboard mask, const Position position ) {
    const Bitboard moves = create_possible_rook_moves(mask, position);
    return moves | create_possible_bishop_moves(mask, position);
}