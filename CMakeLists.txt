cmake_minimum_required(VERSION 3.12)
project(polynomial_calc)

set(CMAKE_CXX_STANDARD 11)

add_executable(polynomial_calc main.cpp polynomial.cpp polynomial.h)