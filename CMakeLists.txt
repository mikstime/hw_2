cmake_minimum_required(VERSION 3.7)
project(hw_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall  -lm")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall  -lm")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

find_package( Threads REQUIRED )

add_executable(static_tests staticLib/tests.cpp "staticLib/catch.hpp")
add_executable(dynamic_tests dynamic/tests.cpp "staticLib/catch.hpp")
add_executable(static_main static_main.c)
add_executable(dynamic_main dynamic_main.c)

#add_subdirectory(calculus)
add_subdirectory(staticLib)
add_subdirectory(dynamic)

target_link_libraries(static_tests staticLib_lib)
target_link_libraries(static_main staticLib_lib ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(dynamic_tests PRIVATE dynamic_lib ${CMAKE_DL_LIBS})
target_link_libraries(dynamic_main PRIVATE dynamic_lib ${CMAKE_DL_LIBS})