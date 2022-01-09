cmake_minimum_required(VERSION 3.1)

project(chess)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/img)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


set(HEADERS
    include/board.hpp
    include/piece.hpp
    include/pieces/bishop.hpp
    include/pieces/king.hpp
    include/pieces/queen.hpp
    include/pieces/rook.hpp
    include/pieces/pawn.hpp
    include/pieces/knight.hpp
)

set(SOURCES
    src/board.cpp
    src/piece.cpp
    src/pieces/rook.cpp
)

add_executable(chess 
    src/main.cpp
    src/pieces/rook.cpp
    include/pieces/rook.hpp
)

target_link_libraries(chess sfml-graphics sfml-audio)


