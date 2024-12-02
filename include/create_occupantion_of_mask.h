//
// Created by peter on 02/12/2024.
//

#ifndef CREATE_OCCUPANCY_H
#define CREATE_OCCUPANCY_H

#include "bitboard.h"

/**
 * The mask Bitboard is supposed to have ones everywhere where there _could_ be a chess figure that
 * would restrict the movement of a slider piece. The index parameter is supposed to be in the range
 * of zero to the number of possible (partly) occupancies of these squares. This function create a 1:1 mapping
 * between the index and the occupancy; i. e, if index runs over the range of  zero to the number of possible
 * occupations, there is a single occupation computed (by this function) that corresponds to the index.
 *
 * @note There is one and only one such occupation for each valid index.
 *
 * @param index
 * @param mask
 * @return Given an index the above described occupation is returned.
 */
Bitboard create_occupation_of_mask( unsigned int index, Bitboard mask );

#endif //CREATE_OCCUPANCY_H
