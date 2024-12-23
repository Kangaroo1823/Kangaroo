//
// Created by peter on 15/12/2024.
//

#include "../tools/magic_numbers.h"
#include <fmt/base.h>   // for print
#include <random>       // for mt19937_64


namespace Constants::Impl {

    MagicNumber magic_candidate(const Bitboard occupation) {
        static std::mt19937_64 rng;

        MagicNumber res;

        // make sure that the random number is not too small.
        do {
            res = rng() & rng() & rng();
        } while (Bitcount(occupation * res & 0xFF00000000000000ULL) < 6);

        return res;
    }

    void compute_magic_numbers() {
        // loop over all 64 board squares
        fmt::print("// rooks:\n");
        for (const auto square: All_Positions) {
            const MagicNumber m = find_magic_number<Slider::rook>(square);
            fmt::print("/* magic number found for {}: */", print_position(square));
            fmt::print(" 0x{0:x},\n", m);
        }
        fmt::print("\n");
        fmt::print("// bishops:\n");
        for (const auto square: All_Positions) {
            const MagicNumber m = find_magic_number<Slider::bishop>(square);
            fmt::print("/* magic number found for {}: */", print_position(square));
            fmt::print(" 0x{0:x},\n", m);
        }
    }
}