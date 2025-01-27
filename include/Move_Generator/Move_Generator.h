//
// Created by peter on 26/01/2025.
//

#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#endif //MOVE_GENERATOR_H

#include "Pawn_Move_Generator.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces> class CallbackType>
    class Move_Generator : public Pawn_Move_Generator<status, CallbackType> {
    public:
        constexpr explicit Move_Generator(Chess_Board *board)
            : Pin_And_Check_Mask_Generator<status>(board)
              , Pawn_Move_Generator<status, CallbackType>(board) {
        }

        [[nodiscard]] constexpr std::size_t generate_moves() {
            using enum Move_Generation_Mode;
            using enum Pin_Masks_Suitable_For;

            // pawn move generation
            uint64_t moves = this->template generate_pawn_moves<Normal_Move_Generation>();
            moves += this->template generate_pawn_moves<Pin_HV_Move_Generation>();
            moves += this->template generate_pawn_moves<Pin_D_Move_Generation>();
            moves += this->template generate_pawn_moves<Promotion_Move_Generation>();

            return moves;
        }
    };
}
