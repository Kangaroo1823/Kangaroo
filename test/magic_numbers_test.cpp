// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 15/12/2024.
//

#include <immintrin.h>                   // for _pdep_u64
#include <string>                        // for basic_string
#include "gtest/gtest.h"  // for AssertionHandler, StringRef

#include "bitboard.h"
#include "magic_numbers.h"
#include "constants_masks.h"
#include "constants_magics.h"

template<Slider slider>
bool check_magic_number(const Square position_of_figure, const MagicNumber magic_number) {
    // get the mask corresponding to the position of the figure.
    const Bitboard mask = slider == Slider::bishop
                              ? Constants::bishop_attack_masks[std::to_underlying(position_of_figure)]
                              : Constants::rook_attack_masks[std::to_underlying(position_of_figure)];

    // compute the size of the mask
    const int64_t relevant_bits_in_mask = Bitcount(mask);

    // compute the number of positions that can be created within the given mask.
    const auto number_of_masks = 1UL << relevant_bits_in_mask;

    // holds every possible occupation within mask
    std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> occupancy_table{};
    Constants::Impl::populate_occupancy_with_mask<slider>(mask, occupancy_table);

    // a bit in attack_table[index] is set iff the figure in question can attack it given the
    // occupancy in occupancy_table[index].
    std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> attack_table{};
    Constants::Impl::fill_attack_table_from_occupancy<slider>(position_of_figure, occupancy_table, attack_table);

    std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> used_attack_table{};
    Constants::Impl::reset_used_attack_table<slider>(used_attack_table);

    return Constants::Impl::check_magic_number_collisions<slider>(relevant_bits_in_mask, number_of_masks,
                                                                    occupancy_table, attack_table,
                                                                    used_attack_table, magic_number);
}

TEST(MagicNumbers, magic_numbers) {

    for (const auto &position: All_Positions) {

        // cppcheck-suppress unreadVariable
        bool flag = check_magic_number<Slider::rook>(position, Constants::rook_magic_numbers[std::to_underlying(position)]);
        ASSERT_TRUE(flag);

        // cppcheck-suppress unreadVariable
        bool flag2 = check_magic_number<Slider::bishop>(position, Constants::bishop_magic_numbers[std::to_underlying(position)]);
        ASSERT_TRUE(flag2);
    }
}
