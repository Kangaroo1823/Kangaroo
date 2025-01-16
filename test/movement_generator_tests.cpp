// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by U439644 on 1/8/2025.
//

#include "Movement_Generator.h"
#include "gtest/gtest.h"
#include "move_generator.h"

namespace Kangaroo {
    TEST(Movement_Generator_Test, test_pin_masks_generator) {
        using enum Color;
        using enum Pin_Masks_Suitable_For;

        Chess_Board board("K7/8/8/P7/P7/8/r7/8 w - - 0 1 ");
        Movement_Generator gen(&board);
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0) << "1st test not true";

        board.reset_board("K7/8/8/8/P7/8/r7/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "2nd test not true";

        board.reset_board("k7/8/8/8/P7/8/R7/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0) << "3rd test not true";

        board.reset_board("k7/8/8/8/p7/8/R7/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "4th test not true";


        board.reset_board("K7/8/8/8/P7/8/q7/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "5th test not true";

        board.reset_board("k7/8/8/8/p7/8/Q7/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "6th test not true";


        board.reset_board("8/q7/8/P7/8/8/8/K7 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "7th test not true";

        board.reset_board("8/Q7/8/p7/8/8/8/k7 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "8th test not true";

        board.reset_board("8/r7/8/P7/8/8/8/K7 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "9th test not true";

        board.reset_board("8/R7/8/p7/8/8/8/k7 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "10th test not true";

        board.reset_board("8/r7/8/P7/P7/8/8/K7 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "11th test not true";

        board.reset_board("8/R7/8/p7/p7/8/8/k7 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "12th test not true";

        board.reset_board("8/8/R1pp2k1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "13th test not true";

        board.reset_board("8/8/R2p2k1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x3f0000000000) << "14th test not true";

        board.reset_board("8/8/r1PP2K1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "15th test not true";

        board.reset_board("8/8/r2P2K1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x3f0000000000) << "16th test not true";


        board.reset_board("8/8/K2P2r1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x7e0000000000) << "17th test not true";

        board.reset_board("8/8/K1PP2r1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "18th test not true";

        board.reset_board("8/8/k2p2R1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x7e0000000000) << "19th test not true";

        board.reset_board("8/8/k1pp2R1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "20th test not true";

        board.reset_board("8/8/K2P2q1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x7e0000000000) << "21th test not true";

        board.reset_board("8/8/K1PP2q1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "22th test not true";

        board.reset_board("8/8/k2p2Q1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x7e0000000000) << "23th test not true";

        board.reset_board("8/8/k1pp2Q1/8/8/8/8/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "24th test not true";

        // Bishop tests

        board.reset_board("8/1k6/8/3p4/4p3/8/6B/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        board.reset_board("8/1k6/8/3p4/8/8/6B/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x40810204000) << "26th test not true";

        board.reset_board("8/1K6/8/3P4/4P3/8/6b/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "27th test not true";

        board.reset_board("8/1K6/8/3P4/8/8/6b/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x40810204000) << "28th test not true";

        board.reset_board("8/1k6/8/3p4/4p3/8/6Q/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "29th test not true";

        board.reset_board("8/1k6/8/3p4/8/8/6Q/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x40810204000) << "30th test not true";

        board.reset_board("8/1K6/8/3P4/4P3/8/6q/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "31th test not true";

        board.reset_board("8/1K6/8/3P4/8/8/6q/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x40810204000) << "32th test not true";


        board.reset_board("8/6k1/8/4p3/3p4/8/1B6/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        board.reset_board("8/6k1/8/8/3p4/8/1B6/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x201008040200) << "25th test not true";

        board.reset_board("8/6K1/8/4P3/3P4/8/1b6/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        board.reset_board("8/6K1/8/8/3P4/8/1b6/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x201008040200) << "25th test not true";

        board.reset_board("8/6k1/8/4p3/3p4/8/1Q6/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        board.reset_board("8/6k1/8/8/3p4/8/1Q6/8 w - - 0 1 ");
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x201008040200) << "25th test not true";

        board.reset_board("8/6K1/8/4P3/3P4/8/1q6/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        board.reset_board("8/6K1/8/8/3P4/8/1q6/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x201008040200) << "25th test not true";

        // should be zero
        board.reset_board("8/6K1/8/4p3/3P4/8/1q6/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x0) << "25th test not true";

        board.reset_board("8/6K1/8/8/3P4/8/q7/8 w - - 0 1 ");
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x0) << "25th test not true";
    }

    TEST(Movement_Generator_Test, test_pawn_movement_generator) {
        Chess_Board board("8/8/8/8/8/8/8/8 w - - 0 1");
        Movement_Generator gen(&board);

        // empty board results in no moves generated
        auto number_of_moves = gen.run_move_generation(
            []([[maybe_unused]] const Chess_Board *new_board, [[maybe_unused]] const Move move,
               [[maybe_unused]] const Color color, [[maybe_unused]] const Chess_Pieces chess_piece) {
                std::print("move: 0x{0:x}\n", move);
                print_bitboard(move);
                std::print("\n\n");
            });
        ASSERT_EQ(number_of_moves, 0);

        /*
                        A  B  C  D  E  F  G  H

                   8    .  .  .  .  .  .  .  .
                   7    .  .  ♖  .  .  .  .  .
                   6    .  .  .  ♟  .  .  .  .
                   5    .  .  .  .  .  .  .  .
                   4    .  .  .  .  .  .  .  .
                   3    .  .  .  .  .  .  .  .
                   2    .  .  .  .  .  .  .  .
                   1    .  .  .  .  .  .  .  .

                        A  B  C  D  E  F  G  H
          */
        board.reset_board("8/2r5/3P4/8/8/8/8/8 w - - 0 1");
        print_chess_board(&board);

        std::vector<Bitboard> moves = {
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  1  .  .  .  .
              6    .  .  .  1  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x8080000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  1  .  .  .  .  .
              6    .  .  .  1  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x4080000000000,
        };

        number_of_moves = gen.run_move_generation(
            [&moves]([[maybe_unused]] const Chess_Board *new_board, [[maybe_unused]] const Move move,
               [[maybe_unused]] const Color color, [[maybe_unused]] const Chess_Pieces chess_piece) {
                print_bitboard(move);
                ASSERT_TRUE(std::ranges::contains(moves, move));
            });

        ASSERT_EQ(number_of_moves, 2);
    }
}
