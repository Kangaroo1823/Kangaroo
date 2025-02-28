//
// Created by peter on 2/23/25.
//

#ifndef ADDRESS_ATTACK_TABLES_H
#define ADDRESS_ATTACK_TABLES_H

#include "Types.h"
#include "constants_magics.h"
#include "constants_masks.h"


template<Chess_Pieces slider>
_ForceInline constexpr std::size_t create_hash_index(const Square position, const Bitboard occupancy,
                                                     const int64_t relevant_bits) {
    if constexpr (slider == Chess_Pieces::Bishop) {
        return (occupancy * Constants::bishop_magic_numbers[std::to_underlying(position)]) >> (64 - relevant_bits);
    } else {
        return (occupancy * Constants::rook_magic_numbers[std::to_underlying(position)]) >> (64 - relevant_bits);
    }
}


template<Chess_Pieces slider>
_ForceInline constexpr std::size_t create_magic_hash_index(const Square position, const Bitboard occupancy,
                                                           const int64_t relevant_bits) {
    const std::size_t offset = (slider == Chess_Pieces::Bishop ? 512 : 4096) * std::to_underlying(position);

    return offset + create_hash_index<slider>(position, occupancy, relevant_bits);
}


template<Chess_Pieces slider>
/**
 * Computes the attack mask for a sliding piece (rook or bishop) based on its position
 * on the board. The function determines if the slider is a bishop or rook and retrieves
 * the corresponding attack mask from the predefined constants.
 *
 * @param position The position of the sliding piece on the chess board (e.g., A1, B2, etc.).
 * @return The attack mask represented as a Bitboard, defining all possible attack moves
 *         from the given position for the respective slider.
 */
_ForceInline constexpr Bitboard get_attack_mask_for_slider(const Square position) {
    return slider == Chess_Pieces::Bishop
               ? Constants::bishop_attack_masks[std::to_underlying(position)]
               : Constants::rook_attack_masks[std::to_underlying(position)];
}


#endif //ADDRESS_ATTACK_TABLES_H
