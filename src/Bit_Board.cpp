// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


#include "Bit_Board.h"
#include <print>
#include <array>       // for array


/**
 * print a bitboard
 *    - as an 8 x 8 square of binaries and
 *    - as a 64 bit unsigned integer
 */
void print_bitboard(const Bitboard bitboard) {
    std::print("{}\n", format_bitboard(bitboard));
}

std::string format_square(const Square position) {
    // An example of using a look-up table
    static const std::array<std::string, 64> position_table = {
        "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1",
        "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2",
        "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3",
        "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4",
        "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5",
        "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6",
        "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7",
        "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8"
    };

    return position_table[std::to_underlying(position)];
}
