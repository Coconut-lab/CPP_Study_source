cmake_minimum_required(VERSION 3.30)
project(CPP_Study_source)

set(CMAKE_CXX_STANDARD 98)

add_library(CPP_Study_source STATIC library.cpp
        test.cpp)
add_executable(library test.cpp)
add_executable(test test.cpp)