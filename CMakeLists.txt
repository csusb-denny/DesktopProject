cmake_minimum_required(VERSION 3.29)
project(DesktopProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(DesktopProject main.cpp
        FileHandler.h
        Original.cpp
        FileHandler.cpp)
