cmake_minimum_required(VERSION 3.16)

project(example)
include_directories(include)

add_executable(e1NoCopyingConstructor src/main.cpp src/Point.cpp src/Pojazd.cpp)