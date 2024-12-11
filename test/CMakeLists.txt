

if(NOT TARGET Kangaroo_options)
    message(ERROR " Need target 'Kangaroo_options' to build tests")
endif ()

if(NOT TARGET Kangaroo_warnings)
    message( ERROR " Need target 'Kangaroo_warnings to build tests")
endif ()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=x86-64-v3")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=x86-64-v3")
set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -march=x86-64-v3")

# take care of the test executable
add_executable(Kangaroo_tests
        ../include/pawn_attacks.h
        ../include/colors.h
        ../include/king_attacks.h
        ../include/chess_board.h
        ../include/knight_attacks.h
        ../include/rook_attack_masks.h
        ../include/bishop_attack_masks.h
        bitboard_tests.cpp
        pawn_attack_tests.cpp
        king_attack_tests.cpp
        knight_attacks_tests.cpp
        rook_attack_mask_tests.cpp
        bishop_attack_mask_tests.cpp
        ../include/create_possible_rook_moves.h
        create_possible_rook_moves_tests.cpp
        create_possible_bishop_moves_tests.cpp
        ../include/create_possible_bishop_moves.h
        ../include/create_occupantion_of_mask.h
        create_occupantion_of_mask_tests.cpp
        ../include/base.h)
target_link_libraries(Kangaroo_tests PRIVATE Kangaroo_library Kangaroo_options Kangaroo_warnings Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(Kangaroo_tests)

