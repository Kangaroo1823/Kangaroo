
set(CMAKE_CXX_STANDARD 20)

##############################################
#
# see that fmt is valiable
#
##############################################
Include(FetchContent)

FetchContent_Declare(
        FMT
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG        11.0.2 # or a later release
)

FetchContent_MakeAvailable(FMT)


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
        ../include/queen_attack_masks.h)
target_link_libraries(ChessEngineLib PUBLIC fmt::fmt)

# take care of the main executable
add_executable(ChessEngine
        main.cpp
        ../include/bitboard.h
)
target_link_libraries(ChessEngine PRIVATE ChessEngineLib)
