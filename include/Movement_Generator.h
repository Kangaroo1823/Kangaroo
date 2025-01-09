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

        _ForceInline constexpr Bitboard get_pin_mask_HV() const {
            return pin_mask_HV;
        }

        _ForceInline constexpr Bitboard get_pin_mask_D() const {
            return pin_mask_D;
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
            const Square king_position = square_of(color_of_king == white
                                                       ? board_p->white_king()
                                                       : board_p->black_king());

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

        template<typename CallBack>
        [[nodiscard]] _ForceInline constexpr std::size_t run_move_generation(CallBack callback) {
            switch (board_p->get_flags()) {
                case 0x00: return generate_moves<Board_Status(0x00)>(callback);
                case 0x01: return generate_moves<Board_Status(0x01)>(callback);
                case 0x02: return generate_moves<Board_Status(0x02)>(callback);
                case 0x03: return generate_moves<Board_Status(0x03)>(callback);
                case 0x04: return generate_moves<Board_Status(0x04)>(callback);
                case 0x05: return generate_moves<Board_Status(0x05)>(callback);
                case 0x06: return generate_moves<Board_Status(0x06)>(callback);
                case 0x07: return generate_moves<Board_Status(0x07)>(callback);
                case 0x08: return generate_moves<Board_Status(0x08)>(callback);
                case 0x09: return generate_moves<Board_Status(0x09)>(callback);
                case 0x0a: return generate_moves<Board_Status(0x0a)>(callback);
                case 0x0b: return generate_moves<Board_Status(0x0b)>(callback);
                case 0x0c: return generate_moves<Board_Status(0x0c)>(callback);
                case 0x0d: return generate_moves<Board_Status(0x0d)>(callback);
                case 0x0e: return generate_moves<Board_Status(0x0e)>(callback);
                case 0x0f: return generate_moves<Board_Status(0x0f)>(callback);
                case 0x10: return generate_moves<Board_Status(0x10)>(callback);
                case 0x11: return generate_moves<Board_Status(0x11)>(callback);
                case 0x12: return generate_moves<Board_Status(0x12)>(callback);
                case 0x13: return generate_moves<Board_Status(0x13)>(callback);
                case 0x14: return generate_moves<Board_Status(0x14)>(callback);
                case 0x15: return generate_moves<Board_Status(0x15)>(callback);
                case 0x16: return generate_moves<Board_Status(0x16)>(callback);
                case 0x17: return generate_moves<Board_Status(0x17)>(callback);
                case 0x18: return generate_moves<Board_Status(0x18)>(callback);
                case 0x19: return generate_moves<Board_Status(0x19)>(callback);
                case 0x1a: return generate_moves<Board_Status(0x1a)>(callback);
                case 0x1b: return generate_moves<Board_Status(0x1b)>(callback);
                case 0x1c: return generate_moves<Board_Status(0x1c)>(callback);
                case 0x1d: return generate_moves<Board_Status(0x1d)>(callback);
                case 0x1e: return generate_moves<Board_Status(0x1e)>(callback);
                case 0x1f: return generate_moves<Board_Status(0x1f)>(callback);
                case 0x20: return generate_moves<Board_Status(0x20)>(callback);
                case 0x21: return generate_moves<Board_Status(0x21)>(callback);
                case 0x22: return generate_moves<Board_Status(0x22)>(callback);
                case 0x23: return generate_moves<Board_Status(0x23)>(callback);
                case 0x24: return generate_moves<Board_Status(0x24)>(callback);
                case 0x25: return generate_moves<Board_Status(0x25)>(callback);
                case 0x26: return generate_moves<Board_Status(0x26)>(callback);
                case 0x27: return generate_moves<Board_Status(0x27)>(callback);
                case 0x28: return generate_moves<Board_Status(0x28)>(callback);
                case 0x29: return generate_moves<Board_Status(0x29)>(callback);
                case 0x2a: return generate_moves<Board_Status(0x2a)>(callback);
                case 0x2b: return generate_moves<Board_Status(0x2b)>(callback);
                case 0x2c: return generate_moves<Board_Status(0x2c)>(callback);
                case 0x2d: return generate_moves<Board_Status(0x2d)>(callback);
                case 0x2e: return generate_moves<Board_Status(0x2e)>(callback);
                case 0x2f: return generate_moves<Board_Status(0x2f)>(callback);
                case 0x30: return generate_moves<Board_Status(0x30)>(callback);
                case 0x31: return generate_moves<Board_Status(0x31)>(callback);
                case 0x32: return generate_moves<Board_Status(0x32)>(callback);
                case 0x33: return generate_moves<Board_Status(0x33)>(callback);
                case 0x34: return generate_moves<Board_Status(0x34)>(callback);
                case 0x35: return generate_moves<Board_Status(0x35)>(callback);
                case 0x36: return generate_moves<Board_Status(0x36)>(callback);
                case 0x37: return generate_moves<Board_Status(0x37)>(callback);
                case 0x38: return generate_moves<Board_Status(0x38)>(callback);
                case 0x39: return generate_moves<Board_Status(0x39)>(callback);
                case 0x3a: return generate_moves<Board_Status(0x3a)>(callback);
                case 0x3b: return generate_moves<Board_Status(0x3b)>(callback);
                case 0x3c: return generate_moves<Board_Status(0x3c)>(callback);
                case 0x3d: return generate_moves<Board_Status(0x3d)>(callback);
                case 0x3e: return generate_moves<Board_Status(0x3e)>(callback);
                case 0x3f: return generate_moves<Board_Status(0x3f)>(callback);
                case 0x40: return generate_moves<Board_Status(0x40)>(callback);
                default: throw std::runtime_error("Invalid board status");
            }
        }

        template<Kangaroo::Board_Status status, typename CallBackType>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_moves(CallBackType callback) {
            build_pin_masks<status.color_p, Pin_Masks_Suitable_For::detecting_pins>();

            return generate_pawn_moves<status>(callback);
        }

    private:
        // template<Color color>
        // [[nodiscard]] static _ForceInline constexpr bool is_double_pawn_push_admissible(
        //     const Bitboard pawn, const Bitboard pawn_move,
        //     const Bitboard &occupied_squares) {
        //     if (pawn & pawn_base_row<color>()) {
        //         return (pawn_move & occupied_squares) == 0;
        //     }
        //
        //     return false;
        // }

        [[nodiscard]] _ForceInline constexpr bool is_pawn_push_admissible(
            Bitboard pawn_origin, Bitboard pawn_move, const Bitboard &occupied_squares) const {
            const bool ret = (pawn_move & occupied_squares) == 0;
            const bool p = (pawn_origin & pin_mask_HV) == 0 || (pawn_move & pin_mask_HV) != 0;
            return ret && p && (pawn_origin & pin_mask_D) == 0;
        }

        template<Kangaroo::Board_Status status, typename CallBackType>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_double_pawn_pushs(
            CallBackType callback, const Bitboard pawn) const {
            std::size_t moves = 0ULL;
            if (pawn & pawn_base_row<status.color_p>()) {
                if (const Bitboard moved_pawn_2 = double_pawn_push<status.color_p>(pawn); is_pawn_push_admissible(pawn,
                    moved_pawn_2, board_p->all_pieces())) {
                    callback(status.color_p == Color_t::white ? Chess_Pieces_t::white_pawn : Chess_Pieces_t::black_pawn,
                             make_move(pawn, moved_pawn_2));
                    ++moves;
                }
            }
            return moves;
        }

        template<Kangaroo::Board_Status status, typename CallBackType>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_captures(
            CallBackType callback, const std::size_t pawn_square, const Bitboard pawn) const {
            std::size_t moves = 0ULL;
            Bitboard mask = (status.color_p == Color_t::white
                                 ? Constants::white_pawn_attacks[pawn_square] & board_p->black_pieces()
                                 : Constants::black_pawn_attacks[pawn_square] & board_p->white_pieces());

            // see if we can capture anything
            Bitloop(mask, pawn_attacks) {
                Bitboard pawn_attack = 1ULL << std::to_underlying(square_of(pawn_attacks));
                callback(status.color_p == Color_t::white ? Chess_Pieces_t::white_pawn : Chess_Pieces_t::black_pawn,
                         make_move(pawn, pawn_attack));
                ++moves;
            }
            return moves;
        }

        template<Kangaroo::Board_Status status, typename CallBackType>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_moves(CallBackType callback) const {
            using enum Color_t;
            using enum Chess_Pieces;

            std::size_t moves = 0ULL;

            Bitboard pawns = status.color_p == white ? board_p->white_pawns() : board_p->black_pawns();

            Bitloop(pawns, pawns_remaining) {
                using enum Color_t;
                using enum Chess_Pieces;

                const std::size_t pawn_square = std::to_underlying(square_of(pawns_remaining));
                const Bitboard pawn = 1ULL << pawn_square;

                // single move for pawns
                if (const Bitboard moved_pawn = regular_pawn_push<status.color_p>(pawn); is_pawn_push_admissible(pawn,
                    moved_pawn, board_p->all_pieces())) {
                    callback(status.color_p == white ? white_pawn : black_pawn,
                             make_move(pawn, moved_pawn));
                    ++moves;

                    // double move for pawns in base row
                    moves += generate_double_pawn_pushs<status, CallBackType>(callback, pawn);
                }

                moves += generate_pawn_captures<status, CallBackType>(callback, pawn_square, pawn);
            }
            return moves;
        }


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
    };
} // Kangaroo

#endif //MOVEMENT_GENERATOR_H
