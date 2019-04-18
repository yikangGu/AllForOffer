cmake_minimum_required(VERSION 2.8)

project(19-03-13)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable(1 1.cpp)
add_executable(2 2.cpp)
