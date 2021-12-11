cmake_minimum_required(VERSION 3.20)
project(Player)

set(CMAKE_CXX_STANDARD 14)

add_executable(Player main.cpp Playlist.cpp Playlist.h Track.cpp Track.h)
