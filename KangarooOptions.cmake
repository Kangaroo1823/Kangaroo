include(cmake/SystemLink.cmake)
include(cmake/LibFuzzer.cmake)
include(CMakeDependentOption)
include(CheckCXXCompilerFlag)


macro(Kangaroo_supports_sanitizers)
    if((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND NOT WIN32)
        set(SUPPORTS_UBSAN ON)
    else()
        set(SUPPORTS_UBSAN OFF)
    endif()

    if((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND WIN32)
        set(SUPPORTS_ASAN OFF)
    else()
        set(SUPPORTS_ASAN ON)
    endif()
endmacro()

macro(Kangaroo_setup_options)
    option(Kangaroo_ENABLE_HARDENING "Enable hardening" ON)
    option(Kangaroo_ENABLE_COVERAGE "Enable coverage reporting" OFF)
    cmake_dependent_option(
            Kangaroo_ENABLE_GLOBAL_HARDENING
            "Attempt to push hardening options to built dependencies"
            ON
            Kangaroo_ENABLE_HARDENING
            OFF)

    Kangaroo_supports_sanitizers()

    if(NOT PROJECT_IS_TOP_LEVEL OR Kangaroo_PACKAGING_MAINTAINER_MODE)
        option(Kangaroo_USE_MOLD "enable mold for linking" ON)
        option(Kangaroo_ENABLE_IPO "Enable IPO/LTO" OFF)
        option(Kangaroo_WARNINGS_AS_ERRORS "Treat Warnings As Errors" OFF)
        option(Kangaroo_ENABLE_USER_LINKER "Enable user-selected linker" OFF)
        option(Kangaroo_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" OFF)
        option(Kangaroo_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
        option(Kangaroo_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" OFF)
        option(Kangaroo_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
        option(Kangaroo_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
        option(Kangaroo_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
        option(Kangaroo_ENABLE_CLANG_TIDY "Enable clang-tidy" OFF)
        option(Kangaroo_ENABLE_CPPCHECK "Enable cpp-check analysis" OFF)
        option(Kangaroo_ENABLE_PCH "Enable precompiled headers" OFF)
        option(Kangaroo_ENABLE_CACHE "Enable ccache" OFF)
    else()
        option(Kangaroo_USE_MOLD "enable mold for linking" ON)
        option(Kangaroo_ENABLE_IPO "Enable IPO/LTO" ON)
        option(Kangaroo_OPTIMIZE_FOR_NATIVE "Build with -march=native" ON)
        option(Kangaroo_WARNINGS_AS_ERRORS "Treat Warnings As Errors" ON)
        option(Kangaroo_ENABLE_USER_LINKER "Enable user-selected linker" OFF)
        option(Kangaroo_ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" ${SUPPORTS_ASAN})
        option(Kangaroo_ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
        option(Kangaroo_ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" ${SUPPORTS_UBSAN})
        option(Kangaroo_ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
        option(Kangaroo_ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
        option(Kangaroo_ENABLE_UNITY_BUILD "Enable unity builds" OFF)
        option(Kangaroo_ENABLE_CLANG_TIDY "Enable clang-tidy" ON)
        option(Kangaroo_ENABLE_CPPCHECK "Enable cpp-check analysis" ON)
        option(Kangaroo_ENABLE_PCH "Enable precompiled headers" OFF)
        option(Kangaroo_ENABLE_CACHE "Enable ccache" ON)
    endif()

    if(NOT PROJECT_IS_TOP_LEVEL)
        mark_as_advanced(
                Kangaroo_ENABLE_IPO
                Kangaroo_WARNINGS_AS_ERRORS
                Kangaroo_ENABLE_USER_LINKER
                Kangaroo_ENABLE_SANITIZER_ADDRESS
                Kangaroo_ENABLE_SANITIZER_LEAK
                Kangaroo_ENABLE_SANITIZER_UNDEFINED
                Kangaroo_ENABLE_SANITIZER_THREAD
                Kangaroo_ENABLE_SANITIZER_MEMORY
                Kangaroo_ENABLE_UNITY_BUILD
                Kangaroo_ENABLE_CLANG_TIDY
                Kangaroo_ENABLE_CPPCHECK
                Kangaroo_ENABLE_COVERAGE
                Kangaroo_ENABLE_PCH
                Kangaroo_ENABLE_CACHE)
    endif()

    Kangaroo_check_libfuzzer_support(LIBFUZZER_SUPPORTED)
    if(LIBFUZZER_SUPPORTED AND (Kangaroo_ENABLE_SANITIZER_ADDRESS OR Kangaroo_ENABLE_SANITIZER_THREAD OR Kangaroo_ENABLE_SANITIZER_UNDEFINED))
        set(DEFAULT_FUZZER ON)
    else()
        set(DEFAULT_FUZZER OFF)
    endif()

    option(Kangaroo_BUILD_FUZZ_TESTS "Enable fuzz testing executable" ${DEFAULT_FUZZER})

endmacro()

macro(Kangaroo_global_options)

    if(Kangaroo_USE_MOLD)
        include(cmake/CheckForMold.cmake)
        Kangaroo_enable_mold()
    endif ()

    if(Kangaroo_OPTIMIZE_FOR_NATIVE)
        include(cmake/OptimizeForNative.cmake)
        Kangaroo_optimize_for_native()
    endif ()

    Kangaroo_supports_sanitizers()

#    if(Kangaroo_ENABLE_HARDENING AND Kangaroo_ENABLE_GLOBAL_HARDENING)
#        include(cmake/Hardening.cmake)
#        if(NOT SUPPORTS_UBSAN
#                OR Kangaroo_ENABLE_SANITIZER_UNDEFINED
#                OR Kangaroo_ENABLE_SANITIZER_ADDRESS
#                OR Kangaroo_ENABLE_SANITIZER_THREAD
#                OR Kangaroo_ENABLE_SANITIZER_LEAK)
#            set(ENABLE_UBSAN_MINIMAL_RUNTIME FALSE)
#        else()
#            set(ENABLE_UBSAN_MINIMAL_RUNTIME TRUE)
#        endif()
#        message("${Kangaroo_ENABLE_HARDENING} ${ENABLE_UBSAN_MINIMAL_RUNTIME} ${Kangaroo_ENABLE_SANITIZER_UNDEFINED}")
#        Kangaroo_enable_hardening(Kangaroo_options ON ${ENABLE_UBSAN_MINIMAL_RUNTIME})
#    endif()
endmacro()

macro(Kangaroo_local_options)
    if(PROJECT_IS_TOP_LEVEL)
        include(cmake/StandardProjectSettings.cmake)
    endif()

    add_library(Kangaroo_warnings INTERFACE)
    add_library(Kangaroo_options INTERFACE)

    include(cmake/CompilerWarnings.cmake)
    Kangaroo_set_project_warnings(
            Kangaroo_warnings
            ${Kangaroo_WARNINGS_AS_ERRORS}
            ""
            ""
            ""
            "")

    if(Kangaroo_ENABLE_USER_LINKER)
        include(cmake/Linker.cmake)
        Kangaroo_configure_linker(Kangaroo_options)
    endif()

#    include(cmake/Sanitizers.cmake)
#    Kangaroo_enable_sanitizers(
#            Kangaroo_options
#            ${Kangaroo_ENABLE_SANITIZER_ADDRESS}
#            ${Kangaroo_ENABLE_SANITIZER_LEAK}
#            ${Kangaroo_ENABLE_SANITIZER_UNDEFINED}
#            ${Kangaroo_ENABLE_SANITIZER_THREAD}
#            ${Kangaroo_ENABLE_SANITIZER_MEMORY})
#
    set_target_properties(Kangaroo_options PROPERTIES UNITY_BUILD ${Kangaroo_ENABLE_UNITY_BUILD})

    if(Kangaroo_ENABLE_PCH)
        target_precompile_headers(
                Kangaroo_options
                INTERFACE
                <vector>
                <string>
                <utility>)
    endif()

    if(Kangaroo_ENABLE_CACHE)
        include(cmake/Cache.cmake)
        Kangaroo_enable_cache()
    endif()

    include(cmake/StaticAnalyzers.cmake)
    if(Kangaroo_ENABLE_CLANG_TIDY)
        Kangaroo_enable_clang_tidy(Kangaroo_options ${Kangaroo_WARNINGS_AS_ERRORS})
    endif()

    if(Kangaroo_ENABLE_CPPCHECK)
        Kangaroo_enable_cppcheck(${Kangaroo_WARNINGS_AS_ERRORS} "" # override cppcheck options
        )
    endif()

    if(Kangaroo_ENABLE_COVERAGE)
        include(cmake/Tests.cmake)
        Kangaroo_enable_coverage(Kangaroo_options)
    endif()

    if(Kangaroo_WARNINGS_AS_ERRORS)
        check_cxx_compiler_flag("-Wl,--fatal-warnings" LINKER_FATAL_WARNINGS)
        if(LINKER_FATAL_WARNINGS)
            # This is not working consistently, so disabling for now
            # target_link_options(Kangaroo_options INTERFACE -Wl,--fatal-warnings)
        endif()
    endif()

#    if(Kangaroo_ENABLE_HARDENING AND NOT Kangaroo_ENABLE_GLOBAL_HARDENING)
#        include(cmake/Hardening.cmake)
#        if(NOT SUPPORTS_UBSAN
#                OR Kangaroo_ENABLE_SANITIZER_UNDEFINED
#                OR Kangaroo_ENABLE_SANITIZER_ADDRESS
#                OR Kangaroo_ENABLE_SANITIZER_THREAD
#                OR Kangaroo_ENABLE_SANITIZER_LEAK)
#            set(ENABLE_UBSAN_MINIMAL_RUNTIME FALSE)
#        else()
#            set(ENABLE_UBSAN_MINIMAL_RUNTIME TRUE)
#        endif()
#        Kangaroo_enable_hardening(Kangaroo_options OFF ${ENABLE_UBSAN_MINIMAL_RUNTIME})
#    endif()

endmacro()
