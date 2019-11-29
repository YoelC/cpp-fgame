cmake_minimum_required(VERSION 3.15)
project(sandbox)

set(CMAKE_CXX_STANDARD 14)
add_executable(sandbox main.cpp player.h player.cpp)
target_link_libraries(sandbox SDL2)
