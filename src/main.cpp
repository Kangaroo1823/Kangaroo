#include <bitset>
#include <iostream>
#include <iso646.h>

#include "bitboard.h"
#include "chess_board.h"






Bitboard create_bishop_attacks(Position position) {
    Bitboard attacks = 0ULL;

    Bitboard bitboard = set_bit(0ULL, position);

    for (unsigned int i = 0; i < 8; ++i)
        attacks |= (bitboard <<= 7 & not_h_file);

    return attacks;
}





int main() {

    // for (Position position : All_Positions) {
    constexpr Position position = E4;
        const Bitboard bitboard = create_bishop_attacks(position);
        print_bitboard(bitboard);
    // }


    return 0;
}

