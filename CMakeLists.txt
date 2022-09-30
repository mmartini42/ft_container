cmake_minimum_required(VERSION 3.23)
project(ft_container CXX)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_container src/main.cpp map.hpp vector.hpp stack.hpp iterator/is_integral.hpp iterator/enable_if.hpp iterator/iterator.hpp vector_test.cpp Algorithm.hpp)
