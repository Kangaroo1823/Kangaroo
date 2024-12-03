//
// Created by peter on 02/12/2024.
//

#ifndef BISHOP_ATTACK_MASKS_H
#define BISHOP_ATTACK_MASKS_H

#include "bitboard.h"

namespace Constants {
    /**
     * @brief Array of 64-bit integers where a bit is set (1) iff a figure there
     * restricts movement of the bishop.
     *
     * The array has 64 elements and is indexed by the position of the bishop on
     * an otherwise empty chess board. At index 0 it is assumed that the bishop is on
     * the square A1, at index 7 the bishop is assumed to be at index H1, at index 8
     * the bishop is at A2, etc.
     *
     * The array is composed of 64-bit unsigned integers. Each bit represents a
     * square of the chess board. If the bit is set (1), it states that another figure
     * at the corresponding square might restrict further movement of the bishop.
     *
     * Note: It is assumed that the bishop can capture the other figure, but cannot go any
     * further in the direction.
     *
     * Otherwise, if a figure at that position does not restrict the bishops' movement the
     * corresponding bit is unset (0). Again it is assumed that the bishop might move to
     * this square
     */
    static constexpr Bitboard bishop_attack_masks[64] = {
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18049651735527936ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        70506452091904ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  1  0  0  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        275415828992ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  1  0  0  0
            3   0  1  0  0  0  1  0  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  0  0  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1075975168ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  1  0  0
            3   0  0  1  0  0  0  1  0
            4   0  1  0  0  0  0  0  0
            5   0  0  0  0  0  0  0  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        38021120ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  1  0
            3   0  0  0  1  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        8657588224ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2216338399232ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        567382630219776ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9024825867763712ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18049651735527424ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  1  0  1  0  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        70506452221952ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  1  0  1  0  0  0
            4   0  1  0  0  0  1  0  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        275449643008ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  1  0  1  0  0
            4   0  0  1  0  0  0  1  0
            5   0  1  0  0  0  0  0  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9733406720ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  1  0  1  0
            4   0  0  0  1  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2216342585344ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        567382630203392ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1134765260406784ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4512412933816832ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9024825867633664ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  1  0  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  1  0  1  0  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18049651768822272ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  1  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  0  1  0  1  0  0  0
            5   0  1  0  0  0  1  0  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        70515108615168ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  1  0  0
            3   0  0  0  0  0  0  0  0
            4   0  0  0  1  0  1  0  0
            5   0  0  1  0  0  0  1  0
            6   0  1  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2491752130560ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  1  0
            3   0  0  0  0  0  0  0  0
            4   0  0  0  0  1  0  1  0
            5   0  0  0  1  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        567383701868544ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  0  0  0  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1134765256220672ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  0  0  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2269530512441344ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  0  0  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2256206450263040ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  0  0  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4512412900526080ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  1  0  1  0  0  0  0
            4   0  0  0  0  0  0  0  0
            5   0  1  0  1  0  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9024834391117824ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  1  0  0
            3   0  0  1  0  1  0  0  0
            4   0  0  0  0  0  0  0  0
            5   0  0  1  0  1  0  0  0
            6   0  1  0  0  0  1  0  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18051867805491712ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  1  0
            3   0  0  0  1  0  1  0  0
            4   0  0  0  0  0  0  0  0
            5   0  0  0  1  0  1  0  0
            6   0  0  1  0  0  0  1  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        637888545440768ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  0  0  1  0  1  0
            4   0  0  0  0  0  0  0  0
            5   0  0  0  0  1  0  1  0
            6   0  0  0  1  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1135039602493440ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  0  0  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2269529440784384ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  0  0  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4539058881568768ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  0  0  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1128098963916800ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  0  0  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2256197927833600ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  1  0  0  0
            4   0  1  0  1  0  0  0  0
            5   0  0  0  0  0  0  0  0
            6   0  1  0  1  0  0  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4514594912477184ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  1  0  0  0  1  0  0
            4   0  0  1  0  1  0  0  0
            5   0  0  0  0  0  0  0  0
            6   0  0  1  0  1  0  0  0
            7   0  1  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9592139778506752ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  0  1  0  0  0  1  0
            4   0  0  0  1  0  1  0  0
            5   0  0  0  0  0  0  0  0
            6   0  0  0  1  0  1  0  0
            7   0  0  1  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        19184279556981248ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  0  1  0  1  0
            5   0  0  0  0  0  0  0  0
            6   0  0  0  0  1  0  1  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2339762086609920ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  0  0  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4538784537380864ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  0  0  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9077569074761728ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  0  0  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        562958610993152ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  0  0  0  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1125917221986304ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  1  0  0  0
            5   0  1  0  1  0  0  0  0
            6   0  0  0  0  0  0  0  0
            7   0  1  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2814792987328512ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  1  0
            4   0  1  0  0  0  1  0  0
            5   0  0  1  0  1  0  0  0
            6   0  0  0  0  0  0  0  0
            7   0  0  1  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        5629586008178688ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  0  1  0  0  0  1  0
            5   0  0  0  1  0  1  0  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  1  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        11259172008099840ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  0  1  0  1  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  0  1  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        22518341868716544ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9007336962655232ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  0  0  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18014673925310464ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2216338399232ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4432676798464ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  1  0  0  0
            6   0  1  0  1  0  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        11064376819712ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  0  0  0  0  0  1  0
            5   0  1  0  0  0  1  0  0
            6   0  0  1  0  1  0  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        22137335185408ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  0  1  0  0  0  1  0
            6   0  0  0  1  0  1  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        44272556441600ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  0  1  0  1  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        87995357200384ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        35253226045952ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        70506452091904ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        567382630219776ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1134765260406784ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  1  0  0  0
            7   0  1  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2832480465846272ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  0  0  0  0  0  0  0
            5   0  0  0  0  0  0  1  0
            6   0  1  0  0  0  1  0  0
            7   0  0  1  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        5667157807464448ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  0  0  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  0  1  0  0  0  1  0
            7   0  0  0  1  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        11333774449049600ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  0  0  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  0  0  1  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        22526811443298304ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9024825867763712ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18049651735527936ULL
    };
}
#endif //BISHOP_ATTACK_MASKS_H
