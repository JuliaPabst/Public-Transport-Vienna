cmake_minimum_required(VERSION 3.27)
project(Program)

set(CMAKE_CXX_STANDARD 17)

add_executable(Program main.cpp
        Program.cpp
        Program.h
        Graph.cpp
        Graph.h
        PathFinder.cpp
        PathFinder.h)
