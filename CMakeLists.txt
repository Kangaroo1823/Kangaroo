cmake_minimum_required(VERSION 3.30)
# This template attempts to be "fetch_content"-able
# so that it works well with tools like CPM or other
# manual dependency management

# Set the cxx_standard
set(CMAKE_CXX_STANDARD 23)


# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the project name and language
project(
        Kangaroo
        VERSION 0.0.1
        DESCRIPTION ""
        HOMEPAGE_URL "https://github.com/pml76/Kangaroo"
        LANGUAGES CXX C)

include(cmake/PreventInSourceBuilds.cmake)

include(KangarooOptions.cmake)
Kangaroo_setup_options()
Kangaroo_global_options()

include(Dependencies.cmake)
Kangaroo_setup_dependencies()

Kangaroo_local_options()

# set(CMAKE_VERBOSE_MAKEFILE ON)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(benchmark)
add_subdirectory(tools)