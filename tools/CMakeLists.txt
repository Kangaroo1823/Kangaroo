project(KangarooConstantsGenerator)


set( CONSTANTS_GENERATOR_SOURCES
        constants_generator.cpp
        ../include/bitboard.h
        ../src/bitboard.cpp
        ../include/colors.h
        ../src/chess_board.cpp
        ../include/chess_board.h
        ../include/attack_masks.h
        ../include/create_possible_slider_moves.h
        ../include/base.h
        ../include/magic_numbers.h
        ../src/magic_numbers.cpp
        ../include/constants.h
)

################################
#
# masks-generator
#
################################
add_executable(Kangaroo_constants_generator_masks ${CONSTANTS_GENERATOR_SOURCES} )
target_link_libraries(Kangaroo_constants_generator_masks
        PUBLIC
        fmt::fmt
        Kangaroo_options
        Kangaroo_warnings)

target_include_directories(Kangaroo_constants_generator_masks
        PRIVATE
        ../include/)
target_compile_definitions(Kangaroo_constants_generator_masks PUBLIC GENERATE_MASKS)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/constants_masks.h"
        COMMAND ${CMAKE_BINARY_DIR}/tools/Kangaroo_constants_generator_masks "${CMAKE_BINARY_DIR}/constants_masks.h"
        DEPENDS Kangaroo_constants_generator_masks  # Make sure "mytool" is built before this runs
        COMMENT "Generating 'constants_masks.h' using Kangaroo_constants_generator ..."
)

################################
#
# magics-generator
#
################################
add_executable(Kangaroo_constants_generator_magics ${CONSTANTS_GENERATOR_SOURCES} )
target_link_libraries(Kangaroo_constants_generator_magics
        PUBLIC
        fmt::fmt
        Kangaroo_options
        Kangaroo_warnings)

target_include_directories(Kangaroo_constants_generator_magics
        PRIVATE
        ../include/)
target_compile_definitions(Kangaroo_constants_generator_magics PUBLIC GENERATE_MAGICS)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/constants_magics.h"
        COMMAND ${CMAKE_BINARY_DIR}/tools/Kangaroo_constants_generator_magics "${CMAKE_BINARY_DIR}/constants_magics.h"
        DEPENDS Kangaroo_constants_generator_magics  # Make sure "mytool" is built before this runs
        COMMENT "Generating 'constants_magics.h' using Kangaroo_constants_generator ..."
)

##################################################
#
# a target to make other targets depend on
#
##################################################
add_custom_target(
        generate_files
        DEPENDS "${CMAKE_BINARY_DIR}/constants_masks.h" "${CMAKE_BINARY_DIR}/constants_magics.h"

)

