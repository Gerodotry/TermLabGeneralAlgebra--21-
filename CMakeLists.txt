cmake_minimum_required(VERSION 3.23)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab main.cpp sources/utils/Vector.cpp headers/utils/Vector.h sources/algorithms/VectorMultiplication.cpp headers/algorithms/VectorMultiplication.h)

include_directories(h headers)
