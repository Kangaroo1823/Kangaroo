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
        Chess_Board board("K7/8/8/P/P/8/r/8 w - - 0 1 ");
        Movement_Generator gen(&board);

        gen.build_pin_masks<Color::white, Pin_Masks_Suitable_For::detecting_pins>();
    }
}