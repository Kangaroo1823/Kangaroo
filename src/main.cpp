#include <fmt/base.h>                                 // for print
#include <cstdint>                                   // for int64_t, uint64_t
#include <sys/types.h>                                // for uint
#include <algorithm>
#include <array>                                      // for array
#include <random>                                     // for mt19937_64
#include <utility>
#include <utility>
#include "../include/bishop_attack_masks.h"           // for bishop_attack_m...
#include "../include/bitboard.h"                      // for Bitboard, Bitcount
#include "../include/create_possible_bishop_moves.h"  // for create_possible...
#include "../include/create_possible_rook_moves.h"    // for create_possible...
#include "../include/rook_attack_masks.h"             // for rook_attack_masks
#include "magic_numbers.h"




int main() {
    Constants::Impl::compute_magic_numbers();

    return 0;
}
