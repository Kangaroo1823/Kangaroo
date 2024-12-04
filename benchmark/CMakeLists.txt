

##################################################
#
# make GoogleBenchmark available
#
##################################################
Include(FetchContent)

FetchContent_Declare(
        GoogleBenchmark
        GIT_REPOSITORY https://github.com/google/benchmark.git
        GIT_TAG        v1.9.1 # or a later release
)

set(HAVE_STD_REGEX ON)
set(RUN_HAVE_STD_REGEX 1)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
FetchContent_MakeAvailable(GoogleBenchmark)