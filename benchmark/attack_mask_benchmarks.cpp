//
// Created by peter on 22/12/2024.
//

#include "benchmark/benchmark.h"
#include "attack_tables.h"

// cppcheck-suppress constParameterCallback
static void BM_is_position_attacked_by_1(benchmark::State& state) {

    std::unique_ptr<Chess_Board> board =  create_chess_board_from_fen( fen_tricky_position );
    Bitboard is_attacked = 0ULL;

    for ([[maybe_unused]] auto _ : state) {

        for (const auto& position : All_Positions ) {
            is_attacked = is_position_attacked_by_1<Color::white>(position, board.get());
        }

    }

    benchmark::DoNotOptimize(is_attacked);

}

BENCHMARK(BM_is_position_attacked_by_1);

BENCHMARK_MAIN();
