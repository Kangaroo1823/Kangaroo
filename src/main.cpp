
#include "magic_numbers.h"

#include <attack_tables.h>


int main(int argc, char **) {
    Constants::Impl::compute_magic_numbers();


    return static_cast<int>(Constants::rook_attack_masks[static_cast<std::size_t>(argc)]);
}
