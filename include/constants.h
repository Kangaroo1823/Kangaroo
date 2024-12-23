//
// Created by U439644 on 12/23/2024.
//

#ifndef CONSTANTS_H
#define CONSTANTS_H

/**
 * We need a little preprocessor magic here to make things compile when the includes below have not been generated yet.
 */

#ifndef GENERATE_MASKS
#  include "constants_masks.h"
#  ifndef GENERATE_MAGICS
#    include "constants_magics.h"
#    ifndef GENERATE_ATTACKS
#      include "constants_attacks.h"
#    else
       namespace Constants {
              inline constexpr std::array<Bitboard, 64 * 4096> rook_attack_table = {};
              inline constexpr std::array<Bitboard, 64 * 512> bishop_attack_table = {};

              inline constexpr std::array<Bitboard, 64> white_pawn_attacks = {};
              inline constexpr std::array<Bitboard, 64> black_pawn_attacks = {};

              inline constexpr std::array<Bitboard, 64> king_attacks = {};
              inline constexpr std::array<Bitboard, 64> knight_attacks = {};
       }
#    endif
#  else
       namespace Constants {
              inline constexpr std::array<Bitboard, 64 * 4096> rook_attack_table = {};
              inline constexpr std::array<Bitboard, 64 * 512> bishop_attack_table = {};

              inline constexpr std::array<Bitboard, 64> white_pawn_attacks = {};
              inline constexpr std::array<Bitboard, 64> black_pawn_attacks = {};

              inline constexpr std::array<Bitboard, 64> king_attacks = {};
              inline constexpr std::array<Bitboard, 64> knight_attacks = {};

              inline constexpr std::array<MagicNumber, 64> bishop_magic_numbers = {};
              inline constexpr std::array<MagicNumber, 64> rook_magic_numbers = {};
       }
#  endif
#else
  namespace Constants {
              inline constexpr std::array<Bitboard, 64 * 4096> rook_attack_table = {};
              inline constexpr std::array<Bitboard, 64 * 512> bishop_attack_table = {};

              inline constexpr std::array<Bitboard, 64> white_pawn_attacks = {};
              inline constexpr std::array<Bitboard, 64> black_pawn_attacks = {};

              inline constexpr std::array<Bitboard, 64> king_attacks = {};
              inline constexpr std::array<Bitboard, 64> knight_attacks = {};

              inline constexpr std::array<MagicNumber, 64> bishop_magic_numbers = {};
              inline constexpr std::array<MagicNumber, 64> rook_magic_numbers = {};

              inline constexpr std::array<Bitboard, 64> bishop_attack_masks = {};
              inline constexpr std::array<Bitboard, 64> rook_attack_masks = {};
       }
#endif



#endif //CONSTANTS_H
