set( CMAKE_VERBOSE_MAKEFILE ON )

include(GenerateExportHeader)

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

#if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /EHsc /arch:AVX2" )
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /bigobj /EHsc /arch:AVX2" )
#    set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} /bigobj /EHsc /arch:AVX2" )
#
#    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Ot")
#    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O2 /Ot")
#    set(CMAKE_LD_FLAGS_RELEASE "${CMAKE_LD_FLAGS_RELEASE} /O2 /Ot")
#elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#    if (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC")
#        # using clang with clang-cl front end
#        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj /EHsc /arch:AVX2 " )
#        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /bigobj /EHsc /arch:AVX2" )
#        set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} /bigobj /EHsc /arch:AVX2" )
#
#        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Ot")
#        set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} /O2 /Ot")
#        set(CMAKE_LD_FLAGS_RELEASE "${CMAKE_LD_FLAGS_RELEASE} /O2 /Ot")
#    elseif (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "GNU")
#        # using clang with regular front end
#        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=x86-64-v3")
#        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=x86-64-v3")
#        set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -march=x86-64-v3")
#
#       # set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -march=native -O3 -flto")
#       # set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -march=native -O3 -flto")
#       # set(CMAKE_LD_FLAGS_RELEASE "${CMAKE_LD_FLAGS_RELEASE} -march=native -O3 -flto")
#    endif()
#else()
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=x86-64-v3")
#    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=x86-64-v3")
#    set(CMAKE_LD_FLAGS "${CMAKE_LD_FLAGS} -march=x86-64-v3")
#
#endif()

find_package(OpenMP)

# create a library to hold the tested logic of the ChessEngine
add_library(Kangaroo
        Bit_Board.cpp
        Chess_Board.cpp
        ../include/Bit_Board.h
        ../include/Chess_Board.h
        ../include/Base.h
        ../include/Constants.h
        ../include/Types.h
        ../include/Board_Status.h
        ../include/Move_Generator/Board_Converter.h
        ../include/Move_Generator/Pin_And_Check_Mask_Generator.h
        ../include/Move_Generator/Pawn_Move_Generator.h
        ../include/Move_Evaluator/Movement_Evaluator.h
        ../include/Move_Generator/Move_Generator.h
        Logger.cpp
        ../include/Logger.h
        ../include/Move_Generator/Callback_Handler.h
        ../include/Move_Generator/Knight_Move_Generator.h
        ../include/Move_Generator/Rook_Move_Generator.h
        ../include/Address_Attack_Tables.h
        ../include/Get_Attacks_For.h
        ../include/Move_Generator/Bishop_Move_Generator.h
)
target_link_libraries(Kangaroo
        PUBLIC
        Kangaroo_warnings
        Kangaroo_options
        spdlog::spdlog
        fmt::fmt
)


target_compile_definitions(Kangaroo PUBLIC LOG_DIRECTORY="${CMAKE_BINARY_DIR}")
generate_export_header(Kangaroo)
if(OpenMP_CXX_FOUND)
    target_link_libraries(Kangaroo PUBLIC OpenMP::OpenMP_CXX)
endif()

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo PRIVATE stdc++exp)
endif ()


target_include_directories(Kangaroo PUBLIC ../include)
target_include_directories(Kangaroo PUBLIC ${CMAKE_BINARY_DIR}/src)
target_include_directories(Kangaroo PUBLIC ${CMAKE_BINARY_DIR})
add_dependencies(Kangaroo generate_files)


# take care of the main executable
add_executable(Kangaroo_bin
        main.cpp
)
target_link_libraries(Kangaroo_bin
        PRIVATE
        Kangaroo
        Kangaroo_options
        Kangaroo_warnings
        fmt::fmt
        spdlog::spdlog
)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo_bin PRIVATE stdc++exp)
endif ()

target_include_directories(Kangaroo_bin PRIVATE ../include)


if(Kangaroo_ENABLE_IPO)
    include(../cmake/InterproceduralOptimization.cmake)
    Kangaroo_enable_ipo_for_target(Kangaroo)
    Kangaroo_enable_ipo_for_target(Kangaroo_bin)
endif()
