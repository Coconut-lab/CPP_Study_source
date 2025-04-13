cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(CPP_Study_source)

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
        중간/3/example-3-1.cpp
        중간/3/example-3-3.cpp
        중간/3/example-3-4.cpp
        중간/3/example-3-5.cpp
        중간/3/example-3-6.cpp
        중간/3/example-3-7.cpp
        중간/3/example-3-8.cpp
        중간/3/example-3-2.cpp
        중간/3/example-3-10.cpp
        중간/3/Adder.h
        중간/3/Calculator.h
        "중간/3/example-3-11.cpp"
        중간/3/Calculator.cpp
        중간/3/Adder.cpp
        중간/4/example-4-1.cpp
        중간/4/example-4-2.cpp
        중간/4/example-4-3.cpp
        중간/4/example-4-5.cpp
        중간/4/example-4-6.cpp
        중간/4/book_code-211.cpp
        중간/4/example-4-8.cpp
        중간/4/example-4-8-1.cpp
        중간/4/example-4-9.cpp
        중간/4/example-4-10.cpp
        중간/4/example-4-12.cpp
        중간/4/book_code-213.cpp
        중간/4/example-4-14.cpp
        중간/5/example-5-2.cpp
        중간/5/example-5-5.cpp
        중간/5/example-5-8.cpp
        과제/4/ATMachine.h
        과제/4/Account.h
        중간/5/example-5-9.cpp
        중간/5/example-5-10.cpp
        중간/5/example-5-11.c
        중간/5/book-274-11.cpp
        중간/6/example-6-2.cpp
        중간/6/example-6-3.cpp
        중간/6/example-6-5.cpp
        중간/6/example-6-9.cpp
        중간/6/book-313-1.cpp)
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
add_executable(example-3-3 중간/3/example-3-3.cpp)
add_executable(example-3-4 중간/3/example-3-4.cpp)
add_executable(example-3-6 중간/3/example-3-6.cpp)
add_executable(example-3-7 중간/3/example-3-7.cpp)
add_executable(example-3-8 중간/3/example-3-8.cpp)
add_executable(example-3-2 중간/3/example-3-2.cpp)
add_executable(example-3-10 중간/3/example-3-10.cpp)
add_executable(example-3-11 중간/3/example-3-11.cpp 중간/3/Adder.cpp 중간/3/Calculator.cpp)

add_executable(Adder 중간/3/Adder.cpp)
add_executable(Calculator 중간/3/Calculator.cpp)
add_executable(example-4-1 중간/4/example-4-1.cpp)
add_executable(example-4-2 중간/4/example-4-2.cpp)
add_executable(example-4-5 중간/4/example-4-5.cpp)
add_executable(example-4-6 중간/4/example-4-6.cpp)
add_executable(book_code-211 중간/4/book_code-211.cpp)
add_executable(example-4-8 중간/4/example-4-8.cpp)
add_executable(example-4-8-1 중간/4/example-4-8-1.cpp)
add_executable(example-4-9 중간/4/example-4-9.cpp)
add_executable(example-4-10 중간/4/example-4-10.cpp)
add_executable(example-4-12 중간/4/example-4-12.cpp)
add_executable(book_code-213 중간/4/book_code-213.cpp)
add_executable(example-4-14 중간/4/example-4-14.cpp)
add_executable(example-5-2 중간/5/example-5-2.cpp)
add_executable(example-5-5 중간/5/example-5-5.cpp)
add_executable(main 과제/4/main.cpp 과제/4/Account.cpp 과제/4/ATMachine.cpp)
add_executable(example-5-9 중간/5/example-5-9.cpp)
add_executable(book-274-11 중간/5/book-274-11.cpp)
add_executable(example-6-2 중간/6/example-6-2.cpp)
add_executable(example-6-5 중간/6/example-6-5.cpp)
add_executable(example-6-9 중간/6/example-6-9.cpp)
add_executable(book-313-1 중간/6/book-313-1.cpp)