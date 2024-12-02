

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

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
FetchContent_MakeAvailable(GoogleBenchmark)