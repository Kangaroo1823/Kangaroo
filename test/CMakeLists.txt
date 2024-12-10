

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)


# take care of the test executable
add_executable(ChessEngineTests
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
target_link_libraries(ChessEngineTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(ChessEngineTests PRIVATE ChessEngineLib)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(ChessEngineTests)

