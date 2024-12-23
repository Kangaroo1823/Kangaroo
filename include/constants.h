//
// Created by U439644 on 12/23/2024.
//

#ifndef CONSTANTS_H
#define CONSTANTS_H

#ifndef GENERATE_MASKS
#  include "constants_masks.h"
#  ifndef GENERATE_MAGICS
#    include "constants_magics.h"
#  else
#  endif
#else
namespace Constants {

    inline constexpr std::array<Bitboard, 64> bishop_attack_masks = {};
    inline constexpr std::array<Bitboard, 64> rook_attack_masks = {};

}
#endif



#endif //CONSTANTS_H
