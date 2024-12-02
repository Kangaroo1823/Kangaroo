//
// Created by peter on 02/12/2024.
//

#include "../include/bitboard.h"
#include "../include/create_possible_rook_moves.h"


Bitboard create_possible_rook_moves( const Bitboard mask, const Position position ) {
    Bitboard moves = 0ULL;

    const int file = position & 7;
    const int rank = position >> 3;

    for ( int r = rank + 1; r < 8; r++ ) {
        const Position pos = rank_file_to_position(r, file);
        moves = set_bit(moves, pos);
        if ( (1ULL << pos) & mask ) break;
    }

    for ( int r = rank - 1; r >= 0; r-- ) {
        const Position pos = rank_file_to_position(r, file);
        moves = set_bit(moves, pos);
        if ( (1ULL << pos) & mask ) break;
    }

    for ( int f = file + 1; f < 8; f++ ) {
        const Position pos = rank_file_to_position(rank, f);
        moves = set_bit(moves, pos);
        if ( (1ULL << pos) & mask ) break;
    }

    for ( int f = file - 1; f >= 0; f-- ) {
        const Position pos = rank_file_to_position(rank, f);
        moves = set_bit(moves, pos);
        if ( (1ULL << pos) & mask ) break;
    }

    return moves;
}
