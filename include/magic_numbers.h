//
// Created by peter on 15/12/2024.
//

#ifndef MAGIC_NUMBERS_H
#define MAGIC_NUMBERS_H


#include <fmt/base.h>                      // for print
#include <algorithm>                       // for for_each
#include <array>                           // for array
#include <cstdint>                         // for int64_t, uint64_t
#include <iostream>
#include <ostream>
#include <utility>                         // for to_underlying
#include "attack_masks.h"                  // for bishop_attack_masks
#include "bitboard.h"                      // for Bitboard, Bitcount, Position
#include "create_possible_slider_moves.h"

namespace Constants {
    using MagicNumber = uint64_t;

    constexpr std::array<MagicNumber, 64> Rook_Magic_Numbers = {
        /* magic number found for A1: */ 0x2280002080c00112,
        /* magic number found for B1: */ 0x144002442001d000,
        /* magic number found for C1: */ 0x100104020010008,
        /* magic number found for D1: */ 0x480080080041000,
        /* magic number found for E1: */ 0x8200100820040200,
        /* magic number found for F1: */ 0x500080100020400,
        /* magic number found for G1: */ 0x280008001000200,
        /* magic number found for H1: */ 0x1100006382104100,
        /* magic number found for A2: */ 0xc1002041008000,
        /* magic number found for B2: */ 0x11002100400094,
        /* magic number found for C2: */ 0x200801000802000,
        /* magic number found for D2: */ 0x808010000800,
        /* magic number found for E2: */ 0x4200800800800402,
        /* magic number found for F2: */ 0x100800200040080,
        /* magic number found for G2: */ 0x10400082204b001,
        /* magic number found for H2: */ 0x2402000062008401,
        /* magic number found for A3: */ 0x400288000400088,
        /* magic number found for B3: */ 0x1010004000402010,
        /* magic number found for C3: */ 0x5880970041002000,
        /* magic number found for D3: */ 0x420008220012,
        /* magic number found for E3: */ 0x6300050011000800,
        /* magic number found for F3: */ 0xc1010002080400,
        /* magic number found for G3: */ 0x20040001900208,
        /* magic number found for H3: */ 0x20000806114,
        /* magic number found for A4: */ 0x10420a00210080,
        /* magic number found for B4: */ 0x200080804000,
        /* magic number found for C4: */ 0x848420200102280,
        /* magic number found for D4: */ 0x4030100080080084,
        /* magic number found for E4: */ 0x1060080080040080,
        /* magic number found for F4: */ 0x448040080020080,
        /* magic number found for G4: */ 0x12000200010884,
        /* magic number found for H4: */ 0x2043000100004082,
        /* magic number found for A5: */ 0x400080800020,
        /* magic number found for B5: */ 0x1060824001802000,
        /* magic number found for C5: */ 0x6020084101002010,
        /* magic number found for D5: */ 0x201001000901,
        /* magic number found for E5: */ 0x2004000801010010,
        /* magic number found for F5: */ 0x801001803000400,
        /* magic number found for G5: */ 0xb0110020400a801,
        /* magic number found for H5: */ 0x100000408a001104,
        /* magic number found for A6: */ 0x400800040008028,
        /* magic number found for B6: */ 0x402010024000,
        /* magic number found for C6: */ 0x200010008080,
        /* magic number found for D6: */ 0x1000100008008080,
        /* magic number found for E6: */ 0x8001000408010011,
        /* magic number found for F6: */ 0x2001001400090042,
        /* magic number found for G6: */ 0x804100188040002,
        /* magic number found for H6: */ 0xa0004400820001,
        /* magic number found for A7: */ 0x100804022010200,
        /* magic number found for B7: */ 0x820100402200,
        /* magic number found for C7: */ 0x1c181200e100080,
        /* magic number found for D7: */ 0x100408210100,
        /* magic number found for E7: */ 0x4088000804008080,
        /* magic number found for F7: */ 0x1008800200040080,
        /* magic number found for G7: */ 0x4080080210010400,
        /* magic number found for H7: */ 0x4000008444010600,
        /* magic number found for A8: */ 0x210040120082,
        /* magic number found for B8: */ 0x610880b620400503,
        /* magic number found for C8: */ 0x2460008a0409082,
        /* magic number found for D8: */ 0x40b0300100086015,
        /* magic number found for E8: */ 0x108200a088100402,
        /* magic number found for F8: */ 0x820a001004080102,
        /* magic number found for G8: */ 0x82001084510802,
        /* magic number found for H8: */ 0x9611084014622
    };

