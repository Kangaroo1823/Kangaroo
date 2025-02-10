//
// Created by peter on 26/01/2025.
//

#ifndef PAWN_MOVE_GENERATOR_H
#define PAWN_MOVE_GENERATOR_H
#include "Pin_And_Check_Mask_Generator.h"
#include "Move_Receiver.h"

namespace Kangaroo::Move_Generator {
    template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces, typename... Args_> class
        CallbackType>
    class Pawn_Move_Generator : public virtual Pin_And_Check_Mask_Generator<status> {
    public:
        constexpr explicit Pawn_Move_Generator(Chess_Board *board) : Pin_And_Check_Mask_Generator<status>(board) {
        }

        template<Move_Generation_Mode mode, typename... Args>
        std::size_t evaluate_pawn_move(const Bitboard from, const Bitboard to, Args... args) {
            std::size_t moves = 0ULL;
            // check if we are in Promotion_Move_Generation-mode
            if constexpr (mode == Move_Generation_Mode::Promotion_Move_Generation) {
                if constexpr (status.check_p) {
                    if (to & this->get_check_mask()) {
                        // if so, perform the move and call the callback function.
                        Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Queen, CallbackType, Args
                            ...>::evaluate_and_perform_move(
                            this->get_board(), from, to, args...);

                        Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Bishop, CallbackType, Args
                            ...>::evaluate_and_perform_move(
                            this->get_board(), from, to, args...);

                        Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Knight, CallbackType, Args
                            ...>::evaluate_and_perform_move(
                            this->get_board(), from, to, args...);

                        Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Rook, CallbackType, Args
                            ...>::evaluate_and_perform_move(
                            this->get_board(), from, to, args...);

                        moves += 4ULL;
                    }
                } else {
                    // if so, perform the move and call the callback function.
                    Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Queen, CallbackType, Args
                        ...>::evaluate_and_perform_move(
                        this->get_board(), from, to, args...);

                    Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Bishop, CallbackType, Args
                        ...>::evaluate_and_perform_move(
                        this->get_board(), from, to, args...);

                    Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Knight, CallbackType, Args
                        ...>::evaluate_and_perform_move(
                        this->get_board(), from, to, args...);

                    Move_Receiver<status, Move_Type::Promotion, Chess_Pieces::Rook, CallbackType, Args
                        ...>::evaluate_and_perform_move(
                        this->get_board(), from, to, args...);

                    moves += 4ULL;
                }
            } else {
                if constexpr (status.check_p) {
                    if (to & this->get_check_mask()) {
                        // perform the move and run the callback
                        Move_Receiver<status, Move_Type::Normal, Chess_Pieces::Pawn, CallbackType, Args
                            ...>::evaluate_and_perform_move(
                            this->get_board(), from, to, args...);

                        // increment the number of moves generated.
                        ++moves;
                    }
                } else {
                    // perform the move and run the callback
                    Move_Receiver<status, Move_Type::Normal, Chess_Pieces::Pawn, CallbackType, Args
                        ...>::evaluate_and_perform_move(
                        this->get_board(), from, to, args...);

                    // increment the number of moves generated.
                    ++moves;
                }

                // double move for pawns in base row
                moves += generate_double_pawn_pushs<mode, Args...>(from, args...);
            }

            return moves;
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
        template<Move_Generation_Mode mode, typename... Args>
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
            if constexpr (mode == Normal_Move_Generation) {
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
                const Bitboard from = bitboard_square_of(pawns_remaining);

                // if we are either in Normal_Move_Generation-mode, Pin_HV_Move_Generation-mode,
                // or Check_Move_Generation-mode
                if constexpr (mode == Normal_Move_Generation || mode == Pin_HV_Move_Generation ||
                              mode == Promotion_Move_Generation) {
                    // compute the moved Pawn
                    const Bitboard to = regular_pawn_push<status.color_to_move>(from);

                    // and check if it is admissible.
                    if (is_pawn_push_admissible<mode>(from, to, total_pieces_for(*(this->get_board())))) {
                        moves += evaluate_pawn_move<mode, Args...>(from, to, args...);
                    }
                }

                if constexpr (mode == Normal_Move_Generation || mode == Promotion_Move_Generation) {
                    moves += generate_pawn_captures<mode, Args...>(from, args...);
                }

                if constexpr (status.en_passant_p == true && (mode == Normal_Move_Generation)) {
                    moves += generate_en_passant_captures<mode, Args...>(from, args...);
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
         * @param from  a bitboard with a single set bit at the position where the pawn 'starts' its move
         * @param to a bitboard with a single set bit at the position where the pawn 'ends' its move.
         * @param occupied_squares a bitboard with bits set where pieces are on the chess board.
         * @return true if and only if the move is admissible.
         */
        template<Move_Generation_Mode mode>
        [[nodiscard]] _ForceInline constexpr bool is_pawn_push_admissible(
            const Bitboard from, const Bitboard to, const Bitboard occupied_squares) {
            using enum Move_Generation_Mode;

            static_assert(mode == Normal_Move_Generation ||
                          mode == Pin_HV_Move_Generation || mode == Promotion_Move_Generation);

            const bool ret = (to & occupied_squares) == 0;
            if constexpr (mode == Normal_Move_Generation || mode == Promotion_Move_Generation) {
                return ret;
            } else if constexpr (mode == Pin_HV_Move_Generation) {
                const bool p = (from & this->get_pin_mask_HV()) == 0 || (to & this->get_pin_mask_HV()) !=
                               0;
                return ret && p && (from & this->get_pin_mask_D()) == 0;
            }
            return false;
        }

        /**
        * Generates a double Pawn push if admissible. Assumes that a single Pawn push is admissible.
        *
        * @param from a Bitboard with a single set bit at the position corresponding to the square where the
        *              pawn in question is currently located.
        * @param args
        * @return Returns the number of moves generated.
        */
        template<Move_Generation_Mode mode, typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_double_pawn_pushs(const Bitboard from, Args... args) {
            std::size_t moves = 0ULL;

            if constexpr (status.check_p) {
                // check if the Pawn is in the base row.
                if (from & pawn_base_row<status.color_to_move>()) {
                    // if so, check if a double Pawn push is admissible.
                    if (const Bitboard to = double_pawn_push<status.color_to_move>(from);
                        to & this->get_check_mask() && is_pawn_push_admissible<mode>(from,
                            to, total_pieces_for(*(this->get_board())))) {
                        // make the move and call the callback function.
                        Move_Receiver<status, Move_Type::Double_Push, Chess_Pieces::Pawn,
                            CallbackType, Args...>::evaluate_and_perform_move(
                            this->get_board(), from, to, args...);

                        // increment the number of moves generated.
                        ++moves;
                    }
                }
            } else {
                // check if the Pawn is in the base row.
                if (from & pawn_base_row<status.color_to_move>()) {
                    // if so, check if a double Pawn push is admissible.
                    if (const Bitboard to = double_pawn_push<status.color_to_move>(from);
                        is_pawn_push_admissible<mode>(from,
                                                      to, total_pieces_for(*(this->get_board())))) {
                        // make the move and call the callback function.
                        Move_Receiver<status, Move_Type::Double_Push, Chess_Pieces::Pawn,
                            CallbackType, Args...>::evaluate_and_perform_move(
                            this->get_board(), from, to, args...);

                        // increment the number of moves generated.
                        ++moves;
                    }
                }
            }

            // return the number of moves generated.
            return moves;
        }

        /**
         * Generates Pawn captures.
         * @param from A bitboard with a single set bit at the position of the pawn.
         * @param args additional arguments for the callback-function defined in CallbackType.
         * @return Returns the number of moves generated.
         */
        template<Move_Generation_Mode mode, typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_captures(const Bitboard from, Args... args) {
            using enum Color;
            using enum Move_Generation_Mode;
            using enum Move_Type;
            using enum Chess_Pieces;

            // this method is only supposed to be called in Normal_Move_Generation mode or in
            // Check_Move_Generation mode.
            static_assert(mode == Normal_Move_Generation || mode == Promotion_Move_Generation);

            // initialize the number of generated moves with zero.
            std::size_t moves = 0ULL;

            const auto pawn_square = std::to_underlying(square_of(from));
            // the squares the Pawn in question can move to should be occupied by the opposite color.
            Bitboard mask = get_pawn_attacks_for<status.color_to_move>(pawn_square) & all_pieces_for(
                                *this->get_board(), enemy(status.color_to_move));


            // loop over all such squares
            Bitloop(mask, pawn_attacks) {
                // generate a Bitboard with a single bit set where the Pawn is attacking
                Bitboard to = bitboard_square_of(pawn_attacks);

                moves += evaluate_pawn_move<mode, Args...>(from, to, args...);
            }

            // return the number of moves generated
            return moves;
        }


        template<Color color>
        [[nodiscard]] static _ForceInline constexpr bool
        en_passant_left_pawn_position(const Bitboard en_passant_square) {
            using enum Color;
            if constexpr (color == White) {
                return en_passant_square >> 7;
            } else {
                return en_passant_square << 7;
            }
        }

        template<Color color>
        [[nodiscard]] static _ForceInline constexpr bool en_passant_right_pawn_position(
            const Bitboard en_passant_square) {
            using enum Color;
            if constexpr (color == White) {
                return en_passant_square >> 9;
            } else {
                return en_passant_square << 9;
            }
        }

        template<Move_Type move_type, typename... Args>
        _ForceInline constexpr void handle_checks_and_en_passant(Chess_Board *board, const Bitboard from,
                                                                 const Bitboard to, Args... args) {
            if constexpr (status.check_p) {
                if (to & this->get_check_mask()) {
                    Move_Receiver<status, move_type, Chess_Pieces::Pawn, CallbackType, Args
                        ...>::evaluate_and_perform_move(board, from, to, args...);
                }
            } else {
                Move_Receiver<status, move_type, Chess_Pieces::Pawn, CallbackType, Args...>::evaluate_and_perform_move(
                    board, from, to, args...);
            }
        }

        /**
          * Generates en passant captures. Only supposed to be called when en passant captures are possible
          * _and_ during normal- or check-move-generation.
          *
          * @param from A Bitboard with a single bit set where the pawn is located.
          * @return Returns the number of moves generated.
          */
        template<Move_Generation_Mode mode, typename... Args>
        [[nodiscard]] _ForceInline constexpr std::size_t
        generate_en_passant_captures(const Bitboard from, Args... args) {
            using enum Color;

            static_assert(
                mode == Move_Generation_Mode::Normal_Move_Generation && status.en_passant_p == true);

            static_assert(status.color_to_move == White || status.color_to_move == Black);

            // initialize the number of generated moves with zero.
            std::size_t moves = 0ULL;

            if (not_h_file & from & (
                    en_passant_right_pawn_position<status.color_to_move>(
                        en_passant_square_for(*this->get_board())) |
                    en_passant_left_pawn_position<status.color_to_move>(
                        en_passant_square_for(*this->get_board())))) {
                // perform the move and call the callback
                handle_checks_and_en_passant<Move_Type::En_Passant, Args...>(
                    this->get_board(), from, en_passant_square_for(*this->get_board()), args...);

                // increase move-counter by one
                ++moves;
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
