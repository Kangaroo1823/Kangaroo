//
// Created by peter on 02/12/2024.
//

#include <cstddef>                // for size_t
#include <utility>                // for to_underlying
#include "../include/bitboard.h"  // for rank_file_to_position, set_bit, Pos...

Bitboard create_possible_bishop_moves( const Bitboard occupancy, const Position position ) {
    Bitboard moves = 0ULL;

    const std::size_t file = std::to_underlying(position) & 7;
    const std::size_t rank = std::to_underlying(position) >> 3;

    for ( std::size_t r = rank + 1, f = file + 1; r < 8 && f < 8; r++, f++ ) {
        const Position pos = rank_file_to_position(r, f);
        moves = set_bit(moves, pos);
        if ( 1ULL << std::to_underlying(pos) & occupancy ) break;
    }

    for ( std::size_t r = rank + 1, f = file; r < 8 && f > 0; r++, f-- ) {
        const Position pos = rank_file_to_position(r, f - 1 );
        moves = set_bit(moves, pos);
        if ( 1ULL << std::to_underlying(pos) & occupancy ) break;
    }

    for ( std::size_t r = rank, f = file; r > 0 && f > 0; r--, f-- ) {
        const Position pos = rank_file_to_position(r-1, f-1);
        moves = set_bit(moves, pos);
        if ( 1ULL << std::to_underlying(pos) & occupancy ) break;
    }

    for ( std::size_t r = rank, f = file + 1; r > 0 && f < 8; r--, f++ ) {
        const Position pos = rank_file_to_position(r -1, f);
        moves = set_bit(moves, pos);
        if ( 1ULL << std::to_underlying(pos) & occupancy ) break;
    }

    return moves;
}