    constexpr std::array<MagicNumber, 64> Bishop_Magic_Numbers = {
        /* magic number found for A1: */ 0x50020228002100,
        /* magic number found for B1: */ 0x180c100492228000,
        /* magic number found for C1: */ 0x8086840810002,
        /* magic number found for D1: */ 0x4004040086180000,
        /* magic number found for E1: */ 0x1104000001200,
        /* magic number found for F1: */ 0x80020a82200080e0,
        /* magic number found for G1: */ 0x2040a0812294200,
        /* magic number found for H1: */ 0x2809002084044006,
        /* magic number found for A2: */ 0x980051010120882,
        /* magic number found for B2: */ 0x5441094004084,
        /* magic number found for C2: */ 0x1400500c08802004,
        /* magic number found for D2: */ 0x8091044502000001,
        /* magic number found for E2: */ 0xa0000202110080a0,
        /* magic number found for F2: */ 0x1404009010080180,
        /* magic number found for G2: */ 0x4e0020082201037,
        /* magic number found for H2: */ 0x620020082011088,
        /* magic number found for A3: */ 0x41003a00310010d,
        /* magic number found for B3: */ 0x8804100208020c08,
        /* magic number found for C3: */ 0x828001000401920,
        /* magic number found for D3: */ 0x2084012044108004,
        /* magic number found for E3: */ 0x2002004401210018,
        /* magic number found for F3: */ 0x81000290009011,
        /* magic number found for G3: */ 0x910c080101284204,
        /* magic number found for H3: */ 0x1100221a82080220,
        /* magic number found for A4: */ 0x20202008020440,
        /* magic number found for B4: */ 0x101480850029800,
        /* magic number found for C4: */ 0x8a00901008004210,
        /* magic number found for D4: */ 0x40404000c410200,
        /* magic number found for E4: */ 0x50900102b004011,
        /* magic number found for F4: */ 0x290004080241000,
        /* magic number found for G4: */ 0x208080810c1080,
        /* magic number found for H4: */ 0x4008800260528,
        /* magic number found for A5: */ 0x4488024340280804,
        /* magic number found for B5: */ 0x84028201081000,
        /* magic number found for C5: */ 0x201424040081201,
        /* magic number found for D5: */ 0x40020080180080,
        /* magic number found for E5: */ 0x4010010040040,
        /* magic number found for F5: */ 0x1100100008042,
        /* magic number found for G5: */ 0x102440100c04804,
        /* magic number found for H5: */ 0x8030244031242,
        /* magic number found for A6: */ 0x4821002a0100800,
        /* magic number found for B6: */ 0x8202151120820800,
        /* magic number found for C6: */ 0x2002001404102206,
        /* magic number found for D6: */ 0x12a104010400200,
        /* magic number found for E6: */ 0x2002082101001010,
        /* magic number found for F6: */ 0x2100200240200,
        /* magic number found for G6: */ 0x14080801210640,
        /* magic number found for H6: */ 0x1280108483100,
        /* magic number found for A7: */ 0x2002210420840780,
        /* magic number found for B7: */ 0x208c04204084,
        /* magic number found for C7: */ 0x620010080900020,
        /* magic number found for D7: */ 0x400084020880200,
        /* magic number found for E7: */ 0x2002442010,
        /* magic number found for F7: */ 0x2040428420411,
        /* magic number found for G7: */ 0x4240509440899080,
        /* magic number found for H7: */ 0x6820020450408140,
        /* magic number found for A8: */ 0x6001008061201004,
        /* magic number found for B8: */ 0x2604010401010800,
        /* magic number found for C8: */ 0x4008202842109044,
        /* magic number found for D8: */ 0xa82a0800,
        /* magic number found for E8: */ 0x4401010505040,
        /* magic number found for F8: */ 0x2006c020a2320208,
        /* magic number found for G8: */ 0x8a408a084240048,
        /* magic number found for H8: */ 0x4004200204460880
    };

