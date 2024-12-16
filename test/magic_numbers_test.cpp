//
// Created by peter on 15/12/2024.
//

#include <magic_numbers.h>
#include <immintrin.h>                   // for _pdep_u64
#include <string>                        // for basic_string
#include "catch2/catch_test_macros.hpp"  // for AssertionHandler, StringRef


template<bool isBishop>
bool check_magic_number(const Position position_of_figure, const Constants::MagicNumber magic_number) {
    // get the mask corresponding to the position of the figure.
    const Bitboard mask = isBishop
                              ? Constants::bishop_attack_masks[std::to_underlying(position_of_figure)]
                              : Constants::rook_attack_masks[std::to_underlying(position_of_figure)];

    // compute the size of the mask
    const int64_t relevant_bits_in_mask = Bitcount(mask);

    // compute the number of positions that can be created within the given mask.
    const auto number_of_masks = 1UL << relevant_bits_in_mask;

    // holds every possible occupation within mask
    std::array<Bitboard, isBishop ? 512 : 4096> occupancy_table{};
    Constants::Impl::populate_occupancy_with_mask<isBishop>(mask, occupancy_table);

    // a bit in attack_table[index] is set iff the figure in question can attack it given the
    // occupancy in occupancy_table[index].
    std::array<Bitboard, isBishop ? 512 : 4096> attack_table{};
    Constants::Impl::fill_attack_table_from_occupancy<isBishop>(position_of_figure, occupancy_table, attack_table);

    std::array<Bitboard, isBishop ? 512 : 4096> used_attack_table{};
    Constants::Impl::reset_used_attack_table<isBishop>(used_attack_table);

    return Constants::Impl::check_magic_number_collisions<isBishop>(relevant_bits_in_mask, number_of_masks,
                                                                    occupancy_table, attack_table,
                                                                    used_attack_table, magic_number);
}

TEST_CASE("MagicNumbers", "[magic_numbers]") {
    for (const auto &position: All_Positions) {
        fmt::print("Rook: Position: {}\n", print_position(position));
        // cppcheck-suppress unreadVariable
        bool flag = check_magic_number<false>(position, Constants::Rook_Magic_Numbers[std::to_underlying(position)]);
        REQUIRE(flag);

        fmt::print("Bishop: Position: {}\n", print_position(position));
        // cppcheck-suppress unreadVariable
        bool flag2 = check_magic_number<true>(position, Constants::Bishop_Magic_Numbers[std::to_underlying(position)]);
        REQUIRE(flag2);
    }
}
