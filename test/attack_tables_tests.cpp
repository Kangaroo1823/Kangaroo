//
// Created by peter on 17/12/2024.
//

#include <fstream>
#include <iostream>

#include "attack_tables.h"
#include "bishop_attack_masks.h"
#include "create_possible_bishop_moves.h"
#include "create_possible_rook_moves.h"
#include "rook_attack_masks.h"
#include "catch2/catch_test_macros.hpp"


template<bool isBishop>
constexpr std::vector<std::string> create_attack_tables(const Position &position) {
    std::vector<std::string> result;
    result.reserve(isBishop ? 512 : 4096);

    const Bitboard mask = isBishop
                              ? Constants::bishop_attack_masks[std::to_underlying(position)]
                              : Constants::rook_attack_masks[std::to_underlying(position)];

    const int64_t relevant_bits = Bitcount(mask);
    const std::size_t number_of_masks = 1UL << relevant_bits;

    std::array<Bitboard, isBishop ? 512 : 4096> attack_table;

    REQUIRE(number_of_masks <= attack_table.size());

    for (std::size_t index = 0; index < number_of_masks; ++index) {
        const Bitboard occupancy = create_occupancy_of_mask(index, mask);
        const Bitboard attack = isBishop
                                    ? create_possible_bishop_moves(occupancy, position)
                                    : create_possible_rook_moves(occupancy, position);

        auto hashed_index = compute_magic_hash<isBishop>(position, occupancy, relevant_bits);

        attack_table[hashed_index] = attack;
    }

    std::ranges::for_each(attack_table, [&](const Bitboard &bitboard) {
        result.emplace_back(format_bitboard(bitboard));
    });

    return result;
}

TEST_CASE("Attack Tables Test", "[attack_tables_test]") {
    std::size_t line_length = 0;

    std::ofstream out("bishop_attacks.inc", std::ofstream::out);
    for (const auto &position: All_Positions) {
        for (std::vector<std::string> vec = create_attack_tables<true>(position); const auto &str: vec) {
            out << str;
            line_length += str.size();
            if (line_length > 100) {
                out << "\n";
                line_length = 0;
            }
        }
    }
    out.close();

    out.open("rook_attacks.inc", std::ofstream::out);
    for (const auto &position: All_Positions) {
        for (const std::vector<std::string> vec = create_attack_tables<false>(position); const auto &str: vec) {
            out << str;
            line_length += str.size();
            if (line_length > 80) {
                out << "\n";
                line_length = 0;
            }
        }
    }
    out.close();

    REQUIRE(true);
}
