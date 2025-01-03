// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 22/12/2024.
//

#include "benchmark/benchmark.h"
#include "../tools/attack_tables.h"

const std::unique_ptr<Chess_Board> board =  create_chess_board_from_fen( fen_tricky_position_w );

// cppcheck-suppress constParameterCallback
static void BM_is_position_attacked_by(benchmark::State& state) {

    Bitboard is_attacked = 0ULL;

    for ([[maybe_unused]] auto _ : state) {

        for (const auto& position : All_Positions ) {
         //   is_attacked = is_position_attacked_by<Color::white>(position, board.get());
        }

    }

    benchmark::DoNotOptimize(is_attacked);

}

BENCHMARK(BM_is_position_attacked_by);

BENCHMARK_MAIN();
