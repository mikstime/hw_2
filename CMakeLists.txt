cmake_minimum_required(VERSION 3.15)
project(hw_2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_executable(hw_2 main.c)
add_executable(hw_2_tests tests/tests.cpp)