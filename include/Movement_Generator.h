//
// Created by U439644 on 1/8/2025.
//

#ifndef MOVEMENT_GENERATOR_H
#define MOVEMENT_GENERATOR_H
#include "chess_board.h"
#include "types.h"
#include "Move_Receiver.h"

namespace Kangaroo {



    class Movement_Generator {
        FRIEND_TEST(Movement_Generator_Test, test_pin_masks_generator);
        FRIEND_TEST(Pawn_Move_Generator, pawn_move_generator_white_pawns_base);
        FRIEND_TEST(Pawn_Move_Generator, pawn_move_generator_black_pawns_base);
        FRIEND_TEST(Pawn_Move_Generator, pawn_move_generator_white_pawn_capture);
        FRIEND_TEST(Pawn_Move_Generator, pawn_move_generator_black_pawn_capture);
        FRIEND_TEST(Movement_Generator_Test, test_pawn_movement_generator);

        Chess_Board *board_p;

        // pin-masks to detect pinned pieces
        Bitboard pin_mask_HV = 0ULL;
        Bitboard pin_mask_D = 0ULL;

        // Bitboard to detect if a King is in check.
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

            static_assert(color_of_king == White || color_of_king == Black, "Invalid color");
            static_assert(
                purpose == Pin_Masks_Suitable_For::Detecting_Pins ||
                purpose == Pin_Masks_Suitable_For::Detecting_Check, "Invalid purpose");

            // reset the pin masks
            if constexpr (purpose == Pin_Masks_Suitable_For::Detecting_Pins) {
                pin_mask_D = pin_mask_HV = 0ULL;
            } else if constexpr (purpose == Pin_Masks_Suitable_For::Detecting_Check) {
                check_mask = 0ULL;
            }

            // compute King position
            const Square king_position = square_of(color_of_king == White
                                                       ? board_p->white_king
                                                       : board_p->black_king);

            // loop over all the rooks of opposite color
            Bitloop(color_of_king == White ? board_p->black_rooks : board_p->white_rooks, rooks_remaining) {
                // change the HV-pin-mask, if necessary
                update_pin_mask_for_movement_like<Rook, purpose, color_of_king>(king_position, rooks_remaining);
            }

            // loop over all the queens of opposite color
            Bitloop(color_of_king == White ? board_p->black_queens : board_p->white_queens, queens_remaining) {
                // change the HV-pin-mask, if necessary
                update_pin_mask_for_movement_like<Rook, purpose, color_of_king>(king_position, queens_remaining);

                // change the D-pin-mask, if necessary
                update_pin_mask_for_movement_like<Bishop, purpose, color_of_king>(king_position, queens_remaining);
            }

            // loop over all the bishops of opposite color
            Bitloop(color_of_king == White ? board_p->black_bishops : board_p->white_bishops, bishops_remaining) {
                // change the D-pin-mask, if necessary
                update_pin_mask_for_movement_like<Bishop, purpose, color_of_king>(king_position, bishops_remaining);
            }
        }


        template<Kangaroo::Board_Status status, typename CallBackType>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_moves(CallBackType callback) {
            using enum Move_Generation_Mode;
            using enum Pin_Masks_Suitable_For;

            build_pin_masks<status.color_to_move, Detecting_Pins>();

            uint64_t moves = generate_pawn_moves<status.copy_and_set_mode(Normal_Move_Generation)>(callback);

            moves += generate_pawn_moves<status.copy_and_set_mode(Pin_HV_Move_Generation)>(callback);

            moves += generate_pawn_moves<status.copy_and_set_mode(Pin_D_Move_Generation)>(callback);

            moves += generate_pawn_moves<status.copy_and_set_mode(Promotion_Move_Generation)>(callback);

            return moves;
        }

    private:
        /**
         * checks if a move is admissible.
         * 
         * @tparam mode current phase of movement generation. Valid values are:
         *                      -   pin_HV_move_generation. Generation of moves of HV pinned pieces.
         *                      -   check_move_generation. Generation of moves in a check situation.
         *                      -   normal_move_generation. Generation of regular moves.
         *
         * @param pawn_origin  a bitboard with a single set bit at the position where the pawn 'starts' its move
         * @param pawn_move a bitboard with a single set bit at the position where the pawn 'ends' its move.
         * @param occupied_squares a bitboard with bits set where pieces are on the chess board.
         * @return true if and only if the move is admissible.
         */
        template<Move_Generation_Mode mode>
        [[nodiscard]] _ForceInline constexpr bool is_pawn_push_admissible(
            const Bitboard pawn_origin, const Bitboard pawn_move, const Bitboard occupied_squares) const {
            using enum Move_Generation_Mode;

            static_assert(mode == Normal_Move_Generation || mode == Check_Move_Generation ||
                          mode == Pin_HV_Move_Generation);

            const bool ret = (pawn_move & occupied_squares) == 0;
            if constexpr (mode == Normal_Move_Generation || mode == Check_Move_Generation) {
                return ret;
            } else if constexpr (mode == Pin_HV_Move_Generation) {
                const bool p = (pawn_origin & pin_mask_HV) == 0 || (pawn_move & pin_mask_HV) != 0;
                return ret && p && (pawn_origin & pin_mask_D) == 0;
            }
            return false;
        }

