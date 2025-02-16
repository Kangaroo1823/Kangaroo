//
// Created by peter on 2/16/25.
//

#ifndef KNIGHT_MOVE_GENERATOR_H
#define KNIGHT_MOVE_GENERATOR_H
#include "Board_Status.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class
        CallbackType>

    class Knight_Move_Generator : public virtual Pin_And_Check_Mask_Generator<status.color_to_move> {
    public:
        constexpr explicit Knight_Move_Generator(Chess_Board* board) : Pin_And_Check_Mask_Generator<status.color_to_move>(board) {}
        constexpr explicit Knight_Move_Generator(const Pin_And_Check_Mask_Generator<status.color_to_move> &pac_gen) : Pin_And_Check_Mask_Generator<status.color_to_move>(pac_gen) {}

        template<Move_Generation_Mode mode, typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_knight_moves(Args... args) {
            std::size_t moves = 0;
            return moves;
        }
    };
}

#endif //KNIGHT_MOVE_GENERATOR_H
