//
// Created by U439644 on 12/23/2024.
//

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "base.h"

#include "constants_masks.h"
#include "constants_magics.h"
#include "constants_attacks.h"
#include "constants_xray_visibility_tables.h"

template <Slider slider>
[[nodiscard]] _ForceInline constexpr Bitboard get_attack_mask_for(const Position position) {

    static_assert(slider == Slider::bishop || slider == Slider::rook);

    const std::size_t index = std::to_underlying(position);

    if constexpr (slider == Slider::rook) {
        return Constants::rook_attack_masks[index];
    } else if constexpr (slider == Slider::bishop) {
        return Constants::bishop_attack_masks[index];
    }

    return 0;
}

template <Slider slider>
[[nodiscard]] _ForceInline constexpr MagicNumber get_magic_number_for(const Position position) {

    static_assert(slider == Slider::bishop || slider == Slider::rook);

    const std::size_t index = std::to_underlying(position);

    if constexpr (slider == Slider::rook) {
        return Constants::rook_magic_numbers[index];
    } else if constexpr (slider == Slider::bishop) {
        return Constants::bishop_magic_numbers[index];
    }

    return 0;

}

template <Slider slider>
[[nodiscard]] _ForceInline constexpr Bitboard get_attacks_for(const Position position, const Bitboard occupancy) {

}

template<Slider slider>
[[nodiscard]] _ForceInline constexpr Bitboard get_xray_visibility_for(const Position king_position, const Position slider_position) {

    static_assert(slider == Slider::bishop || slider == Slider::rook);

    const std::size_t index = std::to_underlying(slider_position) * 64 + std::to_underlying(king_position);

    if constexpr (slider == Slider::rook) {
        return Constants::rook_xray_visibility_table[index];
    } else if constexpr (slider == Slider::bishop) {
        return Constants::bishop_xray_visibility_table[index];
    }

    return 0;
}


#endif //CONSTANTS_H
