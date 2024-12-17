//
// Created by peter on 15/12/2024.
//

#include "magic_numbers.h"
#include <fmt/base.h>   // for print


namespace Constants::Impl {


    // generate 32-bit pseudo legal numbers
    uint32_t get_random_U32_number()
    {
        // pseudo random number state
        static uint32_t random_state = 1804289383;

        // get current state
        uint32_t number = random_state;

        // XOR shift algorithm
        number ^= number << 13;
        number ^= number >> 17;
        number ^= number << 5;

        // update random number state
        random_state = number;

        // return random number
        return number;
    }

    // generate 64-bit pseudo legal numbers
    uint64_t get_random_U64_number()
    {

        // init random numbers slicing 16 bits from MS1B side
        auto n1 = static_cast<uint64_t>(get_random_U32_number()) & 0xFFFF;
        auto n2 = static_cast<uint64_t>(get_random_U32_number()) & 0xFFFF;
        auto n3 = static_cast<uint64_t>(get_random_U32_number()) & 0xFFFF;
        auto n4 = static_cast<uint64_t>(get_random_U32_number()) & 0xFFFF;

        // return random number
        return n1 | (n2 << 16) | (n3 << 32) | (n4 << 48);
    }


    MagicNumber magic_candidate(const Bitboard occupation) {
        MagicNumber res;

        // make sure that the random number is not too small.
        do {
            res = get_random_U64_number() & get_random_U64_number() & get_random_U64_number();
        } while (Bitcount(occupation * res & 0xFF00000000000000ULL) < 6);

        return res;
    }

    void compute_magic_numbers() {
        // loop over all 64 board squares
        fmt::print("// rooks:\n");
        for (const auto square: All_Positions) {
            const MagicNumber m = find_magic_number<false>(square);
            fmt::print("/* magic number found for {}: */", print_position(square));
            fmt::print(" 0x{0:x},\n", m);
        }
        fmt::print("\n");
        fmt::print("// bishops:\n");
        for (const auto square: All_Positions) {
            const MagicNumber m = find_magic_number<true>(square);
            fmt::print("/* magic number found for {}: */", print_position(square));
            fmt::print(" 0x{0:x},\n", m);
        }
    }
}