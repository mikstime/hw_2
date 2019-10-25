cmake_minimum_required(VERSION 3.7)
project(hw_2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall  -lm")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
add_executable(hw_2 main.c staticLib/catch.hpp)
add_executable(static_tests staticLib/tests.cpp "staticLib/catch.hpp")

find_package( Threads REQUIRED )

add_executable(static_main static_main.c)
add_subdirectory(calculus)
add_subdirectory(staticLib)

target_link_libraries(hw_2 calculus_lib)
target_link_libraries(static_tests calculus_lib staticLib_lib)
target_link_libraries(static_main calculus_lib staticLib_lib ${CMAKE_THREAD_LIBS_INIT})