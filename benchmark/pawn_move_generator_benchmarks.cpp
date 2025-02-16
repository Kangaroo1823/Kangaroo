// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 22/12/2024.
//

#include <memory>

#include "benchmark/benchmark.h"

#include "Chess_Board.h"
#include "Board_Status.h"
#include "Move_Generator/Move_Generator.h"


namespace Kangaroo {

    Callback_Template_Inline(Benchmark_Callback, uint64_t &cntr) {
        ++cntr;
        benchmark::DoNotOptimize(&pac_gen);
        benchmark::DoNotOptimize(&move);
    }

    auto board = std::make_unique<Chess_Board>();
    Move_Generator::Move_Generator<Board_Status(0x3d), Benchmark_Callback> generator(board.get());

    // cppcheck-suppress constParameterCallback
    static void BM_move_generator(benchmark::State &state) {

        [[maybe_unused]] auto s  = board->reset_board(fen_tricky_position_w);

        for ([[maybe_unused]] auto _: state) {

            uint64_t cntr = 0ULL;
            std::size_t ret = generator.generate_pawn_movements(cntr);

            benchmark::DoNotOptimize(cntr);
            benchmark::DoNotOptimize(ret);
        }
    }

    BENCHMARK(BM_move_generator)->Iterations(1000000000);
}



BENCHMARK_MAIN();
