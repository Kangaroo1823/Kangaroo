project("Kangaroo_benchmark")

add_executable(Kangaroo_benchmark attack_mask_benchmarks.cpp)
target_link_libraries(Kangaroo_benchmark PRIVATE
        Boost::bind
        Kangaroo_library
        Kangaroo_options
        Kangaroo_warnings
        benchmark::benchmark
)
target_include_directories(Kangaroo_benchmark PRIVATE ../include)