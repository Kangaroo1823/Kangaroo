//
// Created by peter on 01/12/2024.
//

#include <iostream>

#include "bitboard.h"


/**
 * print a bitboard
 *    - as an 8 x 8 square of binaries and
 *    - as a 64 bit unsigned integer
 */
void print_bitboard(const Bitboard bitboard) {

    std::cout << "/*" << std::endl;

    for (int rank = 7; rank >= 0 ; rank--) {
        std::cout << "    " << rank + 1 << "  ";
        for (int file = 0; file < 8 ; file++) {
            if (bitboard & (1ULL << rank * 8 + file)) {
                std::cout << " 1 ";
            } else {
                std::cout << " 0 ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "        A  B  C  D  E  F  G  H" << std::endl;
    std::cout << std::endl;
    std::cout << "       " << "bitboard as 64 bit integer: */" << std::endl;
    std::cout << "       " << bitboard << "ULL," << std::endl;
}

std::string print_position(const Position position) {
    switch (position) {
        case A1: return "A1";
        case B1: return "B1";
        case C1: return "C1";
        case D1: return "D1";
        case E1: return "E1";
        case F1: return "F1";
        case G1: return "G1";
        case H1: return "H1";
        case A2: return "A2";
        case B2: return "B2";
        case C2: return "C2";
        case D2: return "D2";
        case E2: return "E2";
        case F2: return "F2";
        case G2: return "G2";
        case H2: return "H2";
        case A3: return "A3";
        case B3: return "B3";
        case C3: return "C3";
        case D3: return "D3";
        case E3: return "E3";
        case F3: return "F3";
        case G3: return "G3";
        case H3: return "H3";
        case A4: return "A4";
        case B4: return "B4";
        case C4: return "C4";
        case D4: return "D4";
        case E4: return "E4";
        case F4: return "F4";
        case G4: return "G4";
        case H4: return "H4";
        case A5: return "A5";
        case B5: return "B5";
        case C5: return "C5";
        case D5: return "D5";
        case E5: return "E5";
        case F5: return "F5";
        case G5: return "G5";
        case H5: return "H5";
        case A6: return "A6";
        case B6: return "B6";
        case C6: return "C6";
        case D6: return "D6";
        case E6: return "E6";
        case F6: return "F6";
        case G6: return "G6";
        case H6: return "H6";
        case A7: return "A7";
        case B7: return "B7";
        case C7: return "C7";
        case D7: return "D7";
        case E7: return "E7";
        case F7: return "F7";
        case G7: return "G7";
        case H7: return "H7";
        case A8: return "A8";
        case B8: return "B8";
        case C8: return "C8";
        case D8: return "D8";
        case E8: return "E8";
        case F8: return "F8";
        case G8: return "G8";
        case H8: return "H8";
        default: return "unknown";

    }
}