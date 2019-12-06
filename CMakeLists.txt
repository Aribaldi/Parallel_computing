cmake_minimum_required(VERSION 3.15)
project(task1_mmul)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fopenmp")


set(SOURCE_FILES main.cpp)
add_executable(task1_mmul  ${SOURCE_FILES})