//
// Created by peter on 02/12/2024.
//

#ifndef QUEEN_ATTACK_MASKS_H
#define QUEEN_ATTACK_MASKS_H
#include <array>

#include "bitboard.h"

namespace Constants {
    /**
     * @brief Array of 64-bit integers where a bit is set (1) iff a figure there
     * restricts movement of the queen.
     *
     * The array has 64 elements and is indexed by the position of the queen on
     * an otherwise empty chess board. At index 0 it is assumed that the queen is on
     * the square A1, at index 7 the queen is assumed to be at index H1, at index 8
     * the queen is at A2, etc.
     *
     * The array is composed of 64-bit unsigned integers. Each bit represents a
     * square of the chess board. If the bit is set (1), it states that another figure
     * at the corresponding square might block further movement of the queen. It is
     * assumed that the queen can capture the figure, but cannot go any further in
     * the direction.
     *
     * Otherwise, if a figure at that position does not prevent the queen from going
     * further in the direction or the queen cannot go there at all the corresponding
     * bit is unset (0).
     */
    static constexpr std::array<Bitboard,64> Queen_Attack_Masks = {
        /*
            A  B  C  D  E  F  G  H
        1   0  1  1  1  1  1  1  0
        2   1  1  0  0  0  0  0  0
        3   1  0  1  0  0  0  0  0
        4   1  0  0  1  0  0  0  0
        5   1  0  0  0  1  0  0  0
        6   1  0  0  0  0  1  0  0
        7   1  0  0  0  0  0  1  0
        8   0  0  0  0  0  0  0  0

           bitboard as 64 bit integer: */
        18332230535676798ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  1  1  1  1  1  0
     2   0  1  1  0  0  0  0  0
     3   0  1  0  1  0  0  0  0
     4   0  1  0  0  1  0  0  0
     5   0  1  0  0  0  1  0  0
     6   0  1  0  0  0  0  1  0
     7   0  1  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        635664052389500ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  1  0  1  1  1  1  0
     2   0  1  1  1  0  0  0  0
     3   0  0  1  0  1  0  0  0
     4   0  0  1  0  0  1  0  0
     5   0  0  1  0  0  0  1  0
     6   0  0  1  0  0  0  0  0
     7   0  0  1  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        1130590616424058ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  1  1  0  1  1  1  0
     2   0  0  1  1  1  0  0  0
     3   0  1  0  1  0  1  0  0
     4   0  0  0  1  0  0  1  0
     5   0  0  0  1  0  0  0  0
     6   0  0  0  1  0  0  0  0
     7   0  0  0  1  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2260631477165174ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  1  1  1  0  1  1  0
     2   0  0  0  1  1  1  0  0
     3   0  0  1  0  1  0  1  0
     4   0  1  0  0  1  0  0  0
     5   0  0  0  0  1  0  0  0
     6   0  0  0  0  1  0  0  0
     7   0  0  0  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        4521260840401006ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  1  1  1  1  0  1  0
     2   0  0  0  0  1  1  1  0
     3   0  0  0  1  0  1  0  0
     4   0  0  1  0  0  1  0  0
     5   0  1  0  0  0  1  0  0
     6   0  0  0  0  0  1  0  0
     7   0  0  0  0  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        9042530262347870ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  1  1  1  1  1  0  0
     2   0  0  0  0  0  1  1  0
     3   0  0  0  0  1  0  1  0
     4   0  0  0  1  0  0  1  0
     5   0  0  1  0  0  0  1  0
     6   0  1  0  0  0  0  1  0
     7   0  0  0  0  0  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        18087259547918398ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  1  1  1  1  1  1  0
     2   0  0  0  0  0  0  1  1
     3   0  0  0  0  0  1  0  1
     4   0  0  0  0  1  0  0  1
     5   0  0  0  1  0  0  0  1
     6   0  0  1  0  0  0  0  1
     7   0  1  0  0  0  0  0  1
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        36737469049258110ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  1  1  1  1  1  0
     3   1  1  0  0  0  0  0  0
     4   1  0  1  0  0  0  0  0
     5   1  0  0  1  0  0  0  0
     6   1  0  0  0  1  0  0  0
     7   1  0  0  0  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        9307404667944448ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  1  1  1  1  0
     3   0  1  1  0  0  0  0  0
     4   0  1  0  1  0  0  0  0
     5   0  1  0  0  1  0  0  0
     6   0  1  0  0  0  1  0  0
     7   0  1  0  0  0  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        18614809335856128ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  1  1  1  1  0
     3   0  1  1  1  0  0  0  0
     4   0  0  1  0  1  0  0  0
     5   0  0  1  0  0  1  0  0
     6   0  0  1  0  0  0  1  0
     7   0  0  1  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        1200821652847104ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  1  0  1  1  1  0
     3   0  0  1  1  1  0  0  0
     4   0  1  0  1  0  1  0  0
     5   0  0  0  1  0  0  1  0
     6   0  0  0  1  0  0  0  0
     7   0  0  0  1  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2260905850861056ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  1  1  0  1  1  0
     3   0  0  0  1  1  1  0  0
     4   0  0  1  0  1  0  1  0
     5   0  1  0  0  1  0  0  0
     6   0  0  0  0  1  0  0  0
     7   0  0  0  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        4521270535810560ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  1  1  1  0  1  0
     3   0  0  0  0  1  1  1  0
     4   0  0  0  1  0  1  0  0
     5   0  0  1  0  0  1  0  0
     6   0  1  0  0  0  1  0  0
     7   0  0  0  0  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        9044737947360768ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  1  1  1  1  0  0
     3   0  0  0  0  0  1  1  0
     4   0  0  0  0  1  0  1  0
     5   0  0  0  1  0  0  1  0
     6   0  0  1  0  0  0  1  0
     7   0  1  0  0  0  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        18652425839721984ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  1  1  1  1  1  0
     3   0  0  0  0  0  0  1  1
     4   0  0  0  0  0  1  0  1
     5   0  0  0  0  1  0  0  1
     6   0  0  0  1  0  0  0  1
     7   0  0  1  0  0  0  0  1
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        37304851679444480ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   1  1  0  0  0  0  0  0
     3   0  1  1  1  1  1  1  0
     4   1  1  0  0  0  0  0  0
     5   1  0  1  0  0  0  0  0
     6   1  0  0  1  0  0  0  0
     7   1  0  0  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        4794991742157568ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  1  0  0  0  0  0
     3   0  0  1  1  1  1  1  0
     4   0  1  1  0  0  0  0  0
     5   0  1  0  1  0  0  0  0
     6   0  1  0  0  1  0  0  0
     7   0  1  0  0  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        9589983475926528ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  1  1  0  0  0  0
     3   0  1  0  1  1  1  1  0
     4   0  1  1  1  0  0  0  0
     5   0  0  1  0  1  0  0  0
     6   0  0  1  0  0  1  0  0
     7   0  0  1  0  0  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        19179966977150464ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  1  1  0  0  0
     3   0  1  1  0  1  1  1  0
     4   0  0  1  1  1  0  0  0
     5   0  1  0  1  0  1  0  0
     6   0  0  0  1  0  0  1  0
     7   0  0  0  1  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2331145517014016ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  1  1  0  0
     3   0  1  1  1  0  1  1  0
     4   0  0  0  1  1  1  0  0
     5   0  0  1  0  1  0  1  0
     6   0  1  0  0  1  0  0  0
     7   0  0  0  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        4523752560670720ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  1  1  1  0
     3   0  1  1  1  1  0  1  0
     4   0  0  0  0  1  1  1  0
     5   0  0  0  1  0  1  0  0
     6   0  0  1  0  0  1  0  0
     7   0  1  0  0  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        9609905310691328ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  1  1  0
     3   0  1  1  1  1  1  0  0
     4   0  0  0  0  0  1  1  0
     5   0  0  0  0  1  0  1  0
     6   0  0  0  1  0  0  1  0
     7   0  0  1  0  0  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        19219808465608704ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  1  1
     3   0  1  1  1  1  1  1  0
     4   0  0  0  0  0  0  1  1
     5   0  0  0  0  0  1  0  1
     6   0  0  0  0  1  0  0  1
     7   0  0  0  1  0  0  0  1
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        38439616931348480ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   1  0  1  0  0  0  0  0
     3   1  1  0  0  0  0  0  0
     4   0  1  1  1  1  1  1  0
     5   1  1  0  0  0  0  0  0
     6   1  0  1  0  0  0  0  0
     7   1  0  0  1  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2538787347563776ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  1  0  0  0  0
     3   0  1  1  0  0  0  0  0
     4   0  0  1  1  1  1  1  0
     5   0  1  1  0  0  0  0  0
     6   0  1  0  1  0  0  0  0
     7   0  1  0  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        5077572547643904ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  1  0  0  0
     3   0  1  1  1  0  0  0  0
     4   0  1  0  1  1  1  1  0
     5   0  1  1  1  0  0  0  0
     6   0  0  1  0  1  0  0  0
     7   0  0  1  0  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        10155151571424256ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  1  0  1  0  0
     3   0  0  1  1  1  0  0  0
     4   0  1  1  0  1  1  1  0
     5   0  0  1  1  1  0  0  0
     6   0  1  0  1  0  1  0  0
     7   0  0  0  1  0  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        20312500052175360ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  1  0  1  0
     3   0  0  0  1  1  1  0  0
     4   0  1  1  1  0  1  1  0
     5   0  0  0  1  1  1  0  0
     6   0  0  1  0  1  0  1  0
     7   0  1  0  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        5159150924878848ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  1  0  0
     3   0  0  0  0  1  1  1  0
     4   0  1  1  1  1  0  1  0
     5   0  0  0  0  1  1  1  0
     6   0  0  0  1  0  1  0  0
     7   0  0  1  0  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        10177562247440384ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  1  0  1  0
     3   0  0  0  0  0  1  1  0
     4   0  1  1  1  1  1  0  0
     5   0  0  0  0  0  1  1  0
     6   0  0  0  0  1  0  1  0
     7   0  0  0  1  0  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        20354572616749056ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  1  0  1
     3   0  0  0  0  0  0  1  1
     4   0  1  1  1  1  1  1  0
     5   0  0  0  0  0  0  1  1
     6   0  0  0  0  0  1  0  1
     7   0  0  0  0  1  0  0  1
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        40709145267052544ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   1  0  0  1  0  0  0  0
     3   1  0  1  0  0  0  0  0
     4   1  1  0  0  0  0  0  0
     5   0  1  1  1  1  1  1  0
     6   1  1  0  0  0  0  0  0
     7   1  0  1  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        1411214634977536ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  1  0  0  0
     3   0  1  0  1  0  0  0  0
     4   0  1  1  0  0  0  0  0
     5   0  0  1  1  1  1  1  0
     6   0  1  1  0  0  0  0  0
     7   0  1  0  1  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        2821879514141184ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  0  1  0  0
     3   0  0  1  0  1  0  0  0
     4   0  1  1  1  0  0  0  0
     5   0  1  0  1  1  1  1  0
     6   0  1  1  1  0  0  0  0
     7   0  0  1  0  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        5645416919213056ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  0  1  0
     3   0  1  0  1  0  1  0  0
     4   0  0  1  1  1  0  0  0
     5   0  1  1  0  1  1  1  0
     6   0  0  1  1  1  0  0  0
     7   0  1  0  1  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        11853242626099200ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  1  0  0  0
     3   0  0  1  0  1  0  1  0
     4   0  0  0  1  1  1  0  0
     5   0  1  1  1  0  1  1  0
     6   0  0  0  1  1  1  0  0
     7   0  0  1  0  1  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        23705944086286848ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  0  1  0  0
     3   0  0  0  1  0  1  0  0
     4   0  0  0  0  1  1  1  0
     5   0  1  1  1  1  0  1  0
     6   0  0  0  0  1  1  1  0
     7   0  0  0  1  0  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        11382549979341824ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  0  1  0
     3   0  0  0  0  1  0  1  0
     4   0  0  0  0  0  1  1  0
     5   0  1  1  1  1  1  0  0
     6   0  0  0  0  0  1  1  0
     7   0  0  0  0  1  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        22623819156965376ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  1  0  0  1
     3   0  0  0  0  0  1  0  1
     4   0  0  0  0  0  0  1  1
     5   0  1  1  1  1  1  1  0
     6   0  0  0  0  0  0  1  1
     7   0  0  0  0  0  1  0  1
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        45247646903865344ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   1  0  0  0  1  0  0  0
     3   1  0  0  1  0  0  0  0
     4   1  0  1  0  0  0  0  0
     5   1  1  0  0  0  0  0  0
     6   0  1  1  1  1  1  1  0
     7   1  1  0  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        982976364613888ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  0  1  0  0
     3   0  1  0  0  1  0  0  0
     4   0  1  0  1  0  0  0  0
     5   0  1  1  0  0  0  0  0
     6   0  0  1  1  1  1  1  0
     7   0  1  1  0  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        1825215240872448ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  0  0  1  0
     3   0  0  1  0  0  1  0  0
     4   0  0  1  0  1  0  0  0
     5   0  1  1  1  0  0  0  0
     6   0  1  0  1  1  1  1  0
     7   0  1  1  1  0  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        4074850560001024ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  0  0  0
     3   0  0  0  1  0  0  1  0
     4   0  1  0  1  0  1  0  0
     5   0  0  1  1  1  0  0  0
     6   0  1  1  0  1  1  1  0
     7   0  0  1  1  1  0  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        8011162688423936ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  1  0  0  0
     3   0  1  0  0  1  0  0  0
     4   0  0  1  0  1  0  1  0
     5   0  0  0  1  1  1  0  0
     6   0  1  1  1  0  1  1  0
     7   0  0  0  1  1  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        15883786903490560ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  0  1  0  0
     3   0  0  1  0  0  1  0  0
     4   0  0  0  1  0  1  0  0
     5   0  0  0  0  1  1  1  0
     6   0  1  1  1  1  0  1  0
     7   0  0  0  0  1  1  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        31629033194398208ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  0  0  1  0
     3   0  0  0  1  0  0  1  0
     4   0  0  0  0  1  0  1  0
     5   0  0  0  0  0  1  1  0
     6   0  1  1  1  1  1  0  0
     7   0  0  0  0  0  1  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        27090181148918784ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  0  0  1
     3   0  0  0  0  1  0  0  1
     4   0  0  0  0  0  1  0  1
     5   0  0  0  0  0  0  1  1
     6   0  1  1  1  1  1  1  0
     7   0  0  0  0  0  0  1  1
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        54182561321093120ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   1  0  0  0  0  1  0  0
     3   1  0  0  0  1  0  0  0
     4   1  0  0  1  0  0  0  0
     5   1  0  1  0  0  0  0  0
     6   1  1  0  0  0  0  0  0
     7   0  1  1  1  1  1  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        35469167227379968ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  0  0  1  0
     3   0  1  0  0  0  1  0  0
     4   0  1  0  0  1  0  0  0
     5   0  1  0  1  0  0  0  0
     6   0  1  1  0  0  0  0  0
     7   0  0  1  1  1  1  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        34909537435795968ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  0  0  0  0
     3   0  0  1  0  0  0  1  0
     4   0  0  1  0  0  1  0  0
     5   0  0  1  0  1  0  0  0
     6   0  1  1  1  0  0  0  0
     7   0  1  0  1  1  1  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        34355426829272064ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  0  0  0
     3   0  0  0  1  0  0  0  0
     4   0  0  0  1  0  0  1  0
     5   0  1  0  1  0  1  0  0
     6   0  0  1  1  1  0  0  0
     7   0  1  1  0  1  1  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        33245015174547456ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  1  0  0  0
     3   0  0  0  0  1  0  0  0
     4   0  1  0  0  1  0  0  0
     5   0  0  1  0  1  0  1  0
     6   0  0  0  1  1  1  0  0
     7   0  1  1  1  0  1  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        31024181169623040ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  1  0  0
     3   0  1  0  0  0  1  0  0
     4   0  0  1  0  0  1  0  0
     5   0  0  0  1  0  1  0  0
     6   0  0  0  0  1  1  1  0
     7   0  1  1  1  1  0  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        26581965518020608ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  0  0  1  0
     3   0  0  1  0  0  0  1  0
     4   0  0  0  1  0  0  1  0
     5   0  0  0  0  1  0  1  0
     6   0  0  0  0  0  1  1  0
     7   0  1  1  1  1  1  0  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        17557346482143744ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  0  0  0  1
     3   0  0  0  1  0  0  0  1
     4   0  0  0  0  1  0  0  1
     5   0  0  0  0  0  1  0  1
     6   0  0  0  0  0  0  1  1
     7   0  1  1  1  1  1  1  0
     8   0  0  0  0  0  0  0  0

        bitboard as 64 bit integer: */
        35677642917708800ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   1  0  0  0  0  0  1  0
     3   1  0  0  0  0  1  0  0
     4   1  0  0  0  1  0  0  0
     5   1  0  0  1  0  0  0  0
     6   1  0  1  0  0  0  0  0
     7   1  1  0  0  0  0  0  0
     8   0  1  1  1  1  1  1  0

        bitboard as 64 bit integer: */
        9080106810209288448ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  0  0  0  0
     3   0  1  0  0  0  0  1  0
     4   0  1  0  0  0  1  0  0
     5   0  1  0  0  1  0  0  0
     6   0  1  0  1  0  0  0  0
     7   0  1  1  0  0  0  0  0
     8   0  0  1  1  1  1  1  0

        bitboard as 64 bit integer: */
        8936841583563768320ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  1  0  0  0  0  0
     3   0  0  1  0  0  0  0  0
     4   0  0  1  0  0  0  1  0
     5   0  0  1  0  0  1  0  0
     6   0  0  1  0  1  0  0  0
     7   0  1  1  1  0  0  0  0
     8   0  1  0  1  1  1  1  0

        bitboard as 64 bit integer: */
        8794989268293649408ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  1  0  0  0  0
     3   0  0  0  1  0  0  0  0
     4   0  0  0  1  0  0  0  0
     5   0  0  0  1  0  0  1  0
     6   0  1  0  1  0  1  0  0
     7   0  0  1  1  1  0  0  0
     8   0  1  1  0  1  1  1  0

        bitboard as 64 bit integer: */
        8510723884684150784ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  1  0  0  0
     3   0  0  0  0  1  0  0  0
     4   0  0  0  0  1  0  0  0
     5   0  1  0  0  1  0  0  0
     6   0  0  1  0  1  0  1  0
     7   0  0  0  1  1  1  0  0
     8   0  1  1  1  0  1  1  0

        bitboard as 64 bit integer: */
        7942190379423502336ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  1  0  0
     3   0  0  0  0  0  1  0  0
     4   0  1  0  0  0  1  0  0
     5   0  0  1  0  0  1  0  0
     6   0  0  0  1  0  1  0  0
     7   0  0  0  0  1  1  1  0
     8   0  1  1  1  1  0  1  0

        bitboard as 64 bit integer: */
        6804983172613283840ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  0  0  0  0  0  1  0
     3   0  1  0  0  0  0  1  0
     4   0  0  1  0  0  0  1  0
     5   0  0  0  1  0  0  1  0
     6   0  0  0  0  1  0  1  0
     7   0  0  0  0  0  1  1  0
     8   0  1  1  1  1  1  0  0

        bitboard as 64 bit integer: */
        4494680699428814848ULL,
 /*
         A  B  C  D  E  F  G  H
     1   0  0  0  0  0  0  0  0
     2   0  1  0  0  0  0  0  1
     3   0  0  1  0  0  0  0  1
     4   0  0  0  1  0  0  0  1
     5   0  0  0  0  1  0  0  1
     6   0  0  0  0  0  1  0  1
     7   0  0  0  0  0  0  1  1
     8   0  1  1  1  1  1  1  0

        bitboard as 64 bit integer: */
        9133476586933486080ULL
 };
}
#endif //QUEEN_ATTACK_MASKS_H
