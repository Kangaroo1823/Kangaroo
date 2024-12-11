
##############################################
#
# see that fmt is available
#
##############################################
#Include(FetchContent)
#FetchContent_Declare(
#        FMT
#        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
#        GIT_TAG        11.0.2 # or a later release
#)
#FetchContent_MakeAvailable(FMT)

##############################################
#
# see that boost is available
#
##############################################
#set(BOOST_INCLUDE_LIBRARIES thread filesystem system program_options random)
#set(BOOST_ENABLE_CMAKE ON)
#FetchContent_Declare(
#        Boost
#        GIT_REPOSITORY https://github.com/boostorg/boost.git
#        GIT_TAG boost-1.86.0
#        GIT_SHALLOW TRUE
#)
# FetchContent_MakeAvailable(Boost)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /EHsc /arch:AVX2" )
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /bigobj /EHsc /arch:AVX2" )
    set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} /bigobj /EHsc /arch:AVX2" )

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Ot")
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O2 /Ot")
    set(CMAKE_LD_FLAGS_RELEASE "${CMAKE_LD_FLAGS_RELEASE} /O2 /Ot")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
        # using clang with clang-cl front end
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /EHsc /arch:AVX2 " )
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /bigobj /EHsc /arch:AVX2" )
        set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} /bigobj /EHsc /arch:AVX2" )

        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Ot")
        set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O2 /Ot")
        set(CMAKE_LD_FLAGS_RELEASE "${CMAKE_LD_FLAGS_RELEASE} /O2 /Ot")
    elseif (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
        # using clang with regular front end
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=x86-64-v3")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=x86-64-v3")
        set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -march=x86-64-v3")

        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -O3 -flto")
        set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -march=native -O3 -flto")
        set(CMAKE_LD_FLAGS_RELEASE "${CMAKE_LD_FLAGS_RELEASE} -march=native -O3 -flto")
    endif()
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=x86-64-v3")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=x86-64-v3")
    set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -march=x86-64-v3")

endif()

# create a library to hold the tested logic of the ChessEngine
add_library(ChessEngineLib ../include/bitboard.h
        bitboard.cpp
        ../include/pawn_attacks.h
        ../include/colors.h
        ../include/king_attacks.h
        chess_board.cpp
        ../include/chess_board.h
        ../include/knight_attacks.h
        ../include/rook_attack_masks.h
        ../include/bishop_attack_masks.h
        create_possible_rook_moves.cpp
        ../include/create_possible_rook_moves.h
        ../include/create_possible_bishop_moves.h
        create_possible_bishop_moves.cpp
        create_occupantion_of_mask.cpp
        ../include/create_occupantion_of_mask.h
        ../include/base.h)
target_link_libraries(ChessEngineLib
        PUBLIC
        fmt::fmt
        # Boost::random
)

# take care of the main executable
add_executable(ChessEngine
        main.cpp
        ../include/bitboard.h
        ../include/create_possible_bishop_moves.h
        ../include/create_occupantion_of_mask.h
        ../include/base.h
)
target_link_libraries(ChessEngine PRIVATE ChessEngineLib)
