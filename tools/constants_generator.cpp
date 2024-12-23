//
// Created by U439644 on 12/23/2024.
//

#include <fstream>

#include "attack_masks.h"
#include "magic_numbers.h"
#include "fmt/base.h"

template<typename T, std::size_t N>
void output_array (std::ofstream &of, const std::array<T, N>& arr, const std::string& name) {

    of << "inline constexpr std::array<" << typeid(T).name() << ", " << N << "> " << name << " = {\n";
    for (const auto& elem: arr) {
        of << "    " << elem << ",\n";
    }
    of << "};\n\n";
}

void generate_masks(std::ofstream &of) {

    std::array<Bitboard, 64> bishop_attack_masks = create_attack_masks<Slider_t::bishop> ();
    std::array<Bitboard, 64> rook_attack_masks = create_attack_masks<Slider_t::rook>();

    output_array<Bitboard, 64>(of, bishop_attack_masks, "bishop_attack_masks");
    output_array<Bitboard, 64>(of, rook_attack_masks, "rook_attack_masks");

}

void generate_magic_numbers(std::ofstream &of) {
    std::array<Constants::MagicNumber, 64> Bishop_Magic_Numbers = Constants::Impl::find_magic_numbers_for<Slider::bishop>();
    std::array<Constants::MagicNumber, 64> Rook_Magic_Numbers = Constants::Impl::find_magic_numbers_for<Slider::rook>();

    output_array<Constants::MagicNumber, 64>(of, Bishop_Magic_Numbers, "bishop_magic_numbers");
    output_array<Constants::MagicNumber, 64>(of, Rook_Magic_Numbers, "rook_magic_numbers");
}

int main(const int argc, const char** argv) {
    if ( argc != 2 ) {
        fmt::print("Error: The Kangaroo constants generator needs exactly one \n");
        fmt::print("argument---The file[path] where the resulting tables shall \n");
        fmt::print("be written. Aborting ...");
        return 1;
    }

    std::ofstream of;
    fmt::print("Generating constants to file: {}\n", argv[1]);
    of.open(argv[1], std::ios::out);
    of << "#pragma once\n\n";
    of << "#include <array>\n";
    of << "#include \"base.h\"\n";
    of << "#include \"bitboard.h\"\n\n";
    of << "namespace Constants {\n";

#ifdef GENERATE_MASKS
    generate_masks(of);
#elif GENERATE_MAGICS
    generate_magic_numbers(of);
#endif


    of << "} // namespace Constants\n";
    of.close();

}