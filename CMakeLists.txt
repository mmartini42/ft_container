cmake_minimum_required(VERSION 3.21)
project(ft_container CXX)

set(CMAKE_CXX_STANDARD 98)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "./src/*.cpp")
file(GLOB_RECURSE HEADER RELATIVE ${CMAKE_SOURCE_DIR} "./incs/*.hpp")

include_directories(${CMAKE_SOURCE_DIR}/incs/)

add_executable(ft_container ${SOURCES} incs/Map/Pair.hpp incs/Map/TreeStruct.hpp)
