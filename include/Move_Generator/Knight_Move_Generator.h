//
// Created by peter on 2/16/25.
//

#ifndef KNIGHT_MOVE_GENERATOR_H
#define KNIGHT_MOVE_GENERATOR_H

#include "Board_Status.h"
#include "Chess_Board.h"
#include "constants_attacks.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class
        CallbackType>

    class Knight_Move_Generator : public virtual Pin_And_Check_Mask_Generator<status.color_to_move> {
    public:
        constexpr explicit Knight_Move_Generator(Chess_Board* board) : Pin_And_Check_Mask_Generator<status.color_to_move>(board) {}
        constexpr explicit Knight_Move_Generator(const Pin_And_Check_Mask_Generator<status.color_to_move> &pac_gen) : Pin_And_Check_Mask_Generator<status.color_to_move>(pac_gen) {}

        template<Move_Generation_Mode mode, typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_knight_moves(Args... args) {

            using enum Move_Generation_Mode;
            using enum Chess_Pieces;

            std::size_t moves = 0;

            Bitboard knights = bitboard_for(*this->get_board(), status.color_to_move, Knight) & ~(this->get_pin_mask_D() | this->get_pin_mask_HV());

            Bitloop(knights, knights_remaining) {
                Bitboard knight = bitboard_square_of(knights_remaining);
                Bitboard possible_night_moves = Constants::knight_attacks[knight] & !all_pieces_for(*this->get_board(), status.color_to_move);

                Bitloop(possible_night_moves, possible_night_moves_remaining) {
                    Bitboard to = bitboard_square_of(possible_night_moves_remaining);

                    if ( to & all_pieces_for(*this->get_board(), enemy(status.color_to_move))) {

                    } else {

                    }

                }

            }

            return moves;
        }
    };
}

#endif //KNIGHT_MOVE_GENERATOR_H
