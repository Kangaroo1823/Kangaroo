//
// Created by peter on 17/12/2024.
//

#ifndef ATTACK_TABLES_H
#define ATTACK_TABLES_H

#include <array>
#include "bitboard.h"
#include "magic_numbers.h"

static constexpr std::array<Bitboard, 64 * 4096> rook_attack_table = {

};
static constexpr std::array<Bitboard, 64 * 512> bishop_attack_table = {
#include <bishop_attack_masks.h>
};

template<bool isBishop>
constexpr std::size_t compute_magic_hash(const Position &position, const Bitboard &occupancy,
                                           const int64_t &relevant_bits) {
    if constexpr (isBishop) {
        return occupancy * Constants::Bishop_Magic_Numbers[std::to_underlying(position)] >> (64 - relevant_bits);
    } else {
        return occupancy * Constants::Rook_Magic_Numbers[std::to_underlying(position)] >> (64 - relevant_bits);
    }

}

#endif //ATTACK_TABLES_H
