#include <vector>
#include "../include/bishop_attack_masks.h"
#include "../include/bitboard.h"
#include "../include/create_occupantion_of_mask.h"
#include "../include/create_possible_bishop_moves.h"
#include "../include/create_possible_rook_moves.h"
#include "../include/rook_attack_masks.h"

#include "fmt/printf.h"
#include <random>

typedef unsigned long long MagicNumber;

/**
 * 
 * @param occupation
 * @param relevant_bits 
 * @return 
 */
MagicNumber magic_candidate(const Bitboard occupation) {
    static std::mt19937_64 rng;

    MagicNumber res = rng() & rng() & rng();

    while (Bitcount(occupation * res & 0xFF00000000000000) < 6) {
        res = rng() & rng() & rng();
    }

    return res;
}

template<bool isBishop>
MagicNumber find_magic_number(const Position position_of_figure) {

    // get the mask corresponding to the position of the figure.
    const Bitboard mask = isBishop
                              ? Constants::bishop_attack_masks[position_of_figure]
                              : Constants::rook_attack_masks[position_of_figure];

    // compute the size of the mask
    const int relevant_bits_in_mask = Bitcount(mask);

    // compute the number of positions that can be created within the given mask.
    const int number_of_masks = 1 << relevant_bits_in_mask;

    //
    std::array<Bitboard, isBishop ? 512 : 4096> occupancy_table;
    std::array<Bitboard, isBishop ? 512 : 4096> attack_table;
    std::array<Bitboard, isBishop ? 512 : 4096> used_attack_table;

    // fill the occupation- and attacks-tables with the relevant data.
    for (int index = 0; index < number_of_masks; index++) {
        occupancy_table[index] = create_occupation_of_mask(index, mask);

        attack_table[index] = isBishop
                                  ? create_possible_bishop_moves(mask, position_of_figure)
                                  : create_possible_rook_moves(mask, position_of_figure);
    }

    // the test-loop for magic number candidates
    for (int magic_candidate_number = 0; magic_candidate_number < 1000000000; magic_candidate_number++) {
        MagicNumber magic_number = magic_candidate(mask, relevant_bits_in_mask);
    }

    for (int i = 0; i < 100; i++) {
        //MagicNumber random_number = magic_candidate();
        //fmt::print("/* {} */ 0b{:0b}ULL,\n", print_position(position),random_number);
    }
    occupancy_table[0] = isBishop ? create_possible_bishop_moves(mask, position_of_figure) : create_possible_rook_moves(mask, position_of_figure);
    return occupancy_table[0];
}


int main() {
    // Position position = E4;

    //find_magic_number(position, 6, false);

    return 0;
}
