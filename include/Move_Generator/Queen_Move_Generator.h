//
// Created by peter on 2/22/25.
//

#ifndef QUEEN_MOVE_GENERATOR_H
#define QUEEN_MOVE_GENERATOR_H

#include "Board_Status.h"
#include "Callback_Handler.h"
#include "Constants.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class
        CallbackType>

    class Queen_Move_Generator : public virtual Pin_And_Check_Mask_Generator<status.color_to_move> {
    public:
        constexpr explicit
        Queen_Move_Generator(Chess_Board *board) : Pin_And_Check_Mask_Generator<status.color_to_move>(board) {
        }

        constexpr explicit
        Queen_Move_Generator(
            const Pin_And_Check_Mask_Generator<status.color_to_move> &pac_gen) : Pin_And_Check_Mask_Generator<status.
            color_to_move>(pac_gen) {
        }

        template<Move_Generation_Mode mode, typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_queen_moves(Args... args) {
            static_assert(status.color_to_move == Color::White || status.color_to_move == Color::Black);
            static_assert(mode == Move_Generation_Mode::Normal_Move_Generation ||
                          mode == Move_Generation_Mode::Pin_D_Move_Generation  ||
                          mode == Move_Generation_Mode::Pin_HV_Move_Generation );

            using enum Move_Generation_Mode;
            using enum Chess_Pieces;

            std::size_t moves = 0;

            Bitboard queens =
                    bitboard_for(*this->get_board(), status.color_to_move, Queen);

            if constexpr (mode == Pin_D_Move_Generation) {
                queens &= this->get_pin_mask_D();
            } else if constexpr (mode == Pin_HV_Move_Generation) {
                queens &= this->get_pin_mask_HV();
            } else {
                queens &= ~(this->get_pin_mask_D() | this->get_pin_mask_HV());
            }

            Bitloop(queens, queens_remaining) {
                const Bitboard from = bitboard_square_of(queens_remaining);
                const Square from_square = square_of(queens_remaining);
                Bitboard possible_queen_moves = (get_attacks_for<Bishop>(from_square, total_pieces_for(*this->get_board())) |
                get_attacks_for<Rook>(from_square, total_pieces_for(*this->get_board())))
                                               & ~all_pieces_for(*this->get_board(), status.color_to_move);

                if constexpr (mode == Pin_D_Move_Generation) {
                    possible_queen_moves &= this->get_pin_mask_D();
                }

                if constexpr (mode == Pin_HV_Move_Generation) {
                    possible_queen_moves &= this->get_pin_mask_HV();
                }

                if constexpr (status.check_p) {
                    possible_queen_moves &= this->get_check_mask();
                }

                Bitboard possible_queen_captures = possible_queen_moves & all_pieces_for(
                                                      *this->get_board(), enemy(status.color_to_move));
                possible_queen_moves = possible_queen_moves ^ possible_queen_captures;

                Bitloop(possible_queen_moves, possible_queen_moves_remaining) {
                    Bitboard to = bitboard_square_of(possible_queen_moves_remaining);

                    Callback_Handler<status, Move_Type::Normal, Queen, CallbackType, Args
                        ...>::handle_callback(this->get_board(), from, to, args...);
                    ++moves; // -V779
                }

                Bitloop(possible_queen_captures, possible_rook_captures_remaining) {
                    Bitboard to = bitboard_square_of(possible_rook_captures_remaining);
                    Callback_Handler<status, Move_Type::Capture, Queen, CallbackType, Args
                        ...>::handle_callback(this->get_board(), from, to, args...);
                    ++moves;
                }
            }

            return moves;
        }
    };
}


#endif //QUEEN_MOVE_GENERATOR_H
