//
// Created by U439644 on 1/20/2025.
//

#ifndef MOVEMENT_GENERATOR_DECL_H
#define MOVEMENT_GENERATOR_DECL_H

#include "chess_board.h"
#include "types.h"
#include "Move_Receiver.h"

namespace Kangaroo {
    class Move_Generator {
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
        explicit Move_Generator(Chess_Board *board) : board_p(board) {
        }

        [[nodiscard]] _ForceInline constexpr Bitboard get_pin_mask_HV() const {
            return pin_mask_HV;
        }

        [[nodiscard]] _ForceInline constexpr Bitboard get_pin_mask_D() const {
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
        _ForceInline constexpr void build_pin_masks();


        template<Kangaroo::Board_Status status>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_all_pawn_moves(const CallbackType &callback);

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
            Bitboard pawn_origin, Bitboard pawn_move, Bitboard occupied_squares) const;

        /**
         * Generates a double Pawn push if admissible. Assumes that a single Pawn push is admissible.
         *
         * @tparam status an instances of the Board_Status class indicating the status of move generation
         * @param callback the call function
         * @param pawn a Bitboard with a single set bit at the position corresponding to the square where the
         *              pawn in question is currently located.
         * @return Returns the number of moves generated.
         */
        template<Kangaroo::Board_Status status>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_double_pawn_pushs(
            const CallbackType &callback, Bitboard pawn) const;

        /**
         * Generates Pawn captures.
         * @tparam status an instance of the Board_Status class indicating the current state of move generation.
         * @param callback The callback function.
         * @param pawn A bitboard with a single set bit at the position of the pawn.
         * @return Returns the number of moves generated.
         */
        template<Board_Status status>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_captures(
            const CallbackType &callback, Bitboard pawn) const;

        /**
         * Generates en passant captures. Only supposed to be called when en passant captures are possible
         * _and_ during normal- or check-move-generation.
         *
         * @tparam status An instance of the class Board_Status indicating the state of move generation this method was called in.
         * @param callback The callback itself
         * @param pawn A Bitboard with a single bit set where the pawn is located.
         * @return Returns the number of moves generated.
         */
        template<Board_Status status>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_en_passant_captures(
            const CallbackType &callback, Bitboard pawn) const;

        template<Color color>
        [[nodiscard]] static _ForceInline constexpr bool is_pawn_promotion(Bitboard moved_pawn);

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
         * @param callback  The user-provided callback function
         * @return Returns the number of moves generated.
         */
        template<Kangaroo::Board_Status status>
        [[nodiscard]] _ForceInline constexpr std::size_t generate_pawn_moves(const CallbackType &callback) const;


        template<Slider slider, Pin_Masks_Suitable_For purpose, Color color>
        _ForceInline constexpr void update_pin_mask_for_movement_like(Square king_position, Bitboard rooks_remaining);
    };
} // Kangaroo


#endif //MOVEMENT_GENERATOR_DECL_H
