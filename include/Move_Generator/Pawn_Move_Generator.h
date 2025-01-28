//
// Created by peter on 26/01/2025.
//

#ifndef PAWN_MOVE_GENERATOR_H
#define PAWN_MOVE_GENERATOR_H
#include "Pin_And_Check_Mask_Generator.h"
#include "Move_Receiver.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class CallbackType>
    class Pawn_Move_Generator : public virtual Pin_And_Check_Mask_Generator<status> {
    public:
        constexpr explicit Pawn_Move_Generator(Chess_Board *board) : Pin_And_Check_Mask_Generator<status>(board) {
        }

        /**
         * @brief Generates the possible moves for a pawn in a chess game.
         *
         * This function calculates all the possible moves for a given Pawn
         * based on its current position, the board state, and its color.
         * It considers normal advances, captures, en passant captures, and
         * Pawn promotion.
         *
         * @return Returns the number of moves generated.
         */
        template<Move_Generation_Mode mode, typename ...Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_moves(Args... args) {
            using enum Color;
            using enum Chess_Pieces;
            using enum Move_Type;
            using enum Move_Generation_Mode;

            // initialize the number of found moves with zero.
            std::size_t moves = 0ULL;

            // select the correct set of pawns.
            Bitboard pawns = bitboard_for(*(this->get_board()), status.color_to_move, Pawn);

            // if we are in Normal_Move_Generation-mode or in Check_Move_Generation-mode...
            if constexpr (mode == Normal_Move_Generation || mode == Check_Move_Generation) {
                // ... we do not consider pinned pawns
                pawns &= ~(this->get_pin_mask_D() | this->get_pin_mask_HV()) & ~get_promotion_rank<status.
                    color_to_move>();

                // if we are in Pin_HV_Move_Generation-mode ...
            } else if constexpr (mode == Pin_HV_Move_Generation) {
                // ... we only consider HV-pinned pawns.
                pawns &= this->get_pin_mask_HV();

                // if we generate the diagonally pinned pawns...
            } else if constexpr (mode == Pin_D_Move_Generation) {
                // ...there is nothing to be done here.
                return 0;
            } else if constexpr (mode == Promotion_Move_Generation) {
                // if we are in Promotion_Move_Generation-mode, we only consider pawns that are in the promotion rank.
                pawns &= ~(this->get_pin_mask_D() | this->get_pin_mask_HV()) & get_promotion_rank<status.
                    color_to_move>();
            }


            // loop over all pawns that fulfill the current 'generation-mode' constraints.
            Bitloop(pawns, pawns_remaining) {
                using enum Color;

                // compute the position of the current Pawn.
                const Bitboard loop_pawn = bitboard_square_of(pawns_remaining);

                // if we are either in Normal_Move_Generation-mode, Pin_HV_Move_Generation-mode,
                // or Check_Move_Generation-mode
                if constexpr (mode == Normal_Move_Generation || mode == Pin_HV_Move_Generation ||
                              mode == Check_Move_Generation || mode == Promotion_Move_Generation) {
                    // compute the moved Pawn
                    const Bitboard moved_pawn = regular_pawn_push<status.color_to_move>(loop_pawn);

                    // and check if it is admissible.
                    if (is_pawn_push_admissible<mode>(loop_pawn, moved_pawn, total_pieces_for(*(this->get_board())))) {
                        // check if we are in Promotion_Move_Generation-mode
                        if constexpr (mode == Promotion_Move_Generation) {
                            // if so, perform the move and call the callback function.
                            Move_Receiver<status, Promotion, Queen, CallbackType, Args...>::evaluate_and_perform_move(
                                this->get_board(), loop_pawn, moved_pawn, args...);

                            Move_Receiver<status, Promotion, Bishop, CallbackType, Args...>::evaluate_and_perform_move(
                                this->get_board(), loop_pawn, moved_pawn, args...);

                            Move_Receiver<status, Promotion, Knight, CallbackType, Args...>::evaluate_and_perform_move(
                                this->get_board(), loop_pawn, moved_pawn, args...);

                            Move_Receiver<status, Promotion, Rook, CallbackType, Args...>::evaluate_and_perform_move(
                                this->get_board(), loop_pawn, moved_pawn, args...);

                            moves += 4ULL;
                        } else {
                            // perform the move and run the callback
                            Move_Receiver<status, Normal, Pawn, CallbackType, Args...>::evaluate_and_perform_move(
                                this->get_board(), loop_pawn, moved_pawn, args...);

                            // increment the number of moves generated.
                            ++moves;

                            // double move for pawns in base row
                            moves += generate_double_pawn_pushs<mode, Args...>(loop_pawn, args...);
                        }
                    }
                }

                if constexpr (mode == Normal_Move_Generation || mode == Check_Move_Generation ||
                              mode == Promotion_Move_Generation) {
                    moves += generate_pawn_captures<mode, Args...>(loop_pawn, args...);
                }

                if constexpr (status.en_passant_p == true && (
                                  mode == Normal_Move_Generation ||
                                  mode == Check_Move_Generation)) {
                    moves += generate_en_passant_captures<mode, Args...>(loop_pawn, args...);
                }
            }
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
            const Bitboard pawn_origin, const Bitboard pawn_move, const Bitboard occupied_squares) {
            using enum Move_Generation_Mode;

            static_assert(mode == Normal_Move_Generation || mode == Check_Move_Generation ||
                          mode == Pin_HV_Move_Generation || mode == Promotion_Move_Generation);

            const bool ret = (pawn_move & occupied_squares) == 0;
            if constexpr (mode == Normal_Move_Generation || mode == Check_Move_Generation || mode ==
                          Promotion_Move_Generation) {
                return ret;
            } else if constexpr (mode == Pin_HV_Move_Generation) {
                const bool p = (pawn_origin & this->get_pin_mask_HV()) == 0 || (pawn_move & this->get_pin_mask_HV()) !=
                               0;
                return ret && p && (pawn_origin & this->get_pin_mask_D()) == 0;
            }
            return false;
        }

        /**
        * Generates a double Pawn push if admissible. Assumes that a single Pawn push is admissible.
        *
        * @param pawn a Bitboard with a single set bit at the position corresponding to the square where the
        *              pawn in question is currently located.
        * @param args
        * @return Returns the number of moves generated.
        */
        template<Move_Generation_Mode mode, typename ...Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_double_pawn_pushs(const Bitboard pawn, Args... args) {
            std::size_t moves = 0ULL;

            // check if the Pawn is in the base row.
            if (pawn & pawn_base_row<status.color_to_move>()) {
                // if so, check if a double Pawn push is admissible.
                if (const Bitboard moved_pawn_2 = double_pawn_push<status.color_to_move>(pawn);
                    is_pawn_push_admissible<mode>(pawn,
                                                  moved_pawn_2, total_pieces_for(*(this->get_board())))) {
                    // make the move and call the callback function.
                    Move_Receiver<status, Move_Type::Normal, Chess_Pieces::Pawn,
                        CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, moved_pawn_2, args...);

                    // increment the number of moves generated.
                    ++moves;
                }
            }

            // return the number of moves generated.
            return moves;
        }

        /**
         * Generates Pawn captures.
         * @param pawn A bitboard with a single set bit at the position of the pawn.
         * @return Returns the number of moves generated.
         */
        template<Move_Generation_Mode mode, typename ...Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_captures(const Bitboard pawn, Args... args) {
            using enum Color;
            using enum Move_Generation_Mode;
            using enum Move_Type;
            using enum Chess_Pieces;

            // this method is only supposed to be called in Normal_Move_Generation mode or in
            // Check_Move_Generation mode.
            static_assert(
                mode == Normal_Move_Generation ||
                mode == Check_Move_Generation ||
                mode == Promotion_Move_Generation);

            // initialize the number of generated moves with zero.
            std::size_t moves = 0ULL;

            const auto pawn_square = std::to_underlying(square_of(pawn));
            // the squares the Pawn in question can move to should be occupied by the opposite color.
            Bitboard mask = get_pawn_attacks_for<status.color_to_move>(pawn_square) & all_pieces_for(
                                *this->get_board(), enemy(status.color_to_move));


            // loop over all such squares
            Bitloop(mask, pawn_attacks) {
                // generate a Bitboard with a single bit set where the Pawn is attacking
                Bitboard pawn_attack = bitboard_square_of(pawn_attacks);

                if constexpr (mode == Promotion_Move_Generation) {
                    // if so, perform the move and call the callback function.
                    Move_Receiver<status, Capture_Promotion, Queen, CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, pawn_attack, args...);

                    Move_Receiver<status, Capture_Promotion, Bishop, CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, pawn_attack, args...);

                    Move_Receiver<status, Capture_Promotion, Knight, CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, pawn_attack, args...);

                    Move_Receiver<status, Capture_Promotion, Rook, CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, pawn_attack, args...);

                    // increment the number of moves generated by four.
                    moves += 4ULL; // -V112
                } else {
                    // perform the move and call the callback
                    Move_Receiver<status, Capture, Pawn, CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, pawn_attack, args...);

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
          * @param pawn A Bitboard with a single bit set where the pawn is located.
          * @return Returns the number of moves generated.
          */
        template<Move_Generation_Mode mode, typename ...Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_en_passant_captures(const Bitboard pawn, Args... args) {
            using enum Color;

            static_assert(
                (mode == Move_Generation_Mode::Normal_Move_Generation || mode ==
                 Move_Generation_Mode::Check_Move_Generation) && status.en_passant_p == true);

            static_assert(status.color_to_move == White || status.color_to_move == Black);

            // initialize the number of generated moves with zero.
            std::size_t moves = 0ULL;

            // when we generate moves for White
            if constexpr (status.color_to_move == White) {
                // if the Pawn is left of the en_passant_square
                if (not_a_file & pawn & en_passant_square_for(*this->get_board()) >> 7) {
                    // perform the move and call the callback
                    Move_Receiver<status, Move_Type::En_Passant, Chess_Pieces::Pawn, CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, en_passant_square_for(*this->get_board()), args...);

                    // increase move counter by one
                    ++moves;

                    // if the Pawn is on the right-hand-side of the en_passant_square
                } else if (not_h_file & pawn & en_passant_square_for(*this->get_board()) >> 9) {
                    // perform the move and call the callback
                    Move_Receiver<status, Move_Type::En_Passant, Chess_Pieces::Pawn, CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, en_passant_square_for(*this->get_board()), args...);

                    // increase move-counter by one
                    ++moves;
                }

                // when we generate moves for Black ...
            } else if constexpr (status.color_to_move == Black) {
                // if the Pawn is on the right-hand-side of the en_passant_square
                if (not_a_file & pawn & en_passant_square_for(*this->get_board()) << 7) {
                    // perform the move and call the callback
                    Move_Receiver<status, Move_Type::En_Passant, Chess_Pieces::Pawn, CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, en_passant_square_for(*this->get_board()), args...);

                    // increase the move-counter by one
                    ++moves;

                    // if the Pawn is on the left-hand-side of the en_passant_square
                } else if (not_h_file & pawn & en_passant_square_for(*this->get_board()) << 9) {
                    // perform the move and call the callback
                    Move_Receiver<status, Move_Type::En_Passant, Chess_Pieces::Pawn, CallbackType, Args...>::evaluate_and_perform_move(
                        this->get_board(), pawn, en_passant_square_for(*this->get_board()), args...);

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
    };
} // Kangaroo

#endif //PAWN_MOVE_GENERATOR_H
