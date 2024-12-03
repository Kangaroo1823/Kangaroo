//
// Created by peter on 01/12/2024.
//

#ifndef PAWN_ATTACKS_H
#define PAWN_ATTACKS_H

#include "bitboard.h"

namespace Constants {
    /**
     * @brief A precomputed table representing the pawn attack patterns on a chessboard.
     *
     * This 2D array represents the attack patterns of pawns for both white and black.
     * The first dimension of the array, indexed by 0 and 1, corresponds to the color of the pawn;
     * 0 represents white pawns, and 1 represents black pawns. Each entry in the second dimension
     * corresponds to a square on the chessboard and contains a 64-bit integer (Bitboard) that
     * indicates which squares are attacked by a pawn located on the given square.
     *
     * The bitboard representation allows efficient calculations of possible pawn attacks.
     * Each bit in the 64-bit integer corresponds to a square on the chessboard, where a set bit (1)
     * indicates that the square is under attack by the pawn.
     */
    static constexpr Bitboard Pawn_Attacks[2][64] = {
        {
            /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
            512ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   1  0  1  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            1280ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  1  0  1  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            2560ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  1  0  1  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            5120ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  1  0  1  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            10240ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  1  0  1  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            20480ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  1  0  1
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            40960ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  1  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            16384ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  1  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            131072ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   1  0  1  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            327680ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  1  0  1  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            655360ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  1  0  1  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            1310720ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  1  0  1  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            2621440ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  1  0  1  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            5242880ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  1  0  1
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            10485760ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  1  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            4194304ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  1  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            33554432ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   1  0  1  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            83886080ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  1  0  1  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            167772160ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  1  0  1  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            335544320ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  1  0  1  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            671088640ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  1  0  1  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            1342177280ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  1  0  1
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            2684354560ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  1  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            1073741824ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  1  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            8589934592ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   1  0  1  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            21474836480ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  1  0  1  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            42949672960ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  1  0  1  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            85899345920ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  1  0  1  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            171798691840ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  1  0  1  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            343597383680ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  1  0  1
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            687194767360ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  1  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            274877906944ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  1  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            2199023255552ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   1  0  1  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            5497558138880ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  1  0  1  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            10995116277760ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  1  0  1  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            21990232555520ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  1  0  1  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            43980465111040ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  1  0  1  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            87960930222080ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  1  0  1
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            175921860444160ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  1  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            70368744177664ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  1  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            562949953421312ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   1  0  1  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            1407374883553280ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  1  0  1  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            2814749767106560ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  1  0  1  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            5629499534213120ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  1  0  1  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            11258999068426240ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  1  0  1  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            22517998136852480ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  1  0  1
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            45035996273704960ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  1  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            18014398509481984ULL,
     /*
         8   0  1  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            144115188075855872ULL,
     /*
         8   1  0  1  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            360287970189639680ULL,
     /*
         8   0  1  0  1  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            720575940379279360ULL,
     /*
         8   0  0  1  0  1  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            1441151880758558720ULL,
     /*
         8   0  0  0  1  0  1  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            2882303761517117440ULL,
     /*
         8   0  0  0  0  1  0  1  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            5764607523034234880ULL,
     /*
         8   0  0  0  0  0  1  0  1
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            11529215046068469760ULL,
     /*
         8   0  0  0  0  0  0  1  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            4611686018427387904ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            0ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            0ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            0ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            0ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            0ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            0ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            0ULL,
     /*
         8   0  0  0  0  0  0  0  0
         7   0  0  0  0  0  0  0  0
         6   0  0  0  0  0  0  0  0
         5   0  0  0  0  0  0  0  0
         4   0  0  0  0  0  0  0  0
         3   0  0  0  0  0  0  0  0
         2   0  0  0  0  0  0  0  0
         1   0  0  0  0  0  0  0  0
             A  B  C  D  E  F  G  H

            bitboard as 64 bit integer: */
            0ULL
         }, {
             /*
                 8   0  0  0  0  0  0  0  0
                 7   0  0  0  0  0  0  0  0
                 6   0  0  0  0  0  0  0  0
                 5   0  0  0  0  0  0  0  0
                 4   0  0  0  0  0  0  0  0
                 3   0  0  0  0  0  0  0  0
                 2   0  0  0  0  0  0  0  0
                 1   0  0  0  0  0  0  0  0
                     A  B  C  D  E  F  G  H

                    bitboard as 64 bit integer: */
             0ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             0ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             0ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             0ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             0ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             0ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             0ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             0ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  1  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             2ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   1  0  1  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             5ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  1  0  1  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             10ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  1  0  1  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             20ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  1  0  1  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             40ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  1  0  1  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             80ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  1  0  1
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             160ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  1  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             64ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  1  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             512ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   1  0  1  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             1280ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  1  0  1  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             2560ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  1  0  1  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             5120ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  1  0  1  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             10240ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  1  0  1  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             20480ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  1  0  1
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             40960ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  1  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             16384ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  1  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             131072ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   1  0  1  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             327680ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  1  0  1  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             655360ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  1  0  1  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             1310720ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  1  0  1  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             2621440ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  1  0  1  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             5242880ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  1  0  1
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             10485760ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  1  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             4194304ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  1  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             33554432ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   1  0  1  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             83886080ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  1  0  1  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             167772160ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  1  0  1  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             335544320ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  1  0  1  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             671088640ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  1  0  1  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             1342177280ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  1  0  1
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             2684354560ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  1  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             1073741824ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  1  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             8589934592ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   1  0  1  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             21474836480ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  1  0  1  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             42949672960ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  1  0  1  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             85899345920ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  1  0  1  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             171798691840ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  1  0  1  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             343597383680ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  1  0  1
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             687194767360ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  1  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             274877906944ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  1  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             2199023255552ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   1  0  1  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             5497558138880ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  1  0  1  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             10995116277760ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  1  0  1  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             21990232555520ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  1  0  1  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             43980465111040ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  1  0  1  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             87960930222080ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  1  0  1
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             175921860444160ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  0  0
          6   0  0  0  0  0  0  1  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             70368744177664ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  1  0  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             562949953421312ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   1  0  1  0  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             1407374883553280ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  1  0  1  0  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             2814749767106560ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  1  0  1  0  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             5629499534213120ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  1  0  1  0  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             11258999068426240ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  1  0  1  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             22517998136852480ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  1  0  1
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             45035996273704960ULL,
      /*
          8   0  0  0  0  0  0  0  0
          7   0  0  0  0  0  0  1  0
          6   0  0  0  0  0  0  0  0
          5   0  0  0  0  0  0  0  0
          4   0  0  0  0  0  0  0  0
          3   0  0  0  0  0  0  0  0
          2   0  0  0  0  0  0  0  0
          1   0  0  0  0  0  0  0  0
              A  B  C  D  E  F  G  H

             bitboard as 64 bit integer: */
             18014398509481984ULL
          }
    };
}

#endif //PAWN_ATTACKS_H
