cmake_minimum_required(VERSION 3.10.0)
set (CMAKE_CXX_STANDARD 17)

project(SmarthomeSimulation)

include_directories(
    .
)

add_subdirectory(lib)
add_subdirectory(bin)
