//
// Created by peter on 02/12/2024.
//

#ifndef BISHOP_ATTACK_MASKS_H
#define BISHOP_ATTACK_MASKS_H

#include <array>

#include "bitboard.h"

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

namespace Constants {
    /**
     * @brief Array of 64-bit integers where a bit is set (1) iff a figure there
     * restricts movement of the bishop.
     *
     * The array has 64 elements and is indexed by the position of the bishop on
     * an otherwise empty chess board. At index 0 it is assumed that the bishop is on
     * the square A1, at index 7 the bishop is assumed to be at index H1, at index 8
     * the bishop is at A2, etc.
     *
     * The array is composed of 64-bit unsigned integers. Each bit represents a
     * square of the chess board. If the bit is set (1), it states that another figure
     * at the corresponding square might restrict further movement of the bishop.
     *
     * Note: It is assumed that the bishop can capture the other figure, but cannot go any
     * further in the direction.
     *
     * Otherwise, if a figure at that position does not restrict the bishops' movement the
     * corresponding bit is unset (0). Again it is assumed that the bishop might move to
     * this square
     */
    inline constexpr std::array<Bitboard, 64> bishop_attack_masks = as_constant(create_attack_masks<Slider_t::bishop>());
    inline constexpr std::array<Bitboard, 64> rook_attack_masks = as_constant(create_attack_masks<Slider_t::rook>());
}
#endif //BISHOP_ATTACK_MASKS_H
