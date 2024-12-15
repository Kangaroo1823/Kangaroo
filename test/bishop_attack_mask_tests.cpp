//
// Created by peter on 02/12/2024.
//


#include <array>                             // for array
#include "../include/bishop_attack_masks.h"  // for bishop_attack_masks
#include "../include/bitboard.h"             // for Bitboard, Position, prin...
#include "catch2/catch_test_macros.hpp"      // for StringRef, AssertionHandler
#include "catch2/internal/catch_test_registry.hpp"

Bitboard create_bishop_attack_mask(const Position position) {
    Bitboard mask = 0ULL;

    const auto rank = static_cast<int64_t>(std::to_underlying(position) >> 3);
    const auto file = static_cast<int64_t>(std::to_underlying(position) & 7);

    for (int64_t r = rank + 1, f = file + 1; r < 7 && f < 7; ++r, ++f) mask |= 1ULL << (r * 8 + f);
    for (int64_t r = rank + 1, f = file - 1; r < 7 && f > 0; ++r, --f) mask |= 1ULL << (r * 8 + f);
    for (int64_t r = rank - 1, f = file - 1; r > 0 && f > 0; --r, --f) mask |= 1ULL << (r * 8 + f);
    for (int64_t r = rank - 1, f = file + 1; r > 0 && f < 7; --r, ++f) mask |= 1ULL << (r * 8 + f);

    return mask;
}

TEST_CASE("Bishops attack masks", "[bishop_attack_mask]") {
    for (const Position &position : All_Positions) {

        const Bitboard board = create_bishop_attack_mask(position);
        print_bitboard(board);
        REQUIRE(Constants::bishop_attack_masks[std::to_underlying(position)] == board);
    }
}
