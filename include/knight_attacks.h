//
// Created by peter on 01/12/2024.
//

#ifndef KNIGHT_ATTACKS_H
#define KNIGHT_ATTACKS_H
#include <array>

#include "bitboard.h"

namespace Constants {
    /**
     * An array representing pre-computed attack bitboards for a knight on each square of a standard 8x8 chessboard.
     *
     * Each index of the array corresponds to a square on the chessboard where the knight might reside,
     * and the value at each index is a 64-bit integer (Bitboard) that represents all possible squares
     * the knight can attack from that position. The attack pattern reflects the L-shaped moves a knight
     * can make, which can potentially cover up to eight different squares.
     *
     * The value at each index is a bitboard, a 64-bit unsigned long long (ULL), where each bit
     * represents a square on the chessboard. A set bit (1) indicates that the square can be attacked
     * by a knight from the position corresponding to the index.
     *
     * The board squares are indexed from 0 to 63, starting from A1 to H1, then A2 to H2, and so on
     * up to A8 to H8.
     */
    static constexpr std::array<Bitboard,64> knight_attacks = { /*
            A  B  C  D  E  F  G  H
        1   0  0  0  0  0  0  0  0
        2   0  0  1  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        8   0  0  0  0  0  0  0  0

           bitboard as 64 bit integer: */
        132096ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  0  0  0
     3   1  0  1  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        329728ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   1  0  0  0  1  0  0  0
     3   0  1  0  1  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        659712ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  0  1  0  0
     3   0  0  1  0  1  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        1319424ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  0  0  1  0
     3   0  0  0  1  0  1  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2638848ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  0  0  1
     3   0  0  0  0  1  0  1  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        5277696ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  1  0  0  0
     3   0  0  0  0  0  1  0  1
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        10489856ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  1  0  0
     3   0  0  0  0  0  0  1  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        4202496ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  1  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  1  0  0  0  0  0
     4   0  1  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        33816580ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  1  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  1  0  0  0  0
     4   1  0  1  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        84410376ULL,
 /*
         A  B  C  D  E  F  G  H
     1   1  0  0  0  1  0  0  0
     2   0  0  0  0  0  0  0  0
     3   1  0  0  0  1  0  0  0
     4   0  1  0  1  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        168886289ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  1  0  0  0  1  0  0
     2   0  0  0  0  0  0  0  0
     3   0  1  0  0  0  1  0  0
     4   0  0  1  0  1  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        337772578ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  1  0  0  0  1  0
     2   0  0  0  0  0  0  0  0
     3   0  0  1  0  0  0  1  0
     4   0  0  0  1  0  1  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        675545156ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  1  0  0  0  1
     2   0  0  0  0  0  0  0  0
     3   0  0  0  1  0  0  0  1
     4   0  0  0  0  1  0  1  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        1351090312ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  1  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  1  0  0  0
     4   0  0  0  0  0  1  0  1
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2685403152ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  1  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  1  0  0
     4   0  0  0  0  0  0  1  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        1075839008ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  1  0  0  0  0  0  0
     2   0  0  1  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  1  0  0  0  0  0
     5   0  1  0  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        8657044482ULL,
 /*
         A  B  C  D  E  F  G  H
     1   1  0  1  0  0  0  0  0
     2   0  0  0  1  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  1  0  0  0  0
     5   1  0  1  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        21609056261ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  1  0  1  0  0  0  0
     2   1  0  0  0  1  0  0  0
     3   0  0  0  0  0  0  0  0
     4   1  0  0  0  1  0  0  0
     5   0  1  0  1  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        43234889994ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  1  0  1  0  0  0
     2   0  1  0  0  0  1  0  0
     3   0  0  0  0  0  0  0  0
     4   0  1  0  0  0  1  0  0
     5   0  0  1  0  1  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        86469779988ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  1  0  1  0  0
     2   0  0  1  0  0  0  1  0
     3   0  0  0  0  0  0  0  0
     4   0  0  1  0  0  0  1  0
     5   0  0  0  1  0  1  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        172939559976ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  1  0  1  0
     2   0  0  0  1  0  0  0  1
     3   0  0  0  0  0  0  0  0
     4   0  0  0  1  0  0  0  1
     5   0  0  0  0  1  0  1  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        345879119952ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  1  0  1
     2   0  0  0  0  1  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  1  0  0  0
     5   0  0  0  0  0  1  0  1
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        687463207072ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  1  0
     2   0  0  0  0  0  1  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  1  0  0
     5   0  0  0  0  0  0  1  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        275414786112ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  0  0  0  0
     3   0  0  1  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  1  0  0  0  0  0
     6   0  1  0  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2216203387392ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   1  0  1  0  0  0  0  0
     3   0  0  0  1  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  1  0  0  0  0
     6   1  0  1  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        5531918402816ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  1  0  0  0  0
     3   1  0  0  0  1  0  0  0
     4   0  0  0  0  0  0  0  0
     5   1  0  0  0  1  0  0  0
     6   0  1  0  1  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        11068131838464ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  1  0  0  0
     3   0  1  0  0  0  1  0  0
     4   0  0  0  0  0  0  0  0
     5   0  1  0  0  0  1  0  0
     6   0  0  1  0  1  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        22136263676928ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  1  0  0
     3   0  0  1  0  0  0  1  0
     4   0  0  0  0  0  0  0  0
     5   0  0  1  0  0  0  1  0
     6   0  0  0  1  0  1  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        44272527353856ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  1  0  1  0
     3   0  0  0  1  0  0  0  1
     4   0  0  0  0  0  0  0  0
     5   0  0  0  1  0  0  0  1
     6   0  0  0  0  1  0  1  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        88545054707712ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  1  0  1
     3   0  0  0  0  1  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  1  0  0  0
     6   0  0  0  0  0  1  0  1
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        175990581010432ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  1  0
     3   0  0  0  0  0  1  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  1  0  0
     6   0  0  0  0  0  0  1  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        70506185244672ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  1  0  0  0  0  0  0
     4   0  0  1  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  1  0  0  0  0  0
     7   0  1  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        567348067172352ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   1  0  1  0  0  0  0  0
     4   0  0  0  1  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  1  0  0  0  0
     7   1  0  1  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        1416171111120896ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  1  0  1  0  0  0  0
     4   1  0  0  0  1  0  0  0
     5   0  0  0  0  0  0  0  0
     6   1  0  0  0  1  0  0  0
     7   0  1  0  1  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2833441750646784ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  1  0  1  0  0  0
     4   0  1  0  0  0  1  0  0
     5   0  0  0  0  0  0  0  0
     6   0  1  0  0  0  1  0  0
     7   0  0  1  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        5666883501293568ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  1  0  1  0  0
     4   0  0  1  0  0  0  1  0
     5   0  0  0  0  0  0  0  0
     6   0  0  1  0  0  0  1  0
     7   0  0  0  1  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        11333767002587136ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  1  0  1  0
     4   0  0  0  1  0  0  0  1
     5   0  0  0  0  0  0  0  0
     6   0  0  0  1  0  0  0  1
     7   0  0  0  0  1  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        22667534005174272ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  1  0  1
     4   0  0  0  0  1  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  1  0  0  0
     7   0  0  0  0  0  1  0  1
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        45053588738670592ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  1  0
     4   0  0  0  0  0  1  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  1  0  0
     7   0  0  0  0  0  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        18049583422636032ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  1  0  0  0  0  0  0
     5   0  0  1  0  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  1  0  0  0  0  0
     8   0  1  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        145241105196122112ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   1  0  1  0  0  0  0  0
     5   0  0  0  1  0  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  1  0  0  0  0
     8   1  0  1  0  0  0  0  0

        bitboard as 64 bit integer: */
        362539804446949376ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  1  0  1  0  0  0  0
     5   1  0  0  0  1  0  0  0
     6   0  0  0  0  0  0  0  0
     7   1  0  0  0  1  0  0  0
     8   0  1  0  1  0  0  0  0

        bitboard as 64 bit integer: */
        725361088165576704ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  1  0  1  0  0  0
     5   0  1  0  0  0  1  0  0
     6   0  0  0  0  0  0  0  0
     7   0  1  0  0  0  1  0  0
     8   0  0  1  0  1  0  0  0

        bitboard as 64 bit integer: */
        1450722176331153408ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  1  0  1  0  0
     5   0  0  1  0  0  0  1  0
     6   0  0  0  0  0  0  0  0
     7   0  0  1  0  0  0  1  0
     8   0  0  0  1  0  1  0  0

        bitboard as 64 bit integer: */
        2901444352662306816ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  1  0  1  0
     5   0  0  0  1  0  0  0  1
     6   0  0  0  0  0  0  0  0
     7   0  0  0  1  0  0  0  1
     8   0  0  0  0  1  0  1  0

        bitboard as 64 bit integer: */
        5802888705324613632ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  1  0  1
     5   0  0  0  0  1  0  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  1  0  0  0
     8   0  0  0  0  0  1  0  1

        bitboard as 64 bit integer: */
        11533718717099671552ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  1  0
     5   0  0  0  0  0  1  0  0
     6   0  0  0  0  0  0  0  0
     7   0  0  0  0  0  1  0  0
     8   0  0  0  0  0  0  1  0

        bitboard as 64 bit integer: */
        4620693356194824192ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  1  0  0  0  0  0  0
     6   0  0  1  0  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  1  0  0  0  0  0

        bitboard as 64 bit integer: */
        288234782788157440ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   1  0  1  0  0  0  0  0
     6   0  0  0  1  0  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  1  0  0  0  0

        bitboard as 64 bit integer: */
        576469569871282176ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  1  0  1  0  0  0  0
     6   1  0  0  0  1  0  0  0
     7   0  0  0  0  0  0  0  0
     8   1  0  0  0  1  0  0  0

        bitboard as 64 bit integer: */
        1224997833292120064ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  1  0  1  0  0  0
     6   0  1  0  0  0  1  0  0
     7   0  0  0  0  0  0  0  0
     8   0  1  0  0  0  1  0  0

        bitboard as 64 bit integer: */
        2449995666584240128ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  1  0  1  0  0
     6   0  0  1  0  0  0  1  0
     7   0  0  0  0  0  0  0  0
     8   0  0  1  0  0  0  1  0

        bitboard as 64 bit integer: */
        4899991333168480256ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  1  0  1  0
     6   0  0  0  1  0  0  0  1
     7   0  0  0  0  0  0  0  0
     8   0  0  0  1  0  0  0  1

        bitboard as 64 bit integer: */
        9799982666336960512ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  1  0  1
     6   0  0  0  0  1  0  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  1  0  0  0

        bitboard as 64 bit integer: */
        1152939783987658752ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  1  0
     6   0  0  0  0  0  1  0  0
     7   0  0  0  0  0  0  0  0
     8   0  0  0  0  0  1  0  0

        bitboard as 64 bit integer: */
        2305878468463689728ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  1  0  0  0  0  0  0
     7   0  0  1  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        1128098930098176ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   1  0  1  0  0  0  0  0
     7   0  0  0  1  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2257297371824128ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  1  0  1  0  0  0  0
     7   1  0  0  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        4796069720358912ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  1  0  1  0  0  0
     7   0  1  0  0  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        9592139440717824ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  1  0  1  0  0
     7   0  0  1  0  0  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        19184278881435648ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  1  0  1  0
     7   0  0  0  1  0  0  0  1
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        38368557762871296ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  1  0  1
     7   0  0  0  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        4679521487814656ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  0  0
     3   0  0  0  0  0  0  0  0
     4   0  0  0  0  0  0  0  0
     5   0  0  0  0  0  0  0  0
     6   0  0  0  0  0  0  1  0
     7   0  0  0  0  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        9077567998918656ULL
 };
}
#endif //KNIGHT_ATTACKS_H
