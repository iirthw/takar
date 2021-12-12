project (TakarEngine)

# -----------------------------------------------------------------------------

find_package (OpenGL REQUIRED)
include_directories (${OPENGL_INCLUDE_DIRS})

# -----------------------------------------------------------------------------

set (HEADER_FILES public/foobar/foobar.h)
set (IMPL_FILES impl/foobar/foobar.cc)
set (THIRD_PARTY_IMPL_FILES ../third-party/glad/src/glad.c)
set (SOURCE_FILES ${HEADER_FILES} ${IMPL_FILES} ${THIRD_PARTY_IMPL_FILES})

# -----------------------------------------------------------------------------

add_library (TakarEngine STATIC ${SOURCE_FILES})

target_include_directories (
    TakarEngine 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/public
    # Third-party include directories
    "../third-party/glfw/include"
    "../third-party/glad/include"
    )

# -----------------------------------------------------------------------------