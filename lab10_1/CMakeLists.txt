cmake_minimum_required(VERSION 3.20)
project(Lab10_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab10_1 main.cpp src/csvLib.cpp src/MyException.cpp)

include_directories(include)
