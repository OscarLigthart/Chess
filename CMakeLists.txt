cmake_minimum_required( VERSION 3.1 )

project( chess )

find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(deps/glfw)

target_link_libraries(chess glfw)

target_link_libraries(chess OpenGL::GL)


