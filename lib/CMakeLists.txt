set (HEADER_FILES public/foobar/foobar.h)
set (IMPL_FILES impl/foobar/foobar.cc)
set (SOURCE_FILES ${HEADER_FILES} ${IMPL_FILES})

add_library (${CMAKE_PROJECT_NAME} STATIC ${SOURCE_FILES})
target_include_directories (
    ${CMAKE_PROJECT_NAME} 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/public
    )