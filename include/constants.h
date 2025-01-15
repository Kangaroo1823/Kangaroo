//
// Created by U439644 on 12/23/2024.
//

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "base.h"

#include "constants_masks.h"
#include "constants_magics.h"
#include "constants_attacks.h"
#include "constants_pin_tables.h"
#include "constants_xray_visibility_tables.h"

template<Slider slider>
[[nodiscard]] _ForceInline constexpr Bitboard get_attack_mask_for(const Square position) {

    using enum Slider;

    static_assert(slider == Bishop || slider == Rook);

    const std::size_t index = std::to_underlying(position);

    if constexpr (slider == Rook) {
        return Constants::rook_attack_masks[index];
    } else if constexpr (slider == Bishop) {
        return Constants::bishop_attack_masks[index];
    }

    return 0;
}

template<Slider slider>
[[nodiscard]] _ForceInline constexpr MagicNumber get_magic_number_for(const Square position) {

    using enum Slider;

    static_assert(slider == Bishop || slider == Rook);

    const std::size_t index = std::to_underlying(position);

    if constexpr (slider == Rook) {
        return Constants::rook_magic_numbers[index];
    } else if constexpr (slider == Bishop) {
        return Constants::bishop_magic_numbers[index];
    }

    return 0;
}


template<Slider slider>
[[nodiscard]] _ForceInline constexpr Bitboard get_attacks_for(const Square position, const Bitboard occupancy,
                                                              const int64_t relevant_bits) {

    using enum Slider;

    static_assert(slider == Bishop || slider == Rook);

    if constexpr (slider == Bishop) {
        std::size_t index = 512 * std::to_underlying(position);
        index += (occupancy * Constants::bishop_magic_numbers[std::to_underlying(position)]) >> (64 - relevant_bits);
        return Constants::bishop_attack_table[index];
    } else if constexpr (slider == Rook) {
        std::size_t index = 4096 * std::to_underlying(position);
        index += (occupancy * Constants::rook_magic_numbers[std::to_underlying(position)]) >> (64 - relevant_bits);
        return Constants::rook_attack_table[index];
    }

    return 0;
}

template<Slider slider>
[[nodiscard]] _ForceInline constexpr Bitboard get_attacks_for(const Square position, const Bitboard all_pieces) {
    using enum Slider;

    static_assert(slider == Bishop || slider == Rook);

    if constexpr (slider == Rook) {
        const Bitboard mask = Constants::rook_attack_masks[std::to_underlying(position)];
        const Bitboard occupancy = all_pieces & mask;
        return get_attacks_for<Rook>(position, occupancy, Bitcount(mask));
    } else if (slider == Bishop) {
        const Bitboard mask = Constants::bishop_attack_masks[std::to_underlying(position)];
        const Bitboard occupancy = all_pieces & mask;
        return get_attacks_for<Bishop>(position, occupancy, Bitcount(mask));
    }

    return 0;
}

template<Slider slider>
[[nodiscard]] _ForceInline constexpr Bitboard get_xray_for(const Square position) {

    using enum Slider;

    static_assert(slider == Bishop || slider == Rook);

    const std::size_t index = std::to_underlying(position);

    if constexpr (slider == Rook) {
        return Constants::rook_xray_visibility_table[index];
    } else if constexpr (slider == Bishop) {
        return Constants::bishop_xray_visibility_table[index];
    }

    return 0;
}

template<Slider slider>
[[nodiscard]] _ForceInline constexpr Bitboard get_pin_ray_for(const Square king_position,
                                                              const Square slider_position) {
    using enum Slider;

    static_assert(slider == Bishop || slider == Rook);

    const std::size_t index = std::to_underlying(slider_position) * 64 + std::to_underlying(king_position);

    if constexpr (slider == Rook) {
        return Constants::rook_pin_table[index];
    } else if constexpr (slider == Bishop) {
        return Constants::bishop_pin_table[index];
    }

    return 0;
}


#endif //CONSTANTS_H
