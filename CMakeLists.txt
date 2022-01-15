cmake_minimum_required(VERSION 3.17)
project(Playlist)

set(CMAKE_CXX_STANDARD 14)

add_executable(Playlist main.cpp Song.cpp Song.h Playlist.cpp Playlist.h)