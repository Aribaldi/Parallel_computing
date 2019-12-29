cmake_minimum_required(VERSION 3.15)
project(task1_mmul)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")


set(SOURCE_FILES task1_maxminsearch.cpp task2_mmult.cpp utils.hpp utils.cpp task1_maxminsearch.hpp main.cpp task2_mmult.hpp task3_mvmult.hpp task3_mvmult.cpp)
add_executable(task1_mmul  ${SOURCE_FILES})