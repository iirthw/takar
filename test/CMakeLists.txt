# Download GoogleTest as an external project
include (${PROJECT_SOURCE_DIR}/cmake/download_gtest.cmake)

project (RunUnitTests)

set (SOURCE_FILES test_foobar.cc)
add_executable (${PROJECT_NAME} main.cc ${SOURCE_FILES})

# Get the Engine include directories
get_target_property (
    MAIN_LIBRARY_INCLUDES TakarEngine
    INCLUDE_DIRECTORIES
    )

target_include_directories (
    ${PROJECT_NAME} 
    PUBLIC ${MAIN_LIBRARY_INCLUDES}
    )
    
target_link_libraries (${PROJECT_NAME} TakarEngine gtest)

# Uncomment the following, if test resources are needed
# configure_file (
#    ${CMAKE_CURRENT_SOURCE_DIR}/resources/simple.json 
#    ${CMAKE_CURRENT_BINARY_DIR}/resources/simple.json COPYONLY
# )

# In order to treat warning as error, uncomment the following:
# if (MSVC)
#   target_compile_options (RunUnitTests PRIVATE /W4 /WX)
# else ()
#   target_compile_options (RunUnitTests PRIVATE -Wall -Wextra -Wpedantic -Werror)
# endif ()
