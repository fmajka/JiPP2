cmake_minimum_required(VERSION 3.20)
project(simpleCalc)

set(CMAKE_CXX_STANDARD 14)

add_executable(simpleCalc src/main.cpp  src/simpleCalc.cpp)


include_directories(include)
