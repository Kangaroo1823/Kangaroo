//
// Created by peter on 2/16/25.
//

#ifndef KNIGHT_MOVE_GENERATOR_H
#define KNIGHT_MOVE_GENERATOR_H

#include "Board_Status.h"
#include "Callback_Handler.h"
#include "Chess_Board.h"
#include "constants_attacks.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class
        CallbackType>

    class Knight_Move_Generator : public virtual Pin_And_Check_Mask_Generator<status.color_to_move> {
    public:
        constexpr explicit
        Knight_Move_Generator(Chess_Board *board) : Pin_And_Check_Mask_Generator<status.color_to_move>(board) {
        }

        constexpr explicit
        Knight_Move_Generator(
            const Pin_And_Check_Mask_Generator<status.color_to_move> &pac_gen) : Pin_And_Check_Mask_Generator<status.
            color_to_move>(pac_gen) {
        }

        template<Move_Generation_Mode mode, typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_knight_moves(Args... args) {

            static_assert(status.color_to_move == Color::White || status.color_to_move == Color::Black);
            static_assert(mode == Move_Generation_Mode::Normal_Move_Generation);

            using enum Move_Generation_Mode;
            using enum Chess_Pieces;

            std::size_t moves = 0;

            if constexpr (mode == Normal_Move_Generation) {
                Bitboard knights =
                        bitboard_for(*this->get_board(), status.color_to_move, Knight) & ~(
                            this->get_pin_mask_D() | this->get_pin_mask_HV());

                Bitloop(knights, knights_remaining) {
                    const Bitboard from = bitboard_square_of(knights_remaining);
                    Bitboard possible_night_moves = Constants::knight_attacks[std::to_underlying(square_of(from))] & ~all_pieces_for( *this->get_board(), status.color_to_move);

                    if constexpr (status.check_p) {
                        possible_night_moves &= this->get_check_mask();
                    }

                    Bitboard possible_night_captures = possible_night_moves & all_pieces_for(
                                                           *this->get_board(), enemy(status.color_to_move));
                    possible_night_moves = possible_night_moves ^ possible_night_captures;

                    Bitloop(possible_night_moves, possible_night_moves_remaining) {
                        Bitboard to = bitboard_square_of(possible_night_moves_remaining);

                        Callback_Handler<status, Move_Type::Normal, Chess_Pieces::Knight, CallbackType, Args
                            ...>::handle_callback(this->get_board(), from, to, args...);
                        ++moves; // -V779
                    }

                    Bitloop(possible_night_captures, possible_night_captures_remaining) {
                        Bitboard to = bitboard_square_of(possible_night_captures_remaining);
                        Callback_Handler<status, Move_Type::Capture, Chess_Pieces::Knight, CallbackType, Args
                            ...>::handle_callback(this->get_board(), from, to, args...);
                        ++moves;
                    }
                }
            }

            return moves;
        }
    };
}

#endif //KNIGHT_MOVE_GENERATOR_H
