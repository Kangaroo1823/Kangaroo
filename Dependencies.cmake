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

    if (NOT TARGET Boost::boost)
        cpmaddpackage("gh:boostorg/boost#boost-1.86.0")
    endif ()

    if (NOT TARGET Catch2::Catch2WithMain)
        cpmaddpackage(
                NAME
                Catch2
                VERSION
                3.4.0
                GITHUB_REPOSITORY
                "catchorg/Catch2"
        )
        list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
        set (CMAKE_MODULE_PATH  ${CMAKE_MODULE_PATH} PARENT_SCOPE)
    endif ()

    if (NOT TARGET benchmark::benchmark_main)
        set(HAVE_STD_REGEX ON)
        set(RUN_HAVE_STD_REGEX 1)
        set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
        set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
        cpmaddpackage("gh:google/benchmark@1.9.1")
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
