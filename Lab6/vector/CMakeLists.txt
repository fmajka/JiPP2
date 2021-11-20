cmake_minimum_required(VERSION 3.20)
project(vector)

set(CMAKE_CXX_STANDARD 14)

add_executable(vector main.cpp Vector.cpp Imaginary.cpp Imaginary.h)