    namespace Impl {
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
         * for a chess piece, determined by whether the piece is a bishop or not.
         *
         * \param mask A bitboard that represents the areas of the board considered for occupancy.
         * \param occupancy_table An array used to store all possible occupancy bitboards generated
         *        based on the given mask.
         */
        constexpr void populate_occupancy_with_mask(const Bitboard mask,
                                          std::array<Bitboard, slider == Slider::bishop
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
         * for each possible occupancy. Depending on whether the figure is a bishop or rook,
         * the method uses appropriate move generation functions.
         *
         * \tparam isBishop Boolean value indicating whether the figure is a bishop (true) or a rook (false).
         * \param position_of_figure The position of the figure on the board.
         * \param occupancy_table A precomputed table of all possible occupancies for the relevant squares.
         * \param attack_table A table that will be populated with the possible attack bitboards for the given occupancies.
         */
        constexpr void fill_attack_table_from_occupancy(const Position position_of_figure,
                                              const std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> &occupancy_table,
                                              std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> &attack_table) {
            typename std::array<Bitboard, slider == Slider::bishop ? 512 : 4096>::size_type index = 0;
            for (auto &attack: attack_table) {
                // compute the attacks corresponding to index given occupancy.
                attack = create_possible_slider_moves<slider>(occupancy_table[index], position_of_figure);
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
        void reset_used_attack_table(std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> used_attack_table) {
            // set the array used_attack_table to zero. We need it to check if we have a
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
                                           const unsigned long number_of_occupancies,
                                           std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> occupancy_table,
                                           std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> attack_table,
                                           std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> used_attack_table,
                                           MagicNumber magic_number) {
            for (std::size_t index = 0; index < number_of_occupancies; index++) {

                Bitboard magic_index = occupancy_table[index] * magic_number >> (64 - relevant_bits_in_mask);

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
         * for a given chess piece (bishop or rook). The process continues until a valid
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
                                   const unsigned long number_of_occupancies,
                                   const std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> &occupancy_table,
                                   const std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> &attack_table,
                                   MagicNumber &value1) {
            std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> used_attack_table{};

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
        MagicNumber find_magic_number(const Position position_of_figure) {
            // get the mask corresponding to the position of the figure.
            const Bitboard mask = slider == Slider::bishop
                                      ? Constants::bishop_attack_masks[std::to_underlying(position_of_figure)]
                                      : Constants::rook_attack_masks[std::to_underlying(position_of_figure)];

            // compute the size of the mask
            const int64_t relevant_bits_in_mask = Bitcount(mask);

            // compute the number of positions that can be created within the given mask.
            const auto number_of_occupancies = 1UL << relevant_bits_in_mask;

            // holds every possible occupation within mask
            std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> occupancy_table{};
            populate_occupancy_with_mask<slider>(mask, occupancy_table);

            // a bit in attack_table[index] is set iff the figure in question can attack it given the
            // occupancy in occupancy_table[index].
            std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> attack_table{};
            fill_attack_table_from_occupancy<slider>(position_of_figure, occupancy_table, attack_table);

            if (MagicNumber value1; generate_magic_number<slider>(mask, relevant_bits_in_mask, number_of_occupancies,
                                                                    occupancy_table, attack_table, value1)) {
                return value1;
            }

            fmt::print("no magic number found\n");
            return 0;
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
}

#endif //MAGIC_NUMBERS_H
