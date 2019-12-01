cmake_minimum_required(VERSION 3.15)
project(cpp-fgame)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
add_executable(cpp-fgame main.cpp player.h player.cpp physics_cube.h physics_cube.cpp)
target_link_libraries(cpp-fgame ${SDL2_LIBRARIES})