        /**
         * Generates a double Pawn push if admissible. Assumes that a single Pawn push is admissible.
         *
         * @tparam status an instances of the Board_Status class indicating the status of move generation
         * @tparam CallBackType type of the callback function.
         * @param callback the call function
         * @param pawn a Bitboard with a single set bit at the position corresponding to the square where the
         *              pawn in question is currently located.
         * @return Returns the number of moves generated.
         */
        template<Kangaroo::Board_Status status, typename CallBackType>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_double_pawn_pushs(
            CallBackType callback, const Bitboard pawn) const {
            std::size_t moves = 0ULL;

            // check if the Pawn is in the base row.
            if (pawn & pawn_base_row<status.color_to_move>()) {
                // if so, check if a double Pawn push is admissible.
                if (const Bitboard moved_pawn_2 = double_pawn_push<status.color_to_move>(pawn);
                    is_pawn_push_admissible<status.mode>(pawn,
                                                         moved_pawn_2, board_p->all_pieces)) {
                    // make the move and call the callback function.
                    Move_Receiver<status, Move_Type::Normal, Chess_Pieces::Pawn,
                        CallBackType>::evaluate_and_perform_move(board_p, callback, pawn, moved_pawn_2);

                    // increment the number of moves generated.
                    ++moves;
                }
            }

            // return the number of moves generated.
            return moves;
        }

        /**
         * Generates Pawn captures.
         * @tparam status an instance of the Board_Status class indicating the current state of move generation.
         * @tparam CallBackType The type of the callback function. Should return void.
         * @param callback The callback function.
         * @param pawn A bitboard with a single set bit at the position of the pawn.
         * @return Returns the number of moves generated.
         */
        template<Kangaroo::Board_Status status, typename CallBackType>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_captures(
            CallBackType callback, const Bitboard pawn) const {
            using enum Color;
            using enum Move_Generation_Mode;
            using enum Move_Type;
            using enum Chess_Pieces;

            // this method is only supposed to be called in Normal_Move_Generation mode or in
            // Check_Move_Generation mode.
            static_assert(
                status.mode == Normal_Move_Generation ||
                status.mode == Check_Move_Generation ||
                status.mode == Promotion_Move_Generation);

            // initialize the number of generated moves with zero.
            std::size_t moves = 0ULL;

            const auto pawn_square = std::to_underlying(square_of(pawn));
            // the squares the Pawn in question can move to should be occupied by the opposite color.
            Bitboard mask = status.color_to_move == White
                                ? Constants::white_pawn_attacks[pawn_square] & board_p->black_pieces
                                : Constants::black_pawn_attacks[pawn_square] & board_p->white_pieces;


            // loop over all such squares
            Bitloop(mask, pawn_attacks) {
                // generate a Bitboard with a single bit set where the Pawn is attacking
                Bitboard pawn_attack = 1ULL << std::to_underlying(square_of(pawn_attacks));

                if constexpr (status.mode == Promotion_Move_Generation) {
                    // if so, perform the move and call the callback function.
                    Move_Receiver<status, Promotion, Queen,
                        CallBackType>::evaluate_and_perform_move(
                        board_p, callback, pawn, pawn_attack);

                    Move_Receiver<status, Promotion, Bishop, CallBackType>::evaluate_and_perform_move(
                        board_p, callback, pawn, pawn_attack);

                    Move_Receiver<status, Promotion, Knight, CallBackType>::evaluate_and_perform_move(
                        board_p, callback, pawn, pawn_attack);

                    Move_Receiver<status, Promotion, Rook, CallBackType>::evaluate_and_perform_move(
                        board_p, callback, pawn, pawn_attack);

                    // increment the number of moves generated by four.
                    moves += 4ULL; // -V112
                } else {
                    // perform the move and call the callback
                    Move_Receiver<status, Capture, Pawn, CallBackType>::evaluate_and_perform_move(
                        board_p, callback, pawn, pawn_attack);

                    // increment the number of moves generated
                    ++moves;
                }
            }

            // return the number of moves generated
            return moves;
        }

