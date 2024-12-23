//
// Created by U439644 on 12/23/2024.
//

#include <fstream>

#include "../test/attack_masks.h"
#include "../test/attack_tables.h"
#include "../test/magic_numbers.h"

#include "fmt/base.h"
#include "types.h"

template<typename T, std::size_t N>
void output_array(std::ofstream &of, const std::array<T, N> &arr, const std::string &name, const std::string &type) {
    of << "inline constexpr std::array<" << type << ", " << N << "> " << name << " = {\n";
    for (const auto &elem: arr) {
        of << "    " << fmt::format("0x{0:x}ULL", elem) << ",\n";
    }
    of << "};\n\n";
}

void generate_masks(std::ofstream &of) {
    std::array<Bitboard, 64> bishop_attack_masks = create_attack_masks<Slider_t::bishop>();
    std::array<Bitboard, 64> rook_attack_masks = create_attack_masks<Slider_t::rook>();

    output_array<Bitboard, 64>(of, bishop_attack_masks, "bishop_attack_masks", "Bitboard");
    output_array<Bitboard, 64>(of, rook_attack_masks, "rook_attack_masks", "Bitboard");
}

void generate_magic_numbers(std::ofstream &of) {
    std::array<MagicNumber, 64> Bishop_Magic_Numbers = Constants::Impl::find_magic_numbers_for<Slider::bishop>();
    std::array<MagicNumber, 64> Rook_Magic_Numbers = Constants::Impl::find_magic_numbers_for<Slider::rook>();

    output_array<MagicNumber, 64>(of, Bishop_Magic_Numbers, "bishop_magic_numbers", "MagicNumber");
    output_array<MagicNumber, 64>(of, Rook_Magic_Numbers, "rook_magic_numbers", "MagicNumber");
}

#ifdef GENERATE_ATTACKS
void generate_attacks(std::ofstream &of) {
    std::array<Bitboard, 64 * 4096> rook_attack_table = create_attack_table<Slider::rook>();
    std::array<Bitboard, 64 * 512> bishop_attack_table = create_attack_table<Slider::bishop>();

    std::array<Bitboard, 64> white_pawn_attacks = create_pawn_attacks<Color::white>();
    std::array<Bitboard, 64> black_pawn_attacks = create_pawn_attacks<Color::black>();

    std::array<Bitboard, 64> king_attacks = create_king_attacks();
    std::array<Bitboard, 64> knight_attacks = create_knight_attacks();


    output_array<Bitboard, 64 * 4096>(of, rook_attack_table, "rook_attack_table", "Bitboard");
    output_array<Bitboard, 64 * 512>(of, bishop_attack_table, "bishop_attack_table", "Bitboard");

    output_array<Bitboard, 64>(of, white_pawn_attacks, "white_pawn_attacks", "Bitboard");
    output_array<Bitboard, 64>(of, black_pawn_attacks, "black_pawn_attacks", "Bitboard");

    output_array<Bitboard, 64>(of, king_attacks, "king_attacks", "Bitboard");

    output_array<Bitboard, 64>(of, knight_attacks, "knight_attacks", "Bitboard");
}
#endif

int main(const int argc, const char **argv) {
    if (argc != 2) {
        fmt::print("Error: The Kangaroo constants generator needs exactly one \n");
        fmt::print("argument---The file[path] where the resulting tables shall \n");
        fmt::print("be written. Aborting ...");

        fmt::print("\n");
        fmt::print("argc: {}\n", argc);
        for (std::size_t i = 0; i < static_cast<std::size_t>(argc); ++i) {
            fmt::print("argv[{}]: {}\n", i, argv[i]);
        }
        return 1;
    }

    std::ofstream of;
    of.open(argv[1], std::ios::out);
    of << "#pragma once\n\n";
    of << "#include <array>\n";
    of << "#include \"types.h\"\n\n";

    of << "namespace Constants {\n";
#ifdef GENERATE_MASKS
    generate_masks(of);
#elif GENERATE_MAGICS
    generate_magic_numbers(of);
#elif GENERATE_ATTACKS
    generate_attacks(of);
#endif


    of << "} // namespace Constants\n";
    of.close();
}
