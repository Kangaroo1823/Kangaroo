//
// Created by peter on 15/12/2024.
//

#ifndef MAGIC_NUMBERS_H
#define MAGIC_NUMBERS_H


#include <algorithm>                       // for for_each
#include <array>                           // for array
#include <cstdint>                         // for int64_t, uint64_t
#include <utility>
#include <print>


#include "../include/bitboard.h"
#include "create_possible_slider_moves.h"
#include "../include/types.h"
#include "constants_masks.h"


namespace Constants::Impl {
    /**
     * \brief computes a candidate that can be used for hashing
     */
    MagicNumber magic_candidate(Bitboard occupation);


    template<Slider slider>
    /**
     * \brief Populates the occupancy table with all possible occupancies derived from the given mask.
     *
     * This function iterates through the provided occupancy table and fills it with bitboards
     * representing possible occupancies using the specified mask. The occupancy values are computed
     * using the mask and an index that corresponds to bit combinations forming unique occupancies
     * for a chess piece, determined by whether the piece is a Bishop or not.
     *
     * \param mask A bitboard that represents the areas of the board considered for occupancy.
     * \param occupancy_table An array used to store all possible occupancy bitboards generated
     *        based on the given mask.
     */
    constexpr void populate_occupancy_with_mask(const Bitboard mask,
                                                std::array<Bitboard, slider == Slider::Bishop
                                                                         ? 512
                                                                         : 4096> &occupancy_table) {
        std::size_t index = 0;
        for (auto &occupancy: occupancy_table) {
            occupancy = create_occupancy_from_mask(index, mask);

            ++index;
        }
    }

    template<Slider slider>
    /**
     * \brief Fills the attack table based on the occupancy table and the position of the figure.
     *
     * Iterates through the occupancy and attack tables, generating attack bitboards
     * for each possible occupancy. Depending on whether the figure is a Bishop or Rook,
     * the method uses appropriate move generation functions.
     *
     * \tparam isBishop Boolean value indicating whether the figure is a bishop (true) or a rook (false).
     * \param position_of_figure The position of the figure on the board.
     * \param occupancy_table A precomputed table of all possible occupancies for the relevant squares.
     * \param attack_table A table that will be populated with the possible attack bitboards for the given occupancies.
     */
    constexpr void fill_attack_table_from_occupancy(const Square position_of_figure,
                                                    const std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> &
                                                    occupancy_table,
                                                    std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> &
                                                    attack_table) {
        typename std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096>::size_type index = 0;
        for (auto &attack: attack_table) {
            // compute the attacks corresponding to index given occupancy.
            attack = Kangaroo::create_possible_slider_moves<slider>(occupancy_table[index], position_of_figure);
            ++index;
        }
    }


    template<Slider slider>
    /**
     * \brief Resets the provided used attack table by setting all elements to zero.
     *
     * This function is used to clear the contents of the used attack table to allow for
     * collision checking using a magic number.
     *
     * \param used_attack_table The array representing the used attack table. The size of the array
     * depends on whether it is for bishops (512) or rooks (4096).
     */
    void reset_used_attack_table(std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> used_attack_table) {
        // set the array used_attack_table to zero. We need it to check_p if we have a
        // collision using magic_number.
        std::ranges::for_each(used_attack_table, [](auto &i) { i = 0; });
    }

    template<Slider slider>
    /**
     * \brief Checks for collisions when applying a magic number to a set of occupancy and attack tables.
     *
     * This function applies a given magic number to occupancy values in the table and verifies that the
     * resulting mapped values in the `used_attack_table` do not collide with entries in the `attack_table`.
     *
     * \param relevant_bits_in_mask The number of bits in the mask relevant for the magic number computation.
     * \param number_of_occupancies The total number of masks in the occupancy and attack tables.
     * \param occupancy_table Stores occupancy configurations for a given piece.
     * \param attack_table Stores attack patterns corresponding to the occupancy configurations.
     * \param used_attack_table A table to track mappings created by the magic number.
     * \param magic_number The candidate magic number being tested for collisions.
     * \return True if there are no collisions using the magic number, false otherwise.
     */
    bool check_magic_number_collisions(const int64_t relevant_bits_in_mask,
                                       const std::size_t number_of_occupancies,
                                       std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> occupancy_table,
                                       std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> attack_table,
                                       std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> used_attack_table,
                                       MagicNumber magic_number) {
        for (std::size_t index = 0; index < number_of_occupancies; index++) {
            Bitboard magic_index = (occupancy_table[index] * magic_number) >> (64 - relevant_bits_in_mask);

            if (used_attack_table[magic_index] == 0) {
                used_attack_table[magic_index] = attack_table[index];
            } else if (used_attack_table[magic_index] != attack_table[index]) {
                return false;
            }
        }

        return true;
    }


