//
// Created by U439644 on 1/8/2025.
//

#ifndef MOVEMENT_GENERATOR_H
#define MOVEMENT_GENERATOR_H
#include <filesystem>

#include "Chess_Board.h"
#include "Constants.h"
#include "Types.h"
#include "Move_Generator/Move_Receiver.h"

namespace Kangaroo::Movement_Generator {


    template<Board_Status status>
    [[nodiscard]] constexpr std::size_t generate_knight_moves() {
        using enum Color;
        using enum Chess_Pieces;
        using enum Move_Type;

        return 0;

    }



}


#endif //MOVEMENT_GENERATOR_H
