cmake_minimum_required(VERSION 3.1)

project(chess)

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/img)

add_subdirectory(deps/glfw)

find_package(OpenGL REQUIRED)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_executable( chess src/main.cpp )

target_link_libraries(chess glfw)
target_link_libraries(chess sfml-graphics sfml-audio)
target_link_libraries(chess OpenGL::GL)

