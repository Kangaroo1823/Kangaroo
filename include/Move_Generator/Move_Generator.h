//
// Created by peter on 26/01/2025.
//

#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#endif //MOVE_GENERATOR_H

#include "Pawn_Move_Generator.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType>
    class Move_Generator : public Pawn_Move_Generator<status, CallbackType> {
    public:
        constexpr explicit Move_Generator(Chess_Board *board)
            : Pin_And_Check_Mask_Generator<status>(board)
              , Pawn_Move_Generator<status, CallbackType>(board) {
        }

        template<typename ...Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_movements(Args... args) {
            using enum Move_Generation_Mode;

            // pawn move generation
            uint64_t moves = this->template generate_pawn_moves<Normal_Move_Generation>(args...);
            moves += this->template generate_pawn_moves<Pin_HV_Move_Generation>(args...);
            moves += this->template generate_pawn_moves<Pin_D_Move_Generation>(args...);
            moves += this->template generate_pawn_moves<Promotion_Move_Generation>(args...);

            return moves;
        }

        template<typename ...Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_moves(Args... args) {
            std::size_t moves = this->generate_pawn_movments(args...);

            return moves;
        }

    };
}
