

if(NOT TARGET Kangaroo_options)
    message(ERROR " Need target 'Kangaroo_options' to build tests")
endif ()

if(NOT TARGET Kangaroo_warnings)
    message( ERROR " Need target 'Kangaroo_warnings to build tests")
endif ()

# take care of the test executable
add_executable(Kangaroo_tests
        bitboard_tests.cpp
        pawn_attack_tests.cpp
        king_attack_tests.cpp
        knight_attacks_tests.cpp
        rook_attack_mask_tests.cpp
        bishop_attack_mask_tests.cpp
        create_possible_rook_moves_tests.cpp
        create_possible_bishop_moves_tests.cpp
        create_occupation_of_mask_tests.cpp)
target_link_libraries(Kangaroo_tests PRIVATE Kangaroo_library Kangaroo_options Kangaroo_warnings Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(Kangaroo_tests)

