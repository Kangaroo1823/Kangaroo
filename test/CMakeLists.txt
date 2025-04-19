

if (NOT TARGET Kangaroo_options)
    message(ERROR " Need target 'Kangaroo_options' to build tests")
endif ()

if (NOT TARGET Kangaroo_warnings)
    message(ERROR " Need target 'Kangaroo_warnings to build tests")
endif ()

# take care of the test executable
add_executable(Kangaroo_tests
        bitboard_tests.cpp
        attack_mask_tests.cpp
        create_possible_slider_moves_tests.cpp
        create_occupation_of_mask_tests.cpp
        magic_numbers_test.cpp
        attack_tables_tests.cpp
        Pawn_Move_Generation/generate_pawn_moves_tests.cpp
        Pin_Mask_Generation/Tests.cpp
        Pawn_Move_Generation/Empty_Board.cpp
        Pawn_Move_Generation/Simple.cpp
        Pawn_Move_Generation/Promotion1.cpp
        Pawn_Move_Generation/Pins1.cpp
        Pawn_Move_Generation/Pins2.cpp
        Pawn_Move_Generation/Pins3.cpp
        Pawn_Move_Generation/EnPassant1.cpp
        Pawn_Move_Generation/EnPassant2.cpp
        Pawn_Move_Generation/EnPassant3.cpp
        Pawn_Move_Generation/EnPassant4.cpp
        Pawn_Move_Generation/Check1.cpp
        Knight_Move_Generation/Simple.cpp
        Knight_Move_Generation/PinHV.cpp
        Knight_Move_Generation/PinD.cpp
        Knight_Move_Generation/Check1.cpp
        Rook_Move_Generation/Simple1.cpp
        Rook_Move_Generation/Blocking.cpp
        Rook_Move_Generation/HV_Pin.cpp
        Rook_Move_Generation/D_Pin.cpp
        Bishop_Move_Generator/Simple1.cpp
        Bishop_Move_Generator/Blocking.cpp
        Bishop_Move_Generator/Pin_D.cpp
        Bishop_Move_Generator/Pin_HV.cpp
        Queen_Move_Generator/Simple.cpp
        Rook_Move_Generation/Check1.cpp
        Bishop_Move_Generator/Check.cpp
        Queen_Move_Generator/Blocking.cpp
        Queen_Move_Generator/Pin_HV.cpp
        Queen_Move_Generator/Pin_D.cpp
        Queen_Move_Generator/Check_D.cpp)
target_link_libraries(Kangaroo_tests
        PRIVATE
        Kangaroo
        Kangaroo_options
        Kangaroo_warnings
        gtest
        gtest_main
        fmt::fmt
        spdlog::spdlog
)
target_compile_definitions(Kangaroo_tests PRIVATE COMPILE_TESTS)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo_tests PRIVATE stdc++exp)
endif ()

target_include_directories(Kangaroo_tests PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tools)
