cmake_minimum_required (VERSION 3.19)

set (CMAKE_CXX_STANDARD 14)
project (Takar)

# Group CMake predefined targets in one VS folder
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory (lib)
add_subdirectory (takar)
add_subdirectory (test)