        /**
         * Generates en passant captures. Only supposed to be called when en passant captures are possible
         * _and_ during normal- or check-move-generation.
         *
         * @tparam status An instance of the class Board_Status indicating the state of move generation this method was called in.
         * @tparam CallBackType The type of the callback
         * @param callback The callback itself
         * @param pawn A Bitboard with a single bit set where the pawn is located.
         * @return Returns the number of moves generated.
         */
        template<Kangaroo::Board_Status status, typename CallBackType>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_en_passant_captures(
            CallBackType callback, const Bitboard pawn) const {
            using enum Color;

            static_assert(
                (status.mode == Move_Generation_Mode::Normal_Move_Generation || status.mode ==
                 Move_Generation_Mode::Check_Move_Generation) && status.en_passant_p == true);

            static_assert(status.color_to_move == White || status.color_to_move == Black);

            // initialize the number of generated moves with zero.
            std::size_t moves = 0ULL;

            // when we generate moves for White
            if constexpr (status.color_to_move == White) {
                // if the Pawn is left of the en_passant_square
                if (not_a_file & pawn & board_p->en_passant_square >> 1) {
                    // perform the move and call the callback
                    Move_Receiver<status, Move_Type::Capture, Chess_Pieces::Pawn,
                        CallBackType>::evaluate_and_perform_move(
                        board_p, callback, pawn, pawn << 7);

                    // increase move counter by one
                    ++moves;

                    // if the Pawn is on the right-hand-side of the en_passant_square
                } else if (not_h_file & pawn & board_p->en_passant_square << 1) {
                    // perform the move and call the callback
                    Move_Receiver<status, Move_Type::Capture, Chess_Pieces::Pawn,
                        CallBackType>::evaluate_and_perform_move(
                        board_p, callback, pawn, pawn << 9);

                    // increase move-counter by one
                    ++moves;
                }

                // when we generate moves for Black ...
            } else if constexpr (status.color_to_move == Black) {
                // if the Pawn is on the right-hand-side of the en_passant_square
                if (not_a_file & pawn & board_p->en_passant_square >> 1) {
                    // perform the move and call the callback
                    Move_Receiver<status, Move_Type::Capture, Chess_Pieces::Pawn,
                        CallBackType>::evaluate_and_perform_move(
                        board_p, callback, pawn, pawn >> 7);

                    // increase the move-counter by one
                    ++moves;

                    // if the Pawn is on the left-hand-side of the en_passant_square
                } else if (not_h_file & pawn & board_p->en_passant_square << 1) {
                    // perform the move and call the callback
                    Move_Receiver<status, Move_Type::Capture, Chess_Pieces::Pawn,
                        CallBackType>::evaluate_and_perform_move(
                        board_p, callback, pawn, pawn >> 9);

                    // increase the move-counter by one
                    ++moves;
                }
            }

            // return the number of found moves
            return moves;
        }

        template<Color color>
        [[nodiscard]] static _ForceInline constexpr bool is_pawn_promotion(Bitboard moved_pawn) {
            using enum Color;

            static_assert(color == White || color == Black);

            return moved_pawn & get_promotion_rank<color>() ? true : false;
        }

