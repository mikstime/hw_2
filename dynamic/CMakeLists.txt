cmake_minimum_required(VERSION 3.7)

project(dynamic)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(SOURCES src/dynamic.c src/compute_distance.c)
set(HEADERS include/dynamic.h include/compute_distance.h)

add_library(dynamic_lib SHARED ${SOURCES} ${HEADERS})
target_include_directories(dynamic_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)
target_link_libraries(calculus_lib)