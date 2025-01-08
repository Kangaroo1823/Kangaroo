//
// Created by U439644 on 1/8/2025.
//

#ifndef MOVEMENT_GENERATOR_H
#define MOVEMENT_GENERATOR_H
#include "chess_board.h"

namespace Kangaroo {

    class Movement_Generator {

        FRIEND_TEST(Movement_Generator_Test, test_pin_masks_generator);

        Chess_Board *board_p;

        // pin-masks to detect pinned pieces
        Bitboard pin_mask_HV = 0ULL;
        Bitboard pin_mask_D = 0ULL;

        // Bitboard to detect if a king is in check.
        Bitboard check_mask = 0ULL;

    public:
        explicit Movement_Generator(Chess_Board *board) : board_p(board) {
        }

    private:

        template<Slider slider, Pin_Masks_Suitable_For purpose, Color color>
        _ForceInline constexpr void update_pin_mask_for_movement_like(const Square king_position,
                                                                      const Bitboard rooks_remaining) {
            using enum Slider;
            using enum Color;

            static_assert(
                purpose == Pin_Masks_Suitable_For::detecting_pins ||
                purpose == Pin_Masks_Suitable_For::detecting_check);

            // compute position of current rook
            const Square rook_position = square_of(rooks_remaining);

            // compute the pin-ray between the rook and the king
            const Bitboard ray = get_pin_ray_for<slider>(king_position, rook_position);

            const auto pieces_in_intersection = Bitcount(ray & board_p->all_pieces());

            const auto player_pieces_in_intersection = Bitcount(
                ray & (color == white ? board_p->white_pieces() : board_p->black_pieces()));

            // check if count of set bits in the intersection of the ray with all_pieces is two and that the piece in
            // between is of the same color as the king.
            if (pieces_in_intersection == std::to_underlying(purpose) &&
                player_pieces_in_intersection == std::to_underlying(purpose) - 1) {
                if constexpr (purpose == Pin_Masks_Suitable_For::detecting_pins) {
                    // In case it is, we should add the ray to the pin-mask since there are two pieces in the ray:
                    // - one is at piece_position (rook or queen)
                    // - and one other piece.
                    // Therefore, the other piece is pinned, and we need to add the ray to te pin-mask.

                    if constexpr (slider == rook) {
                        pin_mask_HV |= ray;
                    } else if (slider == bishop) {
                        pin_mask_D |= ray;
                    }
                } else if constexpr (purpose == Pin_Masks_Suitable_For::detecting_check) {
                    // When the Bitcount equals one, it means that it is a check situation!
                    check_mask |= ray;
                }
            }
        }


        /**
         * @brief Computes the pin masks for the current board state.
         *
         * In case `purpose` equals `Pin_Masks_Suitable_For::detecting_pins` this method
         * calculates the horizontal/vertical (HV) and diagonal (D) pin masks
         * for the specified color of the king based on the positions and possible movements
         * of rooks, bishops, and queens of the opposite color.
         *
         * These pin masks are used to identify pieces on the same line or diagonal as the
         * king which cannot move freely due to the threat of exposing the king to a check.
         *
         * In case `purpose` equals `Pin_Masks_Suitable_For::detecting_check` this method computes
         * if a sliding piece of the opposite color poses check to the king of color `color`.
         *
         * @tparam color_of_king The color of the king for which the pin masks are being calculated.
         *               Must be either `Color::white` or `Color::black`.
         * @tparam purpose A purpose or configuration type that defines special pin-mask
         *                 requirements.
         *
         * @note This method assumes the presence of a valid board configuration where all
         *       game rules are respected.
         *
         * @throws static_assert if `color` or `purpose` is not valid.
         */
        template<Color color_of_king, Pin_Masks_Suitable_For purpose>
        _ForceInline constexpr void build_pin_masks() {
            using enum Color;
            using enum Slider;

            static_assert(color_of_king == white || color_of_king == black, "Invalid color");
            static_assert(
                purpose == Pin_Masks_Suitable_For::detecting_pins ||
                purpose == Pin_Masks_Suitable_For::detecting_check, "Invalid purpose");

            // reset the pin masks
            if constexpr (purpose == Pin_Masks_Suitable_For::detecting_pins) {
                pin_mask_D = pin_mask_HV = 0ULL;
            } else if constexpr (purpose == Pin_Masks_Suitable_For::detecting_check) {
                check_mask = 0ULL;
            }

            // compute king position
            const Square king_position = square_of(color_of_king == white ? board_p->white_king() : board_p->black_king());

            // loop over all the rooks of opposite color
            Bitloop(color_of_king == white ? board_p->black_rooks() : board_p->white_rooks(), rooks_remaining) {
                // change the HV-pin-mask, if necessary
                update_pin_mask_for_movement_like<rook, purpose, color_of_king>(king_position, rooks_remaining);
            }

            // loop over all the queens of opposite color
            Bitloop(color_of_king == white ? board_p->black_queens() : board_p->white_queens(), queens_remaining) {
                // change the HV-pin-mask, if necessary
                update_pin_mask_for_movement_like<rook, purpose, color_of_king>(king_position, queens_remaining);

                // change the D-pin-mask, if necessary
                update_pin_mask_for_movement_like<bishop, purpose, color_of_king>(king_position, queens_remaining);
            }

            // loop over all the bishops of opposite color
            Bitloop(color_of_king == white ? board_p->black_bishops() : board_p->white_bishops(), bishops_remaining) {
                // change the D-pin-mask, if necessary
                update_pin_mask_for_movement_like<bishop, purpose, color_of_king>(king_position, bishops_remaining);
            }
        }
    };
} // Kangaroo

#endif //MOVEMENT_GENERATOR_H
