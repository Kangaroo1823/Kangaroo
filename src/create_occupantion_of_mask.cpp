//
// Created by peter on 02/12/2024.
//

#include "../include/bitboard.h"
#include "../include/create_occupantion_of_mask.h"

Bitboard create_occupation_of_mask( unsigned int index, Bitboard mask ) {
    Bitboard occupancy = 0ULL;

    const unsigned int count = Bitcount(mask);
    for ( unsigned int i = 0; i < count; i++ ) {
        unsigned int s = SquareOf( mask );
        mask &= mask - 1ULL;
        if (index & 1ULL << i ) occupancy |= 1ULL << s;
    }

    return occupancy;
}