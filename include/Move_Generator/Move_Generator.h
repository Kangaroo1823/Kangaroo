//
// Created by peter on 26/01/2025.
//

#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H

#include "Knight_Move_Generator.h"
#include "Rook_Move_Generator.h"
#include "Pawn_Move_Generator.h"

namespace Kangaroo::Move_Generator
{
    template <Color> class Pin_And_Check_Mask_Generator;

    template <Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class
              CallbackType>
    class Move_Generator : public Pawn_Move_Generator<status, CallbackType>
        , public Knight_Move_Generator<status, CallbackType>
        , public Rook_Move_Generator<status, CallbackType>

    {
    public:
        constexpr explicit Move_Generator(Chess_Board* board)
            : Pin_And_Check_Mask_Generator<status.color_to_move>(board)
            , Pawn_Move_Generator<status, CallbackType>(board)
            , Knight_Move_Generator<status, CallbackType>(board)
            , Rook_Move_Generator<status, CallbackType>(board)

        {
        }

        constexpr explicit Move_Generator(const Pin_And_Check_Mask_Generator<status.color_to_move> &pac_gen)
        : Pin_And_Check_Mask_Generator<status.color_to_move>(pac_gen)
        , Pawn_Move_Generator<status, CallbackType>(pac_gen)
        , Knight_Move_Generator<status, CallbackType>(pac_gen)
        , Rook_Move_Generator<status, CallbackType>(pac_gen)
        {
        }

        template<typename ... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_rook_movements(Args... args) {
            using enum Move_Generation_Mode;
            std::size_t moves = 0;
            moves += this->template generate_rook_moves<Normal_Move_Generation>(args...);
            moves += this->template generate_rook_moves<Pin_HV_Move_Generation>(args...);
            return moves;
        }

        template <typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_movements(Args... args)
        {
            using enum Move_Generation_Mode;

            // pawn move generation
            std::size_t moves = 0;
            moves += this->template generate_pawn_moves<Normal_Move_Generation>(args...);
            moves += this->template generate_pawn_moves<Pin_HV_Move_Generation>(args...);
            moves += this->template generate_pawn_moves<Pin_D_Move_Generation>(args...);
            moves += this->template generate_pawn_moves<Promotion_Move_Generation>(args...);

            return moves;
        }

        template<typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_knight_movements(Args... args)
        {
            using enum Move_Generation_Mode;

            std::size_t moves = 0;
            moves += this->template generate_knight_moves<Normal_Move_Generation>(args...);
            return moves;

        }

        template <typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_moves(Args... args)
        {
            std::size_t moves = 0;
            moves += this->generate_pawn_movements(args...);
            moves += this->generate_knight_movements(args...);
            moves += this->generate_rook_movements(args...);

            return moves;
        }
    };
}

#endif //MOVE_GENERATOR_H