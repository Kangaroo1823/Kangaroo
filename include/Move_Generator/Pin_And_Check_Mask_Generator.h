//
// Created by peter on 26/01/2025.
//

#ifndef PIN_AND_CHECK_MASK_GENERATOR_H
#define PIN_AND_CHECK_MASK_GENERATOR_H

#include "Bit_Board.h"
#include "Chess_Board.h"
#include "Constants.h"


namespace Kangaroo {
    class Chess_Board;
}

namespace Kangaroo::Move_Generator {

    template<Color color_to_move>
    class Pin_And_Check_Mask_Generator {
    public:
        constexpr explicit Pin_And_Check_Mask_Generator(Chess_Board *board) : m_board(board) {
            generate_pin_and_check_mask();
        }

        constexpr Pin_And_Check_Mask_Generator(const Pin_And_Check_Mask_Generator &gen) = default;

        _ForceInline constexpr void generate_pin_and_check_mask() {
            using enum Pin_Masks_Suitable_For;

            build_pin_masks<Detecting_Pins>();
            build_pin_masks<Detecting_Check>();
        };

        [[nodiscard]] _ForceInline constexpr Bitboard get_pin_mask_HV() const {
            return pin_mask_HV;
        }

        [[nodiscard]] _ForceInline constexpr Bitboard get_pin_mask_D() const {
            return pin_mask_D;
        }

        [[nodiscard]] _ForceInline constexpr Bitboard get_check_mask() const {
            return check_mask;
        }

        [[nodiscard]] _ForceInline constexpr Chess_Board *get_board() const {
            return m_board;
        }
    private:
        Chess_Board *m_board;

        // pin-masks to detect pinned pieces
        Bitboard pin_mask_HV = 0ULL;
        Bitboard pin_mask_D = 0ULL;

        // Bitboard to detect if a King is in check.
        Bitboard check_mask = 0ULL;


        template<Chess_Pieces slider, Pin_Masks_Suitable_For purpose>
        _ForceInline constexpr void update_pin_mask_for_movement_like(const Square king_position,
                                                                      const Bitboard rooks_remaining) {
            using enum Chess_Pieces;
            using enum Color;

            static_assert(
                purpose == Pin_Masks_Suitable_For::Detecting_Pins ||
                purpose == Pin_Masks_Suitable_For::Detecting_Check);

            // compute position of current Rook
            const Square rook_position = square_of(rooks_remaining);

            // compute the pin-ray between the Rook and the King
            const Bitboard ray = get_pin_ray_for<slider>(king_position, rook_position);

            const auto pieces_in_intersection = Bitcount(ray & total_pieces_for(*m_board));

            const auto player_pieces_in_intersection = Bitcount(
                ray & all_pieces_for(*m_board, color_to_move));

            // check if count of set bits in the intersection of the ray with all_pieces is two and that the piece in
            // between is of the same color as the King.
            if (pieces_in_intersection == std::to_underlying(purpose) &&
                player_pieces_in_intersection == std::to_underlying(purpose) - 1) {
                if constexpr (purpose == Pin_Masks_Suitable_For::Detecting_Pins) {
                    // In case it is, we should add the ray to the pin-mask since there are two pieces in the ray:
                    // - one is at piece_position (Rook or Queen)
                    // - and one other piece.
                    // Therefore, the other piece is pinned, and we need to add the ray to te pin-mask.

                    if constexpr (slider == Rook) {
                        pin_mask_HV |= ray;
                    } else if constexpr (slider == Bishop) {
                        pin_mask_D |= ray;
                    }
                } else if constexpr (purpose == Pin_Masks_Suitable_For::Detecting_Check) {
                    // When the Bitcount equals one, it means that it is a check situation!
                    check_mask |= ray;
                }
            }
        }

        /**
    * @brief Computes the pin masks for the current board state.
    *
    * In case `purpose` equals `Pin_Masks_Suitable_For::Detecting_Pins` this method
    * calculates the horizontal/vertical (HV) and diagonal (D) pin masks
    * for the specified color of the King based on the positions and possible movements
    * of rooks, bishops, and queens of the opposite color.
    *
    * These pin masks are used to identify pieces on the same line or diagonal as the
    * King which cannot move freely due to the threat of exposing the King to a check.
    *
    * In case `purpose` equals `Pin_Masks_Suitable_For::Detecting_Check` this method computes
    * if a sliding piece of the opposite color poses check to the King of color `color`.
    *
    * @tparam purpose A purpose or configuration type that defines special pin-mask
    *                 requirements.
    *
    * @note This method assumes the presence of a valid board configuration where all
    *       game rules are respected.
    *
    */
        template<Pin_Masks_Suitable_For purpose>
        _ForceInline constexpr void build_pin_masks() {
            using enum Color;
            using enum Chess_Pieces;
            using enum Pin_Masks_Suitable_For;

            static_assert(color_to_move == White || color_to_move == Black, "Invalid color");
            static_assert(purpose == Detecting_Pins || purpose == Detecting_Check, "Invalid purpose");

            // reset the pin masks
            if constexpr (purpose == Detecting_Pins) {
                pin_mask_D = pin_mask_HV = 0ULL;
            } else if constexpr (purpose == Detecting_Check) {
                check_mask = 0ULL;
            }

            // compute King position
            const Square king_position = square_of(bitboard_for(*m_board, color_to_move, King));

            // loop over all the rooks of opposite color
            Bitloop(bitboard_for(*m_board, enemy(color_to_move), Rook), rooks_remaining) {
                // change the HV-pin-mask, if necessary
                update_pin_mask_for_movement_like<Rook, purpose>(king_position, rooks_remaining);
            }

            // loop over all the queens of opposite color
            Bitloop(bitboard_for(*m_board, enemy(color_to_move), Queen), queens_remaining) {
                // change the HV-pin-mask, if necessary
                update_pin_mask_for_movement_like<Rook, purpose>(king_position, queens_remaining);

                // change the D-pin-mask, if necessary
                update_pin_mask_for_movement_like<Bishop, purpose>(king_position, queens_remaining);
            }

            // loop over all the bishops of opposite color
            Bitloop(bitboard_for(*m_board, enemy(color_to_move), Bishop), bishops_remaining) {
                // change the D-pin-mask, if necessary
                update_pin_mask_for_movement_like<Bishop, purpose>(king_position, bishops_remaining);
            }
        }
    };
} // Kangaroo

#endif //PIN_AND_CHECK_MASK_GENERATOR_H
