
macro(setup_compiler_options)

    # fix for msys gcc and google benchmark.
    if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNTDDI_VERSION=0x0A000010")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DNTDDI_VERSION=0x0A000010")
    endif ()

endmacro()