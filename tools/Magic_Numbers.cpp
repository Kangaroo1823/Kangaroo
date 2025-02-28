// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com//
//
//
// Created by peter on 15/12/2024.
//

#include "Magic_Numbers.h"
#include <print>   // for print
#include <random>       // for mt19937_64


namespace Constants::Impl {

    MagicNumber magic_candidate(const Bitboard occupation) {
        static std::mt19937_64 rng; // -V1057

        MagicNumber res;

        // make sure that the random number is not too small.
        do {
            res = rng() & rng() & rng();
        } while (Bitcount(occupation * res & 0xFF00000000000000ULL) < 6);

        return res;
    }

    void compute_magic_numbers() {
        // loop over all 64 board squares
        std::print("// rooks:\n");
        for (const auto square: All_Positions) {
            const MagicNumber m = find_magic_number<Chess_Pieces::Rook>(square);
            std::print("/* magic number found for {}: */", format_square(square));
            std::print(" 0x{0:x},\n", m);
        }
        std::print("\n");
        std::print("// bishops:\n");
        for (const auto square: All_Positions) {
            const MagicNumber m = find_magic_number<Chess_Pieces::Bishop>(square);
            std::print("/* magic number found for {}: */", format_square(square));
            std::print(" 0x{0:x},\n", m);
        }
    }
}