//
// Created by peter on 02/12/2024.
//

#ifndef ATTACK_MASKS_H
#define ATTACK_MASKS_H

#include <array>
#include "bitboard.h"
#include "constants.h"

/**********************************************************************************
 * Slider attack masks
 *********************************************************************************/


template<Slider slider>
constexpr Bitboard create_attack_mask_for(const Position& position) {

    Bitboard mask = 0ULL;

    const auto rank = static_cast<int64_t>(std::to_underlying(position) >> 3);
    const auto file = static_cast<int64_t>(std::to_underlying(position) & 7);

    if constexpr (slider == Slider::bishop) {

        for (int64_t r = rank + 1, f = file + 1; r < 7 && f < 7; ++r, ++f) mask |= 1ULL << (r * 8 + f);
        for (int64_t r = rank + 1, f = file - 1; r < 7 && f > 0; ++r, --f) mask |= 1ULL << (r * 8 + f);
        for (int64_t r = rank - 1, f = file - 1; r > 0 && f > 0; --r, --f) mask |= 1ULL << (r * 8 + f);
        for (int64_t r = rank - 1, f = file + 1; r > 0 && f < 7; --r, ++f) mask |= 1ULL << (r * 8 + f);

    return mask;

    } else {

        for (int64_t r = rank + 1; r < 7; ++r) mask |= 1ULL << (r * 8 + file);
        for (int64_t f = file + 1; f < 7; ++f) mask |= 1ULL << (rank * 8 + f);
        for (int64_t r = rank - 1; r > 0; --r) mask |= 1ULL << (r * 8 + file);
        for (int64_t f = file - 1; f > 0; --f) mask |= 1ULL << (rank * 8 + f);

    }

    return mask;

}

template<Slider slider>
constexpr std::array<Bitboard, 64> create_attack_masks() {
    std::array<Bitboard, 64> result = {};
    for (auto board = result.begin(); const auto &position : All_Positions) {
        *board = create_attack_mask_for<slider>(position);
        board++;
    }

    return result;
}




#endif //ATTACK_MASKS_H
