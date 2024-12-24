project(KangarooConstantsGenerator)


set(CONSTANTS_GENERATOR_SOURCES
        constants_generator.cpp
        ../include/bitboard.h
        ../src/bitboard.cpp
        ../include/colors.h
        ../src/chess_board.cpp
        ../include/chess_board.h
        attack_masks.h
        create_possible_slider_moves.h
        ../include/base.h
        magic_numbers.h
        ../src/magic_numbers.cpp
        ../include/constants.h
        ../include/types.h
        ../include/move_generator.h
)

################################
#
# masks-generator
#
################################
add_executable(Kangaroo_constants_generator_masks ${CONSTANTS_GENERATOR_SOURCES})
target_link_libraries(Kangaroo_constants_generator_masks
        PUBLIC
        Kangaroo_warnings
)

target_include_directories(Kangaroo_constants_generator_masks
        PRIVATE
        ../include/
        ${CMAKE_BINARY_DIR}
)
target_compile_definitions(Kangaroo_constants_generator_masks PUBLIC GENERATE_MASKS)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/constants_masks.h"
        COMMAND Kangaroo_constants_generator_masks ${CMAKE_BINARY_DIR}/constants_masks.h
        DEPENDS Kangaroo_constants_generator_masks  # Make sure "mytool" is built before this runs
        COMMENT "Generating 'constants_masks.h' using Kangaroo_constants_generator_masks ..."
)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/constants_masks.h.gch"
        COMMAND ${CMAKE_C_COMPILER} -I../include/ ${CMAKE_BINARY_DIR}/constants_masks.h.gch
        DEPENDS Kangaroo_constants_generator_masks  # Make sure "mytool" is built before this runs
        COMMENT "Generating 'constants_masks.h' using Kangaroo_constants_generator_masks ..."
)

add_custom_target(
        generate_masks
        DEPENDS "${CMAKE_BINARY_DIR}/constants_masks.h"

)

################################
#
# magics-generator
#
################################
add_executable(Kangaroo_constants_generator_magics ${CONSTANTS_GENERATOR_SOURCES})
target_link_libraries(Kangaroo_constants_generator_magics
        PUBLIC
        Kangaroo_warnings)

target_include_directories(Kangaroo_constants_generator_magics
        PRIVATE
        ../include/
        ${CMAKE_BINARY_DIR}
)
target_compile_definitions(Kangaroo_constants_generator_magics PUBLIC GENERATE_MAGICS)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/constants_magics.h"
        COMMAND ${CMAKE_BINARY_DIR}/tools/Kangaroo_constants_generator_magics ${CMAKE_BINARY_DIR}/constants_magics.h
        DEPENDS Kangaroo_constants_generator_magics  # Make sure "mytool" is built before this runs
        COMMENT "Generating 'constants_magics.h' using Kangaroo_constants_generator_magics ... (this might take a while)"
)

add_custom_target(
        generate_magics
        DEPENDS "${CMAKE_BINARY_DIR}/constants_magics.h"

)


add_dependencies(Kangaroo_constants_generator_magics generate_masks)



################################
#
# attacks-generator
#
################################
add_executable(Kangaroo_constants_generator_attacks ${CONSTANTS_GENERATOR_SOURCES})
target_link_libraries(Kangaroo_constants_generator_attacks
        PUBLIC
        Kangaroo_warnings)

target_include_directories(Kangaroo_constants_generator_attacks
        PRIVATE
        ../include/
        ${CMAKE_BINARY_DIR}
)
target_compile_definitions(Kangaroo_constants_generator_attacks PUBLIC GENERATE_ATTACKS)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/constants_attacks.h"
        COMMAND ${CMAKE_BINARY_DIR}/tools/Kangaroo_constants_generator_attacks ${CMAKE_BINARY_DIR}/constants_attacks.h
        DEPENDS Kangaroo_constants_generator_attacks  # Make sure "mytool" is built before this runs
        COMMENT "Generating 'constants_attacks.h' using Kangaroo_constants_generator_attacks ... (this might take a while)"
)
add_dependencies(Kangaroo_constants_generator_attacks generate_masks generate_magics)

add_custom_target(
        generate_attacks
        DEPENDS "${CMAKE_BINARY_DIR}/constants_attacks.h"

)

##################################################
#
# a target to make other targets depend on
#
##################################################
add_custom_target(
        generate_files DEPENDS
        ${CMAKE_BINARY_DIR}/constants_masks.h
        ${CMAKE_BINARY_DIR}/constants_magics.h
        ${CMAKE_BINARY_DIR}/constants_attacks.h
)

target_precompile_headers(Kangaroo_options INTERFACE
        ${CMAKE_BINARY_DIR}/constants_masks.h
        ${CMAKE_BINARY_DIR}/constants_magics.h
        ${CMAKE_BINARY_DIR}/constants_attacks.h
)

add_dependencies(Kangaroo_options generate_files)

target_compile_definitions(Kangaroo_options INTERFACE
        USE_PRECOMPILED_GENERATED_HEADERS
)
