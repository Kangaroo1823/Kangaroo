set( CMAKE_VERBOSE_MAKEFILE ON )

if(NOT TARGET Kangaroo_options)
    message(ERROR " Need target 'Kangaroo_options' to build Kangaroo_library")
endif ()

if(NOT TARGET Kangaroo_warnings)
    message( ERROR " Need target 'Kangaroo_warnings to build Kangaroo_library")
endif ()

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

       # set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -O3 -flto")
       # set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -march=native -O3 -flto")
       # set(CMAKE_LD_FLAGS_RELEASE "${CMAKE_LD_FLAGS_RELEASE} -march=native -O3 -flto")
    endif()
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=x86-64-v3")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=x86-64-v3")
    set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -march=x86-64-v3")

endif()

find_package(OpenMP)

# create a library to hold the tested logic of the ChessEngine
add_library(Kangaroo_library ../include/bitboard.h
        bitboard.cpp
        ../include/colors.h
        chess_board.cpp
        ../include/chess_board.h
        ../include/base.h
        ../include/constants.h
        ../include/types.h
        ../include/move_generator.h
        ../include/Board_Status.h
        Movement_Generator.cpp
        ../include/Movement_Generator.h
        Move_Receiver.cpp
        ../include/Move_Receiver.h
        Board_Status.cpp
)
target_link_libraries(Kangaroo_library
        PUBLIC
        gtest
        Kangaroo_warnings
        Kangaroo_options
)

if(OpenMP_CXX_FOUND)
    target_link_libraries(Kangaroo_library PUBLIC OpenMP::OpenMP_CXX)
endif()

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo_library PRIVATE stdc++exp)
endif ()


target_include_directories(Kangaroo_library PRIVATE ../include)
target_include_directories(Kangaroo_library PUBLIC ${CMAKE_BINARY_DIR})
add_dependencies(Kangaroo_library generate_files)


# take care of the main executable
add_executable(Kangaroo
        main.cpp
)
target_link_libraries(Kangaroo PRIVATE Kangaroo_library Kangaroo_options Kangaroo_warnings)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo PRIVATE stdc++exp)
endif ()

target_include_directories(Kangaroo PRIVATE ../include)


if(Kangaroo_ENABLE_IPO)
    include(../cmake/InterproceduralOptimization.cmake)
    Kangaroo_enable_ipo_for_target(Kangaroo_library)
    Kangaroo_enable_ipo_for_target(Kangaroo)
endif()
