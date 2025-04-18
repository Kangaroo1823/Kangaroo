//
// Created by peter on 2/22/25.
//

#ifndef ROOK_MOVE_GENERATOR_H
#define ROOK_MOVE_GENERATOR_H

#include "Board_Status.h"
#include "Callback_Handler.h"
#include "Constants.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class
        CallbackType>

    class Bishop_Move_Generator : public virtual Pin_And_Check_Mask_Generator<status.color_to_move> {
    public:
        constexpr explicit
        Bishop_Move_Generator(Chess_Board *board) : Pin_And_Check_Mask_Generator<status.color_to_move>(board) {
        }

        constexpr explicit
        Bishop_Move_Generator(
            const Pin_And_Check_Mask_Generator<status.color_to_move> &pac_gen) : Pin_And_Check_Mask_Generator<status.
            color_to_move>(pac_gen) {
        }

        template<Move_Generation_Mode mode, typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_rook_moves(Args... args) {
            static_assert(status.color_to_move == Color::White || status.color_to_move == Color::Black);
            static_assert(mode == Move_Generation_Mode::Normal_Move_Generation |
                          mode == Move_Generation_Mode::Pin_D_Move_Generation );

            using enum Move_Generation_Mode;
            using enum Chess_Pieces;

            std::size_t moves = 0;

            Bitboard bishops =
                    bitboard_for(*this->get_board(), status.color_to_move, Bishop);

            if constexpr (mode == Pin_D_Move_Generation) {
                bishops &= this->get_pin_mask_D();
            } else {
                bishops &= ~(this->get_pin_mask_D() | this->get_pin_mask_HV());
            }

            Bitloop(bishops, bishops_remaining) {
                const Bitboard from = bitboard_square_of(bishops_remaining);
                const Square from_square = square_of(bishops_remaining);
                Bitboard possible_bishop_moves = get_attacks_for<Bishop>(from_square, total_pieces_for(*this->get_board()))
                                               & ~all_pieces_for(*this->get_board(), status.color_to_move);

                if constexpr (mode == Pin_D_Move_Generation) {
                    possible_bishop_moves &= this->get_pin_mask_D();
                }

                if constexpr (status.check_p) {
                    possible_bishop_moves &= this->get_check_mask();
                }

                Bitboard possible_bishop_captures = possible_bishop_moves & all_pieces_for(
                                                      *this->get_board(), enemy(status.color_to_move));
                possible_bishop_moves = possible_bishop_moves ^ possible_bishop_captures;

                Bitloop(possible_bishop_moves, possible_bishop_moves_remaining) {
                    Bitboard to = bitboard_square_of(possible_bishop_moves_remaining);

                    Callback_Handler<status, Move_Type::Normal, Bishop, CallbackType, Args
                        ...>::handle_callback(this->get_board(), from, to, args...);
                    ++moves; // -V779
                }

                Bitloop(possible_bishop_captures, possible_rook_captures_remaining) {
                    Bitboard to = bitboard_square_of(possible_rook_captures_remaining);
                    Callback_Handler<status, Move_Type::Capture, Bishop, CallbackType, Args
                        ...>::handle_callback(this->get_board(), from, to, args...);
                    ++moves;
                }
            }

            return moves;
        }
    };
}


#endif //ROOK_MOVE_GENERATOR_H
