project("Kangaroo_benchmark")

add_executable(Kangaroo_benchmark attack_mask_benchmarks.cpp)
target_link_libraries(Kangaroo_benchmark PRIVATE
        Kangaroo_library
        Kangaroo_options
        Kangaroo_warnings
        benchmark::benchmark
)

if (WIN32 AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(Kangaroo_benchmark PRIVATE stdc++exp)
endif ()

target_include_directories(Kangaroo_benchmark PRIVATE ../include)