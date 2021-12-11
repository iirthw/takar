project (RunTakar)

set (SOURCE_FILES main.cpp)
add_executable (${PROJECT_NAME} ${SOURCE_FILES})

# set VS startup project
set_property (
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} 
    PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}
    )

get_target_property (
    MAIN_LIBRARY_INCLUDES ${CMAKE_PROJECT_NAME} 
    INCLUDE_DIRECTORIES
    )

target_include_directories (
    ${PROJECT_NAME} 
    PUBLIC ${MAIN_LIBRARY_INCLUDES}
    )