        /**
         * @brief Generates the possible moves for a pawn in a chess game.
         *
         * This function calculates all the possible moves for a given Pawn
         * based on its current position, the board state, and its color.
         * It considers normal advances, captures, en passant captures, and
         * Pawn promotion.
         *
         *
         * @tparam status An instance of the class Board_Status indicating the state of move generation we are currently in.
         * @tparam CallBackType The type of the callback function
         * @param callback  The user-provided callback function
         * @return Returns the number of moves generated.
         */
        template<Kangaroo::Board_Status status, typename CallBackType>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_moves(CallBackType callback) const {
            using enum Color;
            using enum Chess_Pieces;
            using enum Move_Type;
            using enum Move_Generation_Mode;

            // initialize the number of found moves with zero.
            std::size_t moves = 0ULL;

            // select the correct set of pawns.
            Bitboard pawns = status.color_to_move == White ? board_p->white_pawns : board_p->black_pawns;

            // if we are in Normal_Move_Generation-mode or in Check_Move_Generation-mode...
            if constexpr (status.mode == Normal_Move_Generation || status.mode == Check_Move_Generation) {
                // ... we do not consider pinned pawns
                pawns &= ~(pin_mask_D | pin_mask_HV) & ~get_promotion_rank<status.color_to_move>();

                // if we are in Pin_HV_Move_Generation-mode ...
            } else if constexpr (status.mode == Pin_HV_Move_Generation) {
                // ... we only consider HV-pinned pawns.
                pawns &= pin_mask_HV;

                // if we generate the diagonally pinned pawns...
            } else if constexpr (status.mode == Pin_D_Move_Generation) {
                // ...there is nothing to be done here.
                return 0;
            } else if constexpr (status.mode == Promotion_Move_Generation) {
                // if we are in Promotion_Move_Generation-mode, we only consider pawns that are in the promotion rank.
                pawns &= ~(pin_mask_D | pin_mask_HV) & get_promotion_rank<status.color_to_move>();
            }


            // loop over all pawns that fulfill the current 'generation-mode' constraints.
            Bitloop(pawns, pawns_remaining) {
                using enum Color;

                // compute the position of the current Pawn.
                const Bitboard loop_pawn = bitboard_square_of(pawns_remaining);

                // if we are either in Normal_Move_Generation-mode, Pin_HV_Move_Generation-mode,
                // or Check_Move_Generation-mode
                if constexpr (status.mode == Normal_Move_Generation || status.mode == Pin_HV_Move_Generation ||
                              status.mode == Check_Move_Generation) {
                    // compute the moved Pawn
                    const Bitboard moved_pawn = regular_pawn_push<status.color_to_move>(loop_pawn);

                    // and check if it is admissible.
                    if (is_pawn_push_admissible<status.mode>(loop_pawn, moved_pawn, board_p->all_pieces)) {
                        // check if we are in Promotion_Move_Generation-mode
                        if constexpr (status.mode == Promotion_Move_Generation) {
                            // if so, perform the move and call the callback function.
                            Move_Receiver<status, Promotion, Queen, CallBackType>::evaluate_and_perform_move(
                                board_p, callback, loop_pawn, moved_pawn);

                            Move_Receiver<status, Promotion, Bishop, CallBackType>::evaluate_and_perform_move(
                                board_p, callback, loop_pawn, moved_pawn);

                            Move_Receiver<status, Promotion, Knight, CallBackType>::evaluate_and_perform_move(
                                board_p, callback, loop_pawn, moved_pawn);

                            Move_Receiver<status, Promotion, Rook, CallBackType>::evaluate_and_perform_move(
                                board_p, callback, loop_pawn, moved_pawn);

                            moves += 4ULL; // -V112
                        } else {
                            // perform the move and run the callback
                            Move_Receiver<status, Normal, Pawn, CallBackType>::evaluate_and_perform_move(
                                board_p, callback, loop_pawn, moved_pawn);

                            // increment the number of moves generated.
                            ++moves;

                            // double move for pawns in base row
                            moves += generate_double_pawn_pushs<status, CallBackType>(callback, loop_pawn);
                        }
                    }
                }

                if constexpr (status.mode == Normal_Move_Generation || status.mode == Check_Move_Generation ||
                              status.mode == Promotion_Move_Generation) {
                    moves += generate_pawn_captures<status, CallBackType>(callback, loop_pawn);
                }

                if constexpr (status.en_passant_p == true && (
                                  status.mode == Normal_Move_Generation ||
                                  status.mode == Check_Move_Generation)) {
                    moves += generate_en_passant_captures<status, CallBackType>(callback, loop_pawn);
                }
            }
            return moves;
        }


        template<Slider slider, Pin_Masks_Suitable_For purpose, Color color>
        _ForceInline constexpr void update_pin_mask_for_movement_like(const Square king_position,
                                                                      const Bitboard rooks_remaining) {
            using enum Slider;
            using enum Color;

            static_assert(
                purpose == Pin_Masks_Suitable_For::Detecting_Pins ||
                purpose == Pin_Masks_Suitable_For::Detecting_Check);

            // compute position of current Rook
            const Square rook_position = square_of(rooks_remaining);

            // compute the pin-ray between the Rook and the King
            const Bitboard ray = get_pin_ray_for<slider>(king_position, rook_position);

            const auto pieces_in_intersection = Bitcount(ray & board_p->all_pieces);

            const auto player_pieces_in_intersection = Bitcount(
                ray & (color == White ? board_p->white_pieces : board_p->black_pieces));

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
    };
} // Kangaroo

#endif //MOVEMENT_GENERATOR_H
