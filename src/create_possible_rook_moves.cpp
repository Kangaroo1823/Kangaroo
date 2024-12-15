//
// Created by peter on 02/12/2024.
//

#include "../include/bitboard.h"
#include "../include/create_possible_rook_moves.h"


Bitboard create_possible_rook_moves( const Bitboard mask, const Position position ) {
    Bitboard moves = 0ULL;

    const std::size_t file = std::to_underlying(position) & 7;
    const std::size_t rank = std::to_underlying(position) >> 3;

    for ( std::size_t r = rank + 1; r < 8; r++ ) {
        const Position pos = rank_file_to_position(r, file);
        moves = set_bit(moves, pos);
        if ( 1ULL << std::to_underlying(pos) & mask ) break;
    }

    for ( std::size_t r = rank; r > 0; r-- ) {
        const Position pos = rank_file_to_position(r-1, file);
        moves = set_bit(moves, pos);
        if ( 1ULL << std::to_underlying(pos) & mask ) break;
    }

    for ( std::size_t f = file + 1; f < 8; f++ ) {
        const Position pos = rank_file_to_position(rank, f);
        moves = set_bit(moves, pos);
        if ( 1ULL << std::to_underlying(pos) & mask ) break;
    }

    for ( std::size_t f = file; f > 0; f-- ) {
        const Position pos = rank_file_to_position(rank, f-1);
        moves = set_bit(moves, pos);
        if ( 1ULL << std::to_underlying(pos) & mask ) break;
    }

    return moves;
}
