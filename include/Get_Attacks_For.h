//
// Created by peter on 2/23/25.
//

#ifndef GET_ATTACKS_FOR_H
#define GET_ATTACKS_FOR_H

#include "Address_Attack_Tables.h"
#include "constants_attacks.h"
#include "Bit_Board.h"

template<Chess_Pieces slider>
[[nodiscard]] _ForceInline constexpr Bitboard get_attacks_for(const Square position, const Bitboard occupancy) {

    const std::size_t index = create_magic_hash_index<slider>(position, occupancy,
                                                              Bitcount(Constants::rook_magic_numbers[std::to_underlying(
                                                                  position)]));
    if constexpr (slider == Chess_Pieces::Rook) {
        return Constants::rook_attack_masks[index];
    } else {
        return Constants::bishop_attack_masks[index];
    }

}



#endif //GET_ATTACKS_FOR_H
