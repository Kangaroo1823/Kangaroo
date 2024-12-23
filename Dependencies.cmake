set(CPM_SOURCE_CACHE "${CMAKE_SOURCE_DIR}/cpm_source_cache")
set(CPM_USE_NAMED_CACHE_DIRECTORIES ON)

include(cmake/CPM.cmake)
# Done as a function so that updates to variables like
# CMAKE_CXX_FLAGS don't propagate out to other
# targets
function(Kangaroo_setup_dependencies)

    # For each dependency, see if it's
    # already been provided to us by a parent project

    if (NOT TARGET fmt::fmt)
        cpmaddpackage("gh:fmtlib/fmt#11.0.2")
    endif ()

#    if (NOT TARGET Boost::boost)
#        CPMAddPackage(
#                NAME Boost
#                VERSION 1.87.0
#                URL https://github.com/boostorg/boost/releases/download/boost-1.87.0/boost-1.87.0-cmake.zip
#                URL_HASH SHA256=03530dec778bc1b85b070f0b077f3b01fd417133509bb19fe7c142e47777a87b
#                OPTIONS "BOOST_ENABLE_CMAKE ON"
#        )
#    endif ()

#    if (NOT TARGET Catch2::Catch2WithMain)
#        cpmaddpackage(
#                NAME
#                Catch2
#                VERSION
#                3.4.0
#                GITHUB_REPOSITORY
#                "catchorg/Catch2"
#        )
#        list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
#        set (CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} PARENT_SCOPE)
#    endif ()

    if(NOT TARGET gtest_main)
        CPMAddPackage(
                NAME googletest
                GITHUB_REPOSITORY google/googletest
                GIT_TAG release-1.12.1
                VERSION 1.15.2
                OPTIONS "INSTALL_GTEST OFF" "gtest_force_shared_crt"
        )
    endif ()


    if (NOT TARGET benchmark::benchmark)
        set(HAVE_STD_REGEX ON)
        set(RUN_HAVE_STD_REGEX 1)
        set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
        set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
        cpmaddpackage(
                NAME
                benchmark
                VERSION
                1.9.1
                GITHUB_REPOSITORY
                "google/benchmark"
        )
    endif ()

    #  if(NOT TARGET spdlog::spdlog)
    #    cpmaddpackage(
    #      NAME
    #      spdlog
    #      VERSION
    #      1.11.0
    #      GITHUB_REPOSITORY
    #      "gabime/spdlog"
    #      OPTIONS
    #      "SPDLOG_FMT_EXTERNAL ON")
    #  endif()

    #  if(NOT TARGET Catch2::Catch2WithMain)
    #    cpmaddpackage("gh:catchorg/Catch2@3.3.2")
    #  endif()

    #  if(NOT TARGET CLI11::CLI11)
    #    cpmaddpackage("gh:CLIUtils/CLI11@2.3.2")
    #  endif()

    #  if(NOT TARGET ftxui::screen)
    #    cpmaddpackage("gh:ArthurSonzogni/FTXUI@5.0.0")
    #  endif()

    #  if(NOT TARGET tools::tools)
    #    cpmaddpackage("gh:lefticus/tools#update_build_system")
    #  endif()

endfunction()
