cmake_minimum_required(VERSION 3.10.0)
set (CMAKE_CXX_STANDARD 17)

project(SmarthomeSimulation)

target_include_directories(SmarthomeSimulation ${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(lib)
add_subdirectory(bin)
