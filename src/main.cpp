#include <fmt/base.h>                                 // for print
#include <cstdint>                                   // for int64_t, uint64_t
#include <sys/types.h>                                // for uint
#include <algorithm>
#include <array>                                      // for array
#include <random>                                     // for mt19937_64
#include "../include/bishop_attack_masks.h"           // for bishop_attack_m...
#include "../include/bitboard.h"                      // for Bitboard, Bitcount
#include "../include/create_possible_bishop_moves.h"  // for create_possible...
#include "../include/create_possible_rook_moves.h"    // for create_possible...
#include "../include/rook_attack_masks.h"             // for rook_attack_masks

using MagicNumber = uint64_t;


/**
 * \brief computes a candidate that can be used for hashing
 */
MagicNumber magic_candidate(const Bitboard occupation) {
    static std::mt19937_64 rng;

    MagicNumber res;

    // make sure that the random number is not too small.
    do {
        res = rng() & rng() & rng();
    } while (Bitcount(occupation * res & 0xFF00000000000000) < 6);

    return res;
}

template<bool isBishop>
/**
 * \brief Populates the occupancy table with all possible occupancies derived from the given mask.
 *
 * This function iterates through the provided occupancy table and fills it with bitboards
 * representing possible occupancies using the specified mask. The occupancy values are computed
 * using the mask and an index that corresponds to bit combinations forming unique occupancies
 * for a chess piece, determined by whether the piece is a bishop or not.
 *
 * \param mask A bitboard that represents the areas of the board considered for occupancy.
 * \param occupancy_table An array used to store all possible occupancy bitboards generated
 *        based on the given mask.
 */
void populate_occupancy_with_mask(const Bitboard mask, std::array<Bitboard, isBishop ? 512 : 4096> &occupancy_table) {
    typename std::array<Bitboard, isBishop ? 512 : 4096>::size_type index = 0;
    for (auto &occupancy: occupancy_table) {
        occupancy = create_occupation_of_mask<Bitboard, isBishop ? 512 : 4096>(index, mask);
        ++index;
    }
}

template<bool isBishop>
/**
 * \brief Fills the attack table based on the occupancy table and the position of the figure.
 *
 * Iterates through the occupancy and attack tables, generating attack bitboards
 * for each possible occupancy. Depending on whether the figure is a bishop or rook,
 * the method uses appropriate move generation functions.
 *
 * \tparam isBishop Boolean value indicating whether the figure is a bishop (true) or a rook (false).
 * \param position_of_figure The position of the figure on the board.
 * \param occupancy_table A precomputed table of all possible occupancies for the relevant squares.
 * \param attack_table A table that will be populated with the possible attack bitboards for the given occupancies.
 */
void fill_attack_table_from_occupancy(const Position position_of_figure,
                                      const std::array<Bitboard, isBishop ? 512 : 4096> &occupancy_table,
                                      std::array<Bitboard, isBishop ? 512 : 4096> &attack_table) {
    typename std::array<Bitboard, isBishop ? 512 : 4096>::size_type index = 0;
    for (auto &attack: attack_table) {
        // compute the attacks corresponding to index given occupancy.
        attack = isBishop
                     ? create_possible_bishop_moves(occupancy_table[index], position_of_figure)
                     : create_possible_rook_moves(occupancy_table[index], position_of_figure);
        ++index;
    }
}


template<bool isBishop>
/**
 * \brief Resets the provided used attack table by setting all elements to zero.
 *
 * This function is used to clear the contents of the used attack table to allow for
 * collision checking using a magic number.
 *
 * \param used_attack_table The array representing the used attack table. The size of the array
 * depends on whether it is for bishops (512) or rooks (4096).
 */
void reset_used_attack_table(std::array<Bitboard, isBishop ? 512 : 4096> used_attack_table) {
    // set the array used_attack_table to zero. We need it to check if we have a
    // collision using magic_number.
    std::ranges::for_each(used_attack_table, [](auto &i) { i = 0; });
}

