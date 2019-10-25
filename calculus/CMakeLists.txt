cmake_minimum_required(VERSION 3.7)

project(calculus)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_library(calculus_lib include/compute_distance.h src/compute_distance.c)
target_include_directories(calculus_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)