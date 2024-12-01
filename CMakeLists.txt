cmake_minimum_required(VERSION 3.30)
project(ChessEngine)


# fetch Catch2 and GoogleBenchmark as a testing- and benchmarking-framework, respectively
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)

FetchContent_Declare(
        GoogleBenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG        v1.9.1 # or a later release
)

FetchContent_Declare(
        FMT
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG        11.0.2 # or a later release
)

FetchContent_Declare(
        QT
        GIT_REPOSITORY https://github.com/qt/qt5.git
        GIT_TAG        v6.8.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
FetchContent_MakeAvailable(GoogleBenchmark)

FetchContent_MakeAvailable(FMT)
FetchContent_MakeAvailable(QT)

# create a library to hold the tested logic of the ChessEngine
add_library(ChessEngineLib src/Bitboard.h src/Bitboard.cpp
        src/pawn_attacks.h
        src/colors.h
        src/king_attacks.h
        src/chess_board.cpp
        src/chess_board.h
        src/knight_attacks.h)
target_link_libraries(ChessEngineLib PUBLIC fmt::fmt)

# take care of the test executable
add_executable(ChessEngineTests test/test.cpp
        src/pawn_attacks.h
        src/colors.h
        src/king_attacks.h
        src/chess_board.h
        src/knight_attacks.h)
target_link_libraries(ChessEngineTests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(ChessEngineTests PRIVATE ChessEngineLib)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(ChessEngineTests)


# take care of the main executable
set(CMAKE_CXX_STANDARD 20)
add_executable(ChessEngine
        src/main.cpp
        src/Bitboard.h
)
target_link_libraries(ChessEngine PRIVATE ChessEngineLib)
