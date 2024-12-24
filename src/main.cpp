
#include "../tools/magic_numbers.h"
#include <../tools/attack_tables.h>
#include "chess_board.h"
#include "move_generator.h"
#include <print>


int main() {

    std::unique_ptr<Chess_Board> board = create_chess_board_from_fen("8/4P3/8/4p3/5Q2/8/8/8 w - - 0 1 ");

    print_chess_board(board.get());
    Bitboard result = 0ULL;

    for (std::size_t rank = 0; rank < 8; ++rank) {
        std::print( "  {}   ", 8 - rank );
        for (std::size_t file = 0; file < 8; ++file) {
            auto position = rank_file_to_position(7-rank, file);
            const auto r = is_position_attacked_by<Color::black>(position, board.get());

            if (r) {
                std::print( " 1 ");
                result = set_bit(result, position);
            } else {
                std::print( " . ");
            }
        }
        std::print("\n");
    }
    std::print("\n       A  B  C  D  E  F  G  H");
    std::print("\n\n   Result: {}\n\n", result);

    return 0;
}
