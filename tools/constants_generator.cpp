// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by U439644 on 12/23/2024.
//

#include <vector>
#include <fstream>
#include <print>
#include <ranges>
#include <algorithm>

#include "attack_masks.h"
#include "types.h"

#ifdef GENERATE_ATTACKS
#include "attack_tables.h"
#endif

#ifdef GENERATE_MAGICS
#include "magic_numbers.h"
#endif

#ifdef GENERATE_MASKS
#include "attack_masks.h"
#endif


template<typename T>
void output_array(std::ofstream &of, const T &arr, const std::string &name, const std::string &type) {
    std::string guard = name;
    std::ranges::transform(guard, guard.begin(), [](unsigned char c) { return std::toupper(c); });
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

/*************************************************************************
 *
 * xray_visibility table generator
 *
 ************************************************************************/

[[nodiscard]] constexpr Bitboard generate_rook_xray_visibility_for(const Square position) {
    Bitboard rook_xray_visibility = 0ULL;

    const auto position_rank = static_cast<int64_t>(std::to_underlying(position) / 8);
    const auto position_file = static_cast<int64_t>(std::to_underlying(position) % 8);

    for (auto r = position_rank + 1; r < 8; ++r) { rook_xray_visibility |= 1ULL << (r * 8 + position_file); }
    for (auto r = position_rank - 1; r >= 0; --r) { rook_xray_visibility |= 1ULL << (r * 8 + position_file); }
    for (auto f = position_file + 1; f < 8; ++f) { rook_xray_visibility |= 1ULL << (position_rank * 8 + f); }
    for (auto f = position_file - 1; f >= 0; --f) { rook_xray_visibility |= 1ULL << (position_rank * 8 + f); }

    return rook_xray_visibility;
}

[[nodiscard]] constexpr Bitboard generate_bishop_xray_visibility_for(const Square position) {
    Bitboard bishop_xray_visibility = 0ULL;

    const auto position_rank = static_cast<int64_t>(std::to_underlying(position) / 8);
    const auto position_file = static_cast<int64_t>(std::to_underlying(position) % 8);

    for (auto r = position_rank + 1, f = position_file + 1; r < 8 && f < 8; ++r, ++f) {
        bishop_xray_visibility |= 1ULL << (r * 8 + f);
    }
    for (auto r = position_rank - 1, f = position_file + 1; r >= 0 && f < 8; --r, ++f) {
        bishop_xray_visibility |= 1ULL << (r * 8 + f);
    }
    for (auto r = position_rank + 1, f = position_file - 1; r < 8 && f >= 0; ++r, --f) {
        bishop_xray_visibility |= 1ULL << (r * 8 + f);
    }
    for (auto r = position_rank - 1, f = position_file - 1; r >= 0 && f >= 0; --r, --f) {
        bishop_xray_visibility |= 1ULL << (r * 8 + f);
    }

    return bishop_xray_visibility;
}

template<Slider slider>
[[nodiscard]] constexpr Bitboard generate_slider_xray_visibility_for(const Square position) {

    using enum Slider_t;

    static_assert(slider == rook || slider == bishop);

    if constexpr (slider == rook) {
        return generate_rook_xray_visibility_for(position);
    } else if constexpr (slider == bishop) {
        return generate_bishop_xray_visibility_for(position);
    }

    return 0ULL;
}

template<Slider slider>
[[nodiscard]] constexpr std::array<Bitboard, All_Positions.size()> generate_slider_visibilities() {
    std::array<Bitboard, All_Positions.size()> visibilities{};

    for ( const auto position : All_Positions) {
        visibilities[std::to_underlying(position)] = generate_slider_xray_visibility_for<slider>(position);
    }

    return visibilities;
}

void generate_xray_visibility_tables(std::ofstream &of) {
    constexpr std::array<Bitboard, All_Positions.size()> rook_xray_visibility_table = generate_slider_visibilities<Slider_t::rook>();
    constexpr std::array<Bitboard, All_Positions.size()> bishop_xray_visibility_table = generate_slider_visibilities<Slider_t::bishop>();

    output_array(of, rook_xray_visibility_table, "rook_xray_visibility_table", "Bitboard");
    output_array(of, bishop_xray_visibility_table, "bishop_xray_visibility_table", "Bitboard");
}



/*************************************************************************
 *
 * pin table generator
 *
 ************************************************************************/

template<Slider slider>
constexpr Bitboard generate_rook_pin_mask_towards_king(const int64_t king_rank, const int64_t king_file,
                                                       const int64_t piece_rank,
                                                       const int64_t piece_file) {
    auto r = piece_rank;
    auto f = piece_file;
    Bitboard ray = 1ULL << (r * 8 + f);


    if (king_file == piece_file) {
        if (king_rank > piece_rank) {
            for (; r < king_rank; ++r) {
                ray |= 1ULL << (r * 8 + f);
            }
            return ray;
        } else {
            for (; r > king_rank; --r) {
                ray |= 1ULL << (r * 8 + f);
            }
            return ray;
        }
    } else if (king_rank == piece_rank) {
        if (king_file > piece_file) {
            for (; f < king_file; ++f) {
                ray |= 1ULL << (r * 8 + f);
            }
            return ray;
        } else {
            for (; f >= king_file; --f) {
                ray |= 1ULL << (r * 8 + f);
            }
            return ray;
        }
    }
    return 0x0ULL;
}

template<Slider slider>
constexpr Bitboard generate_bishop_pin_mask(const int64_t king_rank, const int64_t king_file, const int64_t piece_rank,
                                            const int64_t piece_file) {
    auto r = piece_rank;
    auto f = piece_file;

    Bitboard ray = 1ULL << (r * 8 + f);

    if (piece_rank - piece_file == king_rank - king_file) {
        if (piece_rank < king_rank) {
            for (; r < king_rank && f < king_file; ++r, ++f) {
                ray |= 1ULL << (r * 8 + f);
            }
            return ray;
        } else {
            for (; r > king_rank && f > king_file; --r, --f) {
                ray |= 1ULL << (r * 8 + f);
            }
            return ray;
        }
    }

    if (piece_rank + piece_file == king_rank + king_file) {
        if (piece_rank > king_rank) {
            for (; r > king_rank && f > king_file; --r, --f) {
                ray |= 1ULL << (r * 8 + f);
            }
            return ray;
        } else {
            for (; r < king_rank && f < king_file; ++r, ++f) {
                ray |= 1ULL << (r * 8 + f);
            }
            return ray;
        }
    }
    return 0x0ULL;
}

template<Slider slider>
constexpr Bitboard generate_pin_mask_for_position(Square piece_position, Square king_position) {
    using enum Slider_t;

    static_assert(slider == rook || slider == bishop);

    const auto king_rank = static_cast<int64_t>(std::to_underlying(king_position) / 8);
    const auto king_file = static_cast<int64_t>(std::to_underlying(king_position) % 8);
    const auto piece_rank = static_cast<int64_t>(std::to_underlying(piece_position) / 8);
    const auto piece_file = static_cast<int64_t>(std::to_underlying(piece_position) % 8);

    if constexpr (slider == rook) {
        return generate_rook_pin_mask_towards_king<slider>(king_rank, king_file, piece_rank, piece_file);
    } else if constexpr (slider == bishop) {
        return generate_bishop_pin_mask<slider>(king_rank, king_file, piece_rank, piece_file);
    }

    return 0x0ULL;
}


template<Slider slider>
constexpr std::vector<Bitboard> generate_pin_table() {
    std::vector<Bitboard> pin_table(4096, 0ULL);

    for (const auto &piece_position: All_Positions) {
        for (const auto &king_position: All_Positions) {
            const std::size_t index = std::to_underlying(piece_position) * 64 + std::to_underlying(
                                          king_position);
            if (piece_position == king_position) {
                pin_table[index] = 0xFFFFFFFFFFFFFFFFULL;
                continue;
            }

            pin_table[index] = generate_pin_mask_for_position<slider>(piece_position, king_position);
        }
    }
    return pin_table;
}

void generate_pin_tables(std::ofstream &of) {
    const std::vector<Bitboard> rook_pin_table = generate_pin_table<Slider_t::rook>();
    const std::vector<Bitboard> bishop_pin_table = generate_pin_table<Slider_t::bishop>();

    output_array(of, rook_pin_table, "rook_pin_table", "Bitboard");
    output_array(of, bishop_pin_table, "bishop_pin_table", "Bitboard");
}


void generate_masks(std::ofstream &of) {
    constexpr std::array<Bitboard, 64> bishop_attack_masks = create_attack_masks<Slider_t::bishop>();
    constexpr std::array<Bitboard, 64> rook_attack_masks = create_attack_masks<Slider_t::rook>();

    output_array(of, bishop_attack_masks, "bishop_attack_masks", "Bitboard");
    output_array(of, rook_attack_masks, "rook_attack_masks", "Bitboard");
}

#ifdef GENERATE_MAGICS
void generate_magic_numbers(std::ofstream &of) {
    const std::array<MagicNumber, 64> Bishop_Magic_Numbers = Constants::Impl::find_magic_numbers_for<Slider::bishop>();
    const std::array<MagicNumber, 64> Rook_Magic_Numbers = Constants::Impl::find_magic_numbers_for<Slider::rook>();

    output_array(of, Bishop_Magic_Numbers, "bishop_magic_numbers", "MagicNumber");
    output_array(of, Rook_Magic_Numbers, "rook_magic_numbers", "MagicNumber");
}
#endif

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
#elif GENERATE_PIN_TABLES
    generate_pin_tables(of);
#elif GENERATE_XRAY_VISIBILITY_TABLES
    generate_xray_visibility_tables(of);
#endif


    of << "} // namespace Constants\n";
    of.close();

    return 0;
}
