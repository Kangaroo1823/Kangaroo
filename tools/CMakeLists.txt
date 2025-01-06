project(KangarooConstantsGenerator)


set(CONSTANTS_GENERATOR_SOURCES

)

################################
#
# masks-generator
#
################################
add_executable(Kangaroo_constants_generator_masks
        constants_generator.cpp
        ../include/bitboard.h
        ../src/bitboard.cpp
        ../include/colors.h
        attack_masks.h
        create_possible_slider_moves.h
        ../include/base.h
        ../include/constants.h
        ../include/types.h
        ../include/move_generator.h)
target_link_libraries(Kangaroo_constants_generator_masks
        PUBLIC
        Kangaroo_warnings
)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo_constants_generator_masks PRIVATE stdc++exp)
endif ()


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
add_executable(Kangaroo_constants_generator_magics constants_generator.cpp
        ../include/bitboard.h
        ../src/bitboard.cpp
        ../include/colors.h
        attack_masks.h
        create_possible_slider_moves.h
        ../include/base.h
        magic_numbers.h
        magic_numbers.cpp
        ../include/constants.h
        ../include/types.h
        ../include/move_generator.h)
target_link_libraries(Kangaroo_constants_generator_magics
        PUBLIC
        Kangaroo_warnings
)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo_constants_generator_magics PRIVATE stdc++exp)
endif ()


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
add_executable(Kangaroo_constants_generator_attacks
        constants_generator.cpp
        ../include/bitboard.h
        ../src/bitboard.cpp
        ../include/colors.h
        attack_masks.h
        create_possible_slider_moves.h
        ../include/base.h
        magic_numbers.h
        magic_numbers.cpp
        ../include/constants.h
        ../include/types.h
        ../include/move_generator.h)
target_link_libraries(Kangaroo_constants_generator_attacks
        PUBLIC
        Kangaroo_warnings
)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo_constants_generator_attacks PRIVATE stdc++exp)
endif ()


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
# pin-table-generator
#
##################################################
add_executable(Kangaroo_constants_generator_pin_tables
        constants_generator.cpp
        ../include/bitboard.h
        ../src/bitboard.cpp
        ../include/colors.h)
target_link_libraries(Kangaroo_constants_generator_pin_tables
        PUBLIC
        Kangaroo_warnings
)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo_constants_generator_pin_tables PRIVATE stdc++exp)
endif ()


target_include_directories(Kangaroo_constants_generator_pin_tables
        PRIVATE
        ../include/
        ${CMAKE_BINARY_DIR}
)
target_compile_definitions(Kangaroo_constants_generator_pin_tables PUBLIC GENERATE_PIN_TABLES)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/constants_pin_tables.h"
        COMMAND ${CMAKE_BINARY_DIR}/tools/Kangaroo_constants_generator_pin_tables ${CMAKE_BINARY_DIR}/constants_pin_tables.h
        DEPENDS Kangaroo_constants_generator_pin_tables  # Make sure "mytool" is built before this runs
        COMMENT "Generating 'constants_pin_tables.h' using Kangaroo_constants_generator_pin_tables ... (this might take a while)"
)

add_custom_target(
        generate_pin_tables
        DEPENDS "${CMAKE_BINARY_DIR}/constants_pin_tables.h"
)


##################################################
#
# xray_visibility-table-generator
#
##################################################
add_executable(Kangaroo_constants_generator_xray_visibility_tables
        constants_generator.cpp
        ../include/bitboard.h
        ../src/bitboard.cpp
        ../include/colors.h)
target_link_libraries(Kangaroo_constants_generator_xray_visibility_tables
        PUBLIC
        Kangaroo_warnings
)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo_constants_generator_xray_visibility_tables PRIVATE stdc++exp)
endif ()


target_include_directories(Kangaroo_constants_generator_xray_visibility_tables
        PRIVATE
        ../include/
        ${CMAKE_BINARY_DIR}
)
target_compile_definitions(Kangaroo_constants_generator_xray_visibility_tables PUBLIC GENERATE_XRAY_VISIBILITY_TABLES)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/constants_xray_visibility_tables.h"
        COMMAND ${CMAKE_BINARY_DIR}/tools/Kangaroo_constants_generator_xray_visibility_tables ${CMAKE_BINARY_DIR}/constants_xray_visibility_tables.h
        DEPENDS Kangaroo_constants_generator_xray_visibility_tables  # Make sure "mytool" is built before this runs
        COMMENT "Generating 'constants_xray_visibility_tables.h' using Kangaroo_constants_generator_xray_visibility_tables ... (this might take a while)"
)

add_custom_target(
        generate_xray_visibility_tables
        DEPENDS "${CMAKE_BINARY_DIR}/constants_xray_visibility_tables.h"
)

####################################
#
# hex_to_bitboard
#
# tool that reads a hex number from
# std::cin and outputs it as a
# bitboard
#
####################################

add_executable( hex_to_bitboard
        hex_to_bitboard.cpp
        ../include/bitboard.h
        ../src/bitboard.cpp
)
target_link_libraries( hex_to_bitboard PRIVATE Kangaroo_warnings )
target_include_directories( hex_to_bitboard PRIVATE ../include )


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
        ${CMAKE_BINARY_DIR}/constants_pin_tables.h
        ${CMAKE_BINARY_DIR}/constants_xray_visibility_tables.h
)

add_dependencies(Kangaroo_options generate_files)
