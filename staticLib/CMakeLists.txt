cmake_minimum_required(VERSION 3.7)

project(staticLib)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_library(staticLib_lib include/static.h src/static.c  include/compute_distance.h src/compute_distance.c)
target_include_directories(staticLib_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(calculus_lib)