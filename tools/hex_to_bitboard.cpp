// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 05/01/2025.
//


#include "bitboard.h"
#include <print>

int main (int argc, char *argv[]) {

  if (argc != 2) {
    std::print("Usage: {} <hex_string>\n", argv[0]);
    return 1;
  }

  std::string hex_string = argv[1];
  Bitboard bb = Bitboard_from_hex(hex_string);

  print_bitboard(bb);



  return 0;
}