cmake_minimum_required(VERSION 3.23)
project(Lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab main.cpp sources/utils/Vector.cpp headers/utils/Vector.h sources/algorithms/VectorMultiplication.cpp headers/algorithms/VectorMultiplication.h sources/algorithms/MillerRabinTest.cpp tests/MillerRabinTestTests.cpp  headers/algorithms/Gcd.h sources/algorithms/Gcd.cpp sources/algorithms/Gcd.cpp tests/GcdTests.cpp sources/algorithms/Remainder.cpp headers/algorithms/Remainder.h sources/algorithms/Division.cpp headers/algorithms/Division.h)

include_directories(h headers)
