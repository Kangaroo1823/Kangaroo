

if(NOT TARGET Kangaroo_options)
    message(ERROR " Need target 'Kangaroo_options' to build tests")
endif ()

if(NOT TARGET Kangaroo_warnings)
    message( ERROR " Need target 'Kangaroo_warnings to build tests")
endif ()

# take care of the test executable
add_executable(Kangaroo_tests
        bitboard_tests.cpp
        attack_mask_tests.cpp
        create_possible_slider_moves_tests.cpp
        create_occupation_of_mask_tests.cpp
        magic_numbers_test.cpp
        attack_tables_tests.cpp
        generate_pawn_moves_tests.cpp)
target_link_libraries(Kangaroo_tests PRIVATE Boost::bind Kangaroo_library Kangaroo_options Kangaroo_warnings gtest gtest_main)
target_include_directories(Kangaroo_tests PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/tools)
