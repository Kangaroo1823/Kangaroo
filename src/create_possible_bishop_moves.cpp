//
// Created by peter on 02/12/2024.
//

#include "../include/bitboard.h"
#include "../include/create_possible_bishop_moves.h"

Bitboard create_possible_bishop_moves( const Bitboard mask, const Position position ) {
    Bitboard moves = 0ULL;

    const int file = position & 7;
    const int rank = position >> 3;

    for ( int r = rank + 1, f = file + 1; r < 8 && f < 8; r++, f++ ) {
        const Position pos = rank_file_to_position(r, f);
        moves = set_bit(moves, pos);
        if ( (1ULL << pos) & mask ) break;
    }

    for ( int r = rank + 1, f = file - 1; r < 8 && f >= 0; r++, f-- ) {
        const Position pos = rank_file_to_position(r, f);
        moves = set_bit(moves, pos);
        if ( (1ULL << pos) & mask ) break;
    }

    for ( int r = rank - 1, f = file - 1; r >= 0 && f >= 0; r--, f-- ) {
        const Position pos = rank_file_to_position(r, f);
        moves = set_bit(moves, pos);
        if ( (1ULL << pos) & mask ) break;
    }

    for ( int r = rank - 1, f = file + 1; r >= 0 && f < 8; r--, f++ ) {
        const Position pos = rank_file_to_position(r, f);
        moves = set_bit(moves, pos);
        if ( (1ULL << pos) & mask ) break;
    }

    return moves;
}
