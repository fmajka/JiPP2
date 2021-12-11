cmake_minimum_required(VERSION 3.20)
project(StopExample)

set(CMAKE_CXX_STANDARD 14)

add_executable(StopExample vExample.cpp Stop.cpp Stop.h Line.cpp Line.h)
