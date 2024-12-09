

#include <vector>
#include "../include/bishop_attack_masks.h"
#include "../include/bitboard.h"
#include "../include/create_occupantion_of_mask.h"
#include "../include/create_possible_bishop_moves.h"
#include "../include/create_possible_rook_moves.h"
#include "../include/rook_attack_masks.h"

#include "boost/random.hpp"
#include "fmt/printf.h"


typedef unsigned long long MagicNumber;

/**
 * 
 * @param mask
 * @param relevant_bits 
 * @return 
 */
MagicNumber magic_candidate(Bitboard mask, int relevant_bits) {
    static boost::mt19937 rng;
    static boost::uniform_int<MagicNumber> dist(0ULL, 0xFFFFFFFFFFFFFFFFULL);

    MagicNumber res = dist(rng) & dist(rng) & dist(rng);

    while (count_1_bits(mask * res & 0xFF00000000000000) < 6) {
        res = dist(rng) & dist(rng) & dist(rng);
    }

    return res;
}

MagicNumber find_magic_number(const Position position, const bool isBishop) {

    const Bitboard mask = isBishop ? Constants::bishop_attack_masks[position] : Constants::rook_attack_masks[position];
    const int relevant_bits_in_mask = count_1_bits(mask);
    const int number_of_masks = 1 << relevant_bits_in_mask;

    //
    std::vector<Bitboard> occupancy_table;
    std::vector<Bitboard> attack_table;
    std::vector<Bitboard> used_attack_table;

    // fill the occupation- and attacks-tables with the relevant data.
    for (int index = 0; index < 1 << relevant_bits_in_mask; index++ ) {
        occupancy_table[index] = create_occupation_of_mask(index, mask);

        attack_table[index] = isBishop ? create_possible_bishop_moves(mask, position) : create_possible_rook_moves(mask, position);
    }

    // the test-loop for magic number candidates
    for (int magic_candidate_number = 0; magic_candidate_number < 1000000000; magic_candidate_number++ ) {
        MagicNumber magic_number = magic_candidate(mask, relevant_bits_in_mask);

    }

    for (int i = 0; i < 100; i++ ) {
        //MagicNumber random_number = magic_candidate();
        //fmt::print("/* {} */ 0b{:0b}ULL,\n", print_position(position),random_number);
    }
    return 0;
}


int main() {

    Position position = E4;

   //find_magic_number(position, 6, false);

    return 0;
}

