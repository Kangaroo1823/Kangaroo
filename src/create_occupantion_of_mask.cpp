//
// Created by peter on 02/12/2024.
//

#include "../include/bitboard.h"
#include "../include/create_occupantion_of_mask.h"

/**
 * Creates an occupation mask on a bitboard based on the provided index and mask.
 *
 * The function utilizes the parallel bits deposit instruction (_pdep_u64).
 * It maps bits from the index value onto the specified positions in the mask.
 *
 * @param index An unsigned integer representing the index or bit pattern to be mapped onto the mask.
 * @param mask A Bitboard representing the mask where the index bits are to be deposited.
 * @return A Bitboard with the occupation mask applied, effectively storing the mapping of index bits to the mask.
 */
Bitboard create_occupation_of_mask(const unsigned int index, Bitboard mask ) {

    return _pdep_u64(index, mask);

    /*
    Bitboard occupancy = 0ULL;

    unsigned int i = 0;
    Bitloop(mask) {
        if (index & 1ULL << i++ ) occupancy |= 1ULL << SquareOf( mask );
    }

    return occupancy;
*/

/*    const unsigned int count = Bitcount(mask);
    for ( unsigned int i = 0; i < count; i++ ) {
        unsigned int s = SquareOf( mask );
        mask &= mask - 1ULL;
        if (index & 1ULL << i ) occupancy |= 1ULL << s;
    }

    return occupancy; */
}