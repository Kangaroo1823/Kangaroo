macro(Kangaroo_optimize_for_native)

    # in case we use msvc we want to generate avx2 code:
    if (MSVC)
        if (NOT ${CMAKE_CXX_FLAGS} MATCHES ".*/arch:AVX2")
            include(CheckCXXCompilerFlag)

            # does the compiler support it?
            CHECK_CXX_COMPILER_FLAG("/arch:AVX2" COMPILER_SUPPORTS_MARCH_NATIVE)
            if (COMPILER_SUPPORTS_MARCH_NATIVE)
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /arch:AVX2" CACHE STRING "Compiler Flags for C++" FORCE)
            endif ()

        endif ()

        if (NOT (${CMAKE_C_FLAGS} MATCHES ".*/arch:AVX2.*"))
            include(CheckCCompilerFlag)

            CHECK_C_COMPILER_FLAG("/arch:AVX2" COMPILER_SUPPORTS_MARCH_NATIVE)
            if (COMPILER_SUPPORTS_MARCH_NATIVE)
                set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /arch:AVX2" CACHE STRING "Compiler Flags for C" FORCE)
            endif ()

        endif ()

    elseif (CMAKE_CXX_COMPILER_ID MATCHES ".*Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

        if (NOT (${CMAKE_CXX_FLAGS} MATCHES ".*-march=native") )

            CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
            if (COMPILER_SUPPORTS_MARCH_NATIVE)
                set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native" CACHE STRING "Compiler Flags for C++" FORCE)
            endif ()

        endif ()

        if (NOT (${CMAKE_C_FLAGS} MATCHES ".*-march=native.*"))
            include(CheckCCompilerFlag)

            CHECK_C_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
            if (COMPILER_SUPPORTS_MARCH_NATIVE)
                set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=native" CACHE STRING "Compiler Flags for C" FORCE)
            endif ()

        endif ()

    else ()

        message(AUTHOR_WARNING "No native code support for CXX compiler: '${CMAKE_CXX_COMPILER_ID}'")
        # TODO support Intel compiler

    endif ()

endmacro()