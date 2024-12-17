//
// Created by peter on 02/12/2024.
//

#ifndef CREATE_OCCUPANCY_H
#define CREATE_OCCUPANCY_H

#include "bitboard.h"


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
#define create_occupation_of_mask(index,mask) _pdep_u64(index,mask)


#endif //CREATE_OCCUPANCY_H
