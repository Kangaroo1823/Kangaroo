// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 2/8/25.
//

#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo::Pawn_Move_Generation::Pins1 {

    Callback_Template_Inline(Pawn_Movement_Generator_Test4_Callback) {
        throw std::runtime_error("no moves should be generated here..");
    }

    Status_Callback_Template(Pawn_Movement_Generator_Test4, Chess_Board* board) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements();
    }


    // test that with a diagonally pinned pawn no moves are generated.
    TEST(Pawn_Move_Generation, Pins1) {
        using namespace Kangaroo::Move_Generator;
        /*

               A  B  C  D  E  F  G  H

          8    .  .  .  .  .  .  .  ♚
          7    .  .  .  .  .  .  .  .
          6    .  .  .  .  .  ♟  .  .
          5    .  .  .  .  .  .  .  .
          4    .  .  .  .  .  .  .  .
          3    .  .  .  .  .  .  .  .
          2    .  .  .  .  .  .  .  .
          1    ♗  .  .  .  .  .  .  .

               A  B  C  D  E  F  G  H

        */

        Chess_Board board{};
        const auto status = board.reset_board("7K/8/5P2/8/8/8/8/b7 w - - 0 1");

        const std::size_t n = execute_status_callback_template<Pawn_Movement_Generator_Test4,
            Pawn_Movement_Generator_Test4_Callback>(*status, &board);
        ASSERT_EQ(n, 0);
    }


}