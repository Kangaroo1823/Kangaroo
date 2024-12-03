//
// Created by peter on 02/12/2024.
//

#ifndef ROOK_ATTACK_MASKS_H
#define ROOK_ATTACK_MASKS_H

#include <array>

#include "bitboard.h"

namespace Constants {
    /**
     * @brief Array of 64-bit integers where a bit is set (1) iff a figure there
     * restricts movement of the rook.
     *
     * The array has 64 elements and is indexed by the position of the rook on
     * an otherwise empty chess board. At index 0 it is assumed that the rook is on
     * the square A1, at index 7 the rook is assumed to be at index H1, at index 8
     * the rook is at A2, etc.
     *
     * The array is composed of 64-bit unsigned integers. Each bit represents a
     * square of the chess board. If the bit is set (1), it states that another figure
     * at the corresponding square might restrict further movement of the rook.
     *
     * Note: It is assumed that the rook can capture the other figure, but cannot go any
     * further in the direction.
     *
     * Otherwise, if a figure at that position does not restrict the rooks' movement the
     * corresponding bit is unset (0). Again it is assumed that the rook might move to
     * this square
     */
    static constexpr std::array<Bitboard, 64> rook_attack_masks = {
        /*
                A  B  C  D  E  F  G  H
            1   0  1  1  1  1  1  1  0
            2   1  0  0  0  0  0  0  0
            3   1  0  0  0  0  0  0  0
            4   1  0  0  0  0  0  0  0
            5   1  0  0  0  0  0  0  0
            6   1  0  0  0  0  0  0  0
            7   1  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        282578800148862ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  1  1  1  1  1  0
            2   0  1  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        565157600297596ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  1  0  1  1  1  1  0
            2   0  0  1  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1130315200595066ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  1  1  0  1  1  1  0
            2   0  0  0  1  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2260630401190006ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  1  1  1  0  1  1  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4521260802379886ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  1  1  1  1  0  1  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9042521604759646ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  1  1  1  1  1  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18085043209519166ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  1  1  1  1  1  1  0
            2   0  0  0  0  0  0  0  1
            3   0  0  0  0  0  0  0  1
            4   0  0  0  0  0  0  0  1
            5   0  0  0  0  0  0  0  1
            6   0  0  0  0  0  0  0  1
            7   0  0  0  0  0  0  0  1
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        36170086419038334ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  1  1  1  1  1  0
            3   1  0  0  0  0  0  0  0
            4   1  0  0  0  0  0  0  0
            5   1  0  0  0  0  0  0  0
            6   1  0  0  0  0  0  0  0
            7   1  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        282578800180736ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  1  1  1  1  0
            3   0  1  0  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        565157600328704ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  1  1  1  1  0
            3   0  0  1  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1130315200625152ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  1  0  1  1  1  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2260630401218048ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  1  1  0  1  1  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4521260802403840ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  1  1  1  0  1  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9042521604775424ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  1  1  1  1  0  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18085043209518592ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  1  1  1  1  1  0
            3   0  0  0  0  0  0  0  1
            4   0  0  0  0  0  0  0  1
            5   0  0  0  0  0  0  0  1
            6   0  0  0  0  0  0  0  1
            7   0  0  0  0  0  0  0  1
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        36170086419037696ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   1  0  0  0  0  0  0  0
            3   0  1  1  1  1  1  1  0
            4   1  0  0  0  0  0  0  0
            5   1  0  0  0  0  0  0  0
            6   1  0  0  0  0  0  0  0
            7   1  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        282578808340736ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  0  1  1  1  1  1  0
            4   0  1  0  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        565157608292864ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  1  0  1  1  1  1  0
            4   0  0  1  0  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1130315208328192ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  1  1  0  1  1  1  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2260630408398848ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  1  1  1  0  1  1  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4521260808540160ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  1  1  1  1  0  1  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9042521608822784ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  1  1  1  1  1  0  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18085043209388032ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  1
            3   0  1  1  1  1  1  1  0
            4   0  0  0  0  0  0  0  1
            5   0  0  0  0  0  0  0  1
            6   0  0  0  0  0  0  0  1
            7   0  0  0  0  0  0  0  1
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        36170086418907136ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   1  0  0  0  0  0  0  0
            3   1  0  0  0  0  0  0  0
            4   0  1  1  1  1  1  1  0
            5   1  0  0  0  0  0  0  0
            6   1  0  0  0  0  0  0  0
            7   1  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        282580897300736ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  0  1  1  1  1  1  0
            5   0  1  0  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        565159647117824ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  1  0  1  1  1  1  0
            5   0  0  1  0  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1130317180306432ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  1  1  0  1  1  1  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2260632246683648ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  0  1  0  0  0
            4   0  1  1  1  0  1  1  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4521262379438080ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  0  1  0  0
            4   0  1  1  1  1  0  1  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9042522644946944ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  0  1  0
            4   0  1  1  1  1  1  0  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18085043175964672ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  1
            3   0  0  0  0  0  0  0  1
            4   0  1  1  1  1  1  1  0
            5   0  0  0  0  0  0  0  1
            6   0  0  0  0  0  0  0  1
            7   0  0  0  0  0  0  0  1
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        36170086385483776ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   1  0  0  0  0  0  0  0
            3   1  0  0  0  0  0  0  0
            4   1  0  0  0  0  0  0  0
            5   0  1  1  1  1  1  1  0
            6   1  0  0  0  0  0  0  0
            7   1  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        283115671060736ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  0  1  1  1  1  1  0
            6   0  1  0  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        565681586307584ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  1  0  1  1  1  1  0
            6   0  0  1  0  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1130822006735872ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  1  1  0  1  1  1  0
            6   0  0  0  1  0  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2261102847592448ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  1  1  1  0  1  1  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4521664529305600ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  0  1  0  0
            5   0  1  1  1  1  0  1  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9042787892731904ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  0  1  0
            5   0  1  1  1  1  1  0  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18085034619584512ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  1
            3   0  0  0  0  0  0  0  1
            4   0  0  0  0  0  0  0  1
            5   0  1  1  1  1  1  1  0
            6   0  0  0  0  0  0  0  1
            7   0  0  0  0  0  0  0  1
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        36170077829103616ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   1  0  0  0  0  0  0  0
            3   1  0  0  0  0  0  0  0
            4   1  0  0  0  0  0  0  0
            5   1  0  0  0  0  0  0  0
            6   0  1  1  1  1  1  1  0
            7   1  0  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        420017753620736ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  0  1  1  1  1  1  0
            7   0  1  0  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        699298018886144ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  1  0  1  1  1  1  0
            7   0  0  1  0  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        1260057572672512ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  1  1  0  1  1  1  0
            7   0  0  0  1  0  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        2381576680245248ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  1  1  1  0  1  1  0
            7   0  0  0  0  1  0  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        4624614895390720ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  0  1  0  0
            6   0  1  1  1  1  0  1  0
            7   0  0  0  0  0  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        9110691325681664ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  0  1  0
            6   0  1  1  1  1  1  0  0
            7   0  0  0  0  0  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        18082844186263552ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  1
            3   0  0  0  0  0  0  0  1
            4   0  0  0  0  0  0  0  1
            5   0  0  0  0  0  0  0  1
            6   0  1  1  1  1  1  1  0
            7   0  0  0  0  0  0  0  1
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        36167887395782656ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   1  0  0  0  0  0  0  0
            3   1  0  0  0  0  0  0  0
            4   1  0  0  0  0  0  0  0
            5   1  0  0  0  0  0  0  0
            6   1  0  0  0  0  0  0  0
            7   0  1  1  1  1  1  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        35466950888980736ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  0  1  1  1  1  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        34905104758997504ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  1  0  1  1  1  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        34344362452452352ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  1  1  0  1  1  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        33222877839362048ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  1  1  1  0  1  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        30979908613181440ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  1  0  0
            7   0  1  1  1  1  0  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        26493970160820224ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  0  1  0
            7   0  1  1  1  1  1  0  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        17522093256097792ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  1
            3   0  0  0  0  0  0  0  1
            4   0  0  0  0  0  0  0  1
            5   0  0  0  0  0  0  0  1
            6   0  0  0  0  0  0  0  1
            7   0  1  1  1  1  1  1  0
            8   0  0  0  0  0  0  0  0

               bitboard as 64 bit integer: */
        35607136465616896ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   1  0  0  0  0  0  0  0
            3   1  0  0  0  0  0  0  0
            4   1  0  0  0  0  0  0  0
            5   1  0  0  0  0  0  0  0
            6   1  0  0  0  0  0  0  0
            7   1  0  0  0  0  0  0  0
            8   0  1  1  1  1  1  1  0

               bitboard as 64 bit integer: */
        9079539427579068672ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  1  0  0  0  0  0  0
            3   0  1  0  0  0  0  0  0
            4   0  1  0  0  0  0  0  0
            5   0  1  0  0  0  0  0  0
            6   0  1  0  0  0  0  0  0
            7   0  1  0  0  0  0  0  0
            8   0  0  1  1  1  1  1  0

               bitboard as 64 bit integer: */
        8935706818303361536ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  1  0  0  0  0  0
            3   0  0  1  0  0  0  0  0
            4   0  0  1  0  0  0  0  0
            5   0  0  1  0  0  0  0  0
            6   0  0  1  0  0  0  0  0
            7   0  0  1  0  0  0  0  0
            8   0  1  0  1  1  1  1  0

               bitboard as 64 bit integer: */
        8792156787827803136ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  1  0  0  0  0
            3   0  0  0  1  0  0  0  0
            4   0  0  0  1  0  0  0  0
            5   0  0  0  1  0  0  0  0
            6   0  0  0  1  0  0  0  0
            7   0  0  0  1  0  0  0  0
            8   0  1  1  0  1  1  1  0

               bitboard as 64 bit integer: */
        8505056726876686336ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  1  0  0  0
            3   0  0  0  0  1  0  0  0
            4   0  0  0  0  1  0  0  0
            5   0  0  0  0  1  0  0  0
            6   0  0  0  0  1  0  0  0
            7   0  0  0  0  1  0  0  0
            8   0  1  1  1  0  1  1  0

               bitboard as 64 bit integer: */
        7930856604974452736ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  1  0  0
            3   0  0  0  0  0  1  0  0
            4   0  0  0  0  0  1  0  0
            5   0  0  0  0  0  1  0  0
            6   0  0  0  0  0  1  0  0
            7   0  0  0  0  0  1  0  0
            8   0  1  1  1  1  0  1  0

               bitboard as 64 bit integer: */
        6782456361169985536ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  1  0
            3   0  0  0  0  0  0  1  0
            4   0  0  0  0  0  0  1  0
            5   0  0  0  0  0  0  1  0
            6   0  0  0  0  0  0  1  0
            7   0  0  0  0  0  0  1  0
            8   0  1  1  1  1  1  0  0

               bitboard as 64 bit integer: */
        4485655873561051136ULL,
        /*
                A  B  C  D  E  F  G  H
            1   0  0  0  0  0  0  0  0
            2   0  0  0  0  0  0  0  1
            3   0  0  0  0  0  0  0  1
            4   0  0  0  0  0  0  0  1
            5   0  0  0  0  0  0  0  1
            6   0  0  0  0  0  0  0  1
            7   0  0  0  0  0  0  0  1
            8   0  1  1  1  1  1  1  0

               bitboard as 64 bit integer: */
        9115426935197958144ULL
    };
}
#endif //ROOK_ATTACK_MASKS_H