    template<Slider slider>
    /**
     * \brief Attempts to generate a magic number for optimizing chess move lookup.
     *
     * This function brute-forces the generation of a magic number by validating candidates
     * against constraints such as avoiding collisions in occupancy and attack tables
     * for a given chess piece (Bishop or Rook). The process continues until a valid
     * magic number is found or the search limit is exceeded.
     *
     * \tparam isBishop Determines if the function is generating a magic number for a bishop (true) or rook (false).
     * \param mask The bitboard mask representing possible movements restricted by the relevant piece's position.
     * \param relevant_bits_in_mask Number of relevant bits in the given \p mask.
     * \param number_of_occupancies The number of possible occupancy variations based on \p mask.
     * \param occupancy_table Lookup table containing all potential occupancies derived from \p mask.
     * \param attack_table Lookup table containing precomputed attacks for each possible occupancy.
     * \param value1 Reference to store the resulting magic number if successfully generated.
     * \return True if a valid magic number is found; otherwise, false.
     */
    bool generate_magic_number(const Bitboard mask, const int64_t relevant_bits_in_mask,
                               const std::size_t number_of_occupancies,
                               const std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> &occupancy_table,
                               const std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> &attack_table,
                               MagicNumber &value1) {
        std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> used_attack_table{};

        // the aim of the following loop is to find a magic number that works.
        // We do this brute force! get a candidate and see whether it works, i.e, there
        // are no collisions when using it.
        for (int magic_candidate_number = 0;
             magic_candidate_number < 1000000000; magic_candidate_number++) {
            MagicNumber magic_number = magic_candidate(mask);

            reset_used_attack_table<slider>(used_attack_table);

            const bool success = check_magic_number_collisions<slider>(
                relevant_bits_in_mask, number_of_occupancies,
                occupancy_table, attack_table,
                used_attack_table, magic_number);

            // if magic number works
            if (success) {
                // return it
                value1 = magic_number;
                return true;
            }
        }
        return false;
    }

    template<Slider slider>
    /**
     * \brief Finds a magic number for the specified position of a figure.
     *
     * Computes a magic number used for hashing chessboard states based on the given position.
     * The function determines relevant mask bits, all possible occupancy values within the mask,
     * and fills corresponding attack tables for the figure type. It attempts to generate and
     * return a valid magic number using a heuristic approach. If no magic number is found,
     * it returns 0.
     *
     * \param position_of_figure The position of the chess piece on the board.
     * \return The computed magic number or 0 if no valid number is found.
     */
    MagicNumber find_magic_number(const Square position_of_figure) {
        // get the mask corresponding to the position of the figure.
        const Bitboard mask = slider == Slider::Bishop
                                  ? Constants::bishop_attack_masks[std::to_underlying(position_of_figure)]
                                  : Constants::rook_attack_masks[std::to_underlying(position_of_figure)];

        // compute the size of the mask
        const int64_t relevant_bits_in_mask = Bitcount(mask);

        // compute the number of positions that can be created within the given mask.
        const std::size_t number_of_occupancies =
                static_cast<std::size_t>(1) << static_cast<std::size_t>(relevant_bits_in_mask);

        // holds every possible occupation within mask
        std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> occupancy_table{};
        populate_occupancy_with_mask<slider>(mask, occupancy_table);

        // a bit in attack_table[index] is set iff the figure in question can attack it given the
        // occupancy in occupancy_table[index].
        std::array<Bitboard, slider == Slider::Bishop ? 512 : 4096> attack_table{};
        fill_attack_table_from_occupancy<slider>(position_of_figure, occupancy_table, attack_table);

        if (MagicNumber value1; generate_magic_number<slider>(mask, relevant_bits_in_mask, number_of_occupancies,
                                                              occupancy_table, attack_table, value1)) {
            return value1;
        }

        std::print("no magic number found\n");
        return 0;
    }

    template<Slider slider>
    std::array<MagicNumber, 64> find_magic_numbers_for() {
        std::array<MagicNumber, 64> magic_numbers{};
        for (std::size_t i = 0; i < 64; i++) {
            magic_numbers[i] = find_magic_number<slider>(static_cast<Square>(i));
        }
        return magic_numbers;
    }

    /**
     * \brief Computes and prints magic numbers for positions on a chessboard.
     *
     * This method iterates over all 64 squares of a chessboard and computes magic numbers
     * for both rooks and bishops using the `find_magic_number` function. The results are
     * formatted and printed for each square.
     */
    void compute_magic_numbers();
}


#endif //MAGIC_NUMBERS_H
