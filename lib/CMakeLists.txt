project (TakarEngine)

# -----------------------------------------------------------------------------

find_package (OpenGL REQUIRED)
include_directories (${OPENGL_INCLUDE_DIRS})

# -----------------------------------------------------------------------------

set (HEADER_FILES 
	 public/geometry/mesh.h
     public/image.h
	 public/rendering/node.h
	 )

set (IMPL_FILES
    impl/geometry/mesh.cpp
    impl/image.cpp
    )

source_group (TakarEngine
    FILES
    public/image.h
    impl/image.cpp
    )

source_group (geometry
    FILES
    public/geometry/mesh.h
    impl/geometry/mesh.cpp
    )

source_group (glad
    FILES
    ../third-party/glad/src/glad.c
    )

source_group (rendering
    FILES
    public/rendering/node.h
    )

set (THIRD_PARTY_IMPL_FILES ../third-party/glad/src/glad.c)
set (SOURCE_FILES ${HEADER_FILES} ${IMPL_FILES} ${THIRD_PARTY_IMPL_FILES})

# -----------------------------------------------------------------------------

add_library (TakarEngine STATIC ${SOURCE_FILES})

target_include_directories (
    TakarEngine 
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/public
    # Third-party include directories
    "../third-party/glad/include"
    "../third-party/glfw/include"
    "../third-party/mq-math/public"
    "../third-party/stb_image_clone"
    )

# -----------------------------------------------------------------------------

# To treat warning as error, uncomment the following:
# if (MSVC)
#   target_compile_options (TakarEngine PRIVATE /W4 /WX)
# else ()
#   target_compile_options (TakarEngine PRIVATE -Wall -Wextra -Wpedantic -Werror)
# endif ()

# -----------------------------------------------------------------------------