template<bool isBishop>
/**
 * \brief Checks for collisions when applying a magic number to a set of occupancy and attack tables.
 *
 * This function applies a given magic number to occupancy values in the table and verifies that the
 * resulting mapped values in the `used_attack_table` do not collide with entries in the `attack_table`.
 *
 * \param relevant_bits_in_mask The number of bits in the mask relevant for the magic number computation.
 * \param number_of_masks The total number of masks in the occupancy and attack tables.
 * \param occupancy_table Stores occupancy configurations for a given piece.
 * \param attack_table Stores attack patterns corresponding to the occupancy configurations.
 * \param used_attack_table A table to track mappings created by the magic number.
 * \param magic_number The candidate magic number being tested for collisions.
 * \return True if there are no collisions using the magic number, false otherwise.
 */
bool check_magic_number_collisions(const int64_t relevant_bits_in_mask, const unsigned long number_of_masks,
                                   std::array<Bitboard, isBishop ? 512 : 4096> occupancy_table,
                                   std::array<Bitboard, isBishop ? 512 : 4096> attack_table,
                                   std::array<Bitboard, isBishop ? 512 : 4096> used_attack_table,
                                   MagicNumber magic_number) {
    for (uint index = 0; index < number_of_masks; index++) {
        Bitboard magic_index = occupancy_table[index] * magic_number >> (64 - relevant_bits_in_mask);

        if (used_attack_table[magic_index] == 0 || used_attack_table[magic_index] == attack_table[index]) {
            used_attack_table[magic_index] = attack_table[index];
        } else {
            return false;
        }
    }

    return true;
}

template<bool isBishop>
bool generate_magic_number(const Bitboard mask, const int64_t relevant_bits_in_mask,
                           const unsigned long number_of_masks,
                           const std::array<Bitboard, isBishop ? 512 : 4096> &occupancy_table,
                           const std::array<Bitboard, isBishop ? 512 : 4096> &attack_table,
                           MagicNumber &value1) {

    std::array<Bitboard, isBishop ? 512 : 4096> used_attack_table{};

    // the aim of the following loop is to find a magic number that works.
    // We do this brute force! get a candidate and see whether it works, i.e, there
    // are no collisions when using it.
    for (int magic_candidate_number = 0;
         magic_candidate_number < 1000000000; magic_candidate_number++) {
        MagicNumber magic_number = magic_candidate(mask);

        reset_used_attack_table<isBishop>(used_attack_table);

        const bool fail = check_magic_number_collisions<isBishop>(relevant_bits_in_mask, number_of_masks,
                                                                  occupancy_table, attack_table,
                                                                  used_attack_table, magic_number);

        // if magic number works
        if (!fail) {
            // return it
            value1 = magic_number;
            return true;
        }
    }
    return false;
}

template<bool isBishop>
MagicNumber find_magic_number(const Position position_of_figure) {
    // get the mask corresponding to the position of the figure.
    const Bitboard mask = isBishop
                              ? Constants::bishop_attack_masks[position_of_figure]
                              : Constants::rook_attack_masks[position_of_figure];

    // compute the size of the mask
    const int64_t relevant_bits_in_mask = Bitcount(mask);

    // compute the number of positions that can be created within the given mask.
    const auto number_of_masks = 1UL << relevant_bits_in_mask;

    // holds every possible occupation within mask
    std::array<Bitboard, isBishop ? 512 : 4096> occupancy_table{};
    populate_occupancy_with_mask<isBishop>(mask, occupancy_table);

    // a bit in attack_table[index] is set iff the figure in question can attack it given the
    // occupancy in occupancy_table[index].
    std::array<Bitboard, isBishop ? 512 : 4096> attack_table{};
    fill_attack_table_from_occupancy<isBishop>(position_of_figure, occupancy_table, attack_table);

    if (MagicNumber value1; generate_magic_number<isBishop>(mask, relevant_bits_in_mask, number_of_masks,
                                                            occupancy_table, attack_table, value1)) {
        return value1;
    }

    fmt::print("no magic number found\n");
    return 0;
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


int main() {
    compute_magic_numbers();

    return 0;
}
