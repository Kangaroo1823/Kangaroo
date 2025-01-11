// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 22/12/2024.
//

#include <memory>

#include "benchmark/benchmark.h"
#include "../tools/attack_tables.h"
#include "chess_board.h"
#include "Movement_Generator.h"


const auto board = std::make_unique<Kangaroo::Chess_Board>(fen_tricky_position_w);
const auto movement_generator = std::make_unique<Kangaroo::Movement_Generator>(board.get());

// cppcheck-suppress constParameterCallback
static void BM_move_generator(benchmark::State &state) {
    for ([[maybe_unused]] auto _: state) {
        uint64_t cntr = 0ULL;

        auto s = movement_generator->generate_moves<Kangaroo::Board_Status(0x3d)>([&cntr]([[maybe_unused]] const Chess_Pieces chess_piece,
                                                                    [[maybe_unused]] const Bitboard is_attacked) {
            ++cntr;
        });


        benchmark::DoNotOptimize(cntr);
        benchmark::DoNotOptimize(s);
    }
}
BENCHMARK(BM_move_generator)->Iterations(1000000000);


static void BM_pin_mask_generator(benchmark::State &state) {
    for ([[maybe_unused]] auto _: state) {
        Bitboard cntr1 = 0ULL;
        Bitboard cntr2 = 0ULL;

        movement_generator->build_pin_masks<Color::black, Pin_Masks_Suitable_For_t::detecting_pins>();
        cntr1 = movement_generator->get_pin_mask_HV();
        cntr2 = movement_generator->get_pin_mask_D();

        benchmark::DoNotOptimize(cntr1);
        benchmark::DoNotOptimize(cntr2);
    }
}

BENCHMARK(BM_pin_mask_generator);


BENCHMARK_MAIN();
