// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by U439644 on 12/23/2024.
//

#include <vector>
#include <fstream>
#include <print>

#include "attack_masks.h"
#include "attack_tables.h"
#include "magic_numbers.h"
#include "types.h"


template<typename T>
void output_array(std::ofstream &of, const T &arr, const std::string &name, const std::string &type) {

    std::string guard = name;
    std::ranges::transform(guard, guard.begin(), [](unsigned char c){ return std::toupper(c); });
    guard += "__H";

    of << "#ifndef " << guard << "\n";
    of << "#define " << guard << "\n\n";

    of << "inline constexpr std::array<" << type << ", " << arr.size() << "> " << name << " = {\n";
    for (const auto &elem: arr) {
        of << "    " << std::format("0x{:x}ULL", elem) << ",\n";
    }
    of << "};\n\n";
    of << "#endif // " << guard << "\n\n";

}

void generate_masks(std::ofstream &of) {
    constexpr std::array<Bitboard, 64> bishop_attack_masks = create_attack_masks<Slider_t::bishop>();
    constexpr std::array<Bitboard, 64> rook_attack_masks = create_attack_masks<Slider_t::rook>();

    output_array(of, bishop_attack_masks, "bishop_attack_masks", "Bitboard");
    output_array(of, rook_attack_masks, "rook_attack_masks", "Bitboard");
}

void generate_magic_numbers(std::ofstream &of) {
    const std::array<MagicNumber, 64> Bishop_Magic_Numbers = Constants::Impl::find_magic_numbers_for<Slider::bishop>();
    const std::array<MagicNumber, 64> Rook_Magic_Numbers = Constants::Impl::find_magic_numbers_for<Slider::rook>();

    output_array(of, Bishop_Magic_Numbers, "bishop_magic_numbers", "MagicNumber");
    output_array(of, Rook_Magic_Numbers, "rook_magic_numbers", "MagicNumber");
}

#ifdef GENERATE_ATTACKS
void generate_attacks(std::ofstream &of) {
    std::vector<Bitboard> rook_attack_table(64 * 4096, 0ULL);
    create_attack_table<Slider::rook>(rook_attack_table);

    std::vector<Bitboard> bishop_attack_table(64 * 512, 0ULL);
    create_attack_table<Slider::bishop>(bishop_attack_table);

    std::vector<Bitboard> white_pawn_attacks(64, 0ULL);
    create_pawn_attacks<Color::white>(white_pawn_attacks);

    std::vector<Bitboard> black_pawn_attacks(64, 0ULL);
    create_pawn_attacks<Color::black>(black_pawn_attacks);

    std::vector<Bitboard> king_attacks(64, 0ULL);
    create_king_attacks(king_attacks);

    std::vector<Bitboard> knight_attacks(64, 0ULL);
    create_knight_attacks(knight_attacks);


    output_array(of, rook_attack_table, "rook_attack_table", "Bitboard");
    output_array(of, bishop_attack_table, "bishop_attack_table", "Bitboard");

    output_array(of, white_pawn_attacks, "white_pawn_attacks", "Bitboard");
    output_array(of, black_pawn_attacks, "black_pawn_attacks", "Bitboard");

    output_array(of, king_attacks, "king_attacks", "Bitboard");

    output_array(of, knight_attacks, "knight_attacks", "Bitboard");
}
#endif

int main(const int argc, const char **argv) {
    if (argc != 2) {
        std::print("Error: The Kangaroo constants generator needs exactly one \n");
        std::print("argument---The file[path] where the resulting tables shall \n");
        std::print("be written. Aborting ...");

        std::print("\n");
        std::print("argc: {}\n", argc);
        for (std::size_t i = 0; i < static_cast<std::size_t>(argc); ++i) {
            std::print("argv[{}]: {}\n", i, argv[i]);
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

    return 0;
}
