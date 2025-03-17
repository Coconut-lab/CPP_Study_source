cmake_minimum_required(VERSION 3.30)
project(CPP_Study_source)

set(CMAKE_CXX_STANDARD 98)

add_library(CPP_Study_source STATIC library.cpp
        test.cpp
        중간/2/example-2-1.cpp
        중간/2/example-2-2.cpp
        중간/2/example-2-3.cpp
        중간/2/example-2-4.cpp
        중간/2/example-2-5.cpp
        중간/2/example-2-6.cpp
        중간/2/example-2-7.cpp
        중간/2/book-chap-2-9.cpp
        중간/3/example-3-1.cpp)
add_executable(library test.cpp)
add_executable(test test.cpp)
add_executable(example-2-1 중간/2/example-2-1.cpp)
add_executable(example-2-2 중간/2/example-2-2.cpp)
add_executable(example-2-3 중간/2/example-2-3.cpp)
add_executable(example-2-4 중간/2/example-2-4.cpp)
add_executable(example-2-5 중간/2/example-2-5.cpp)
add_executable(example-2-6 중간/2/example-2-6.cpp)
add_executable(example-2-7 중간/2/example-2-7.cpp)
add_executable(book-chap-2-9 중간/2/book-chap-2-9.cpp)