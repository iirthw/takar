cmake_minimum_required (VERSION 3.19)
set (CMAKE_CXX_STANDARD 14)

# -----------------------------------------------------------------------------

project (Takar)

# Group CMake predefined targets in one VS folder
set_property (GLOBAL PROPERTY USE_FOLDERS ON)

# -----------------------------------------------------------------------------
# Add subdirectories.
# -----------------------------------------------------------------------------

add_subdirectory (lib)
add_subdirectory (takar)
add_subdirectory (test)

# -----------------------------------------------------------------------------
# Submodules
# -----------------------------------------------------------------------------
add_subdirectory (third-party/glfw)
add_subdirectory (third-party/mq-math)

# Turn off/on docs, tests, examples
set (GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set (GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set (GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# -----------------------------------------------------------------------------
