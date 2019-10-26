cmake_minimum_required(VERSION 3.7)

project(dynamic)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

set(SOURCES src/dynamic.c src/compute_distance.c)
set(HEADERS include/dynamic.h include/compute_distance.h)

add_library(dynamic_lib SHARED ${SOURCES} ${HEADERS})

target_include_directories(dynamic_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} include)

#install(TARGETS dynamic_lib EXPORT ${SOURCES} ${HEADERS}
#        LIBRARY DESTINATION lib ARCHIVE DESTINATION lib INCLUDES DESTINATION include)
#install(FILES dynamic.h DESTINATION include)
#install(EXPORT myLibTargets
#        FILE myLibConfig.cmake NAMESPACE MyLib:: DESTINATION lib/cmake/MyLib)