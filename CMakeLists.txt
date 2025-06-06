cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## UTF-8 인코딩 설정 (한글 문제 해결)
#if(WIN32)
#    # Windows에서 MSVC 컴파일러 사용시
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
#    add_definitions(/utf-8)
#elseif(APPLE)
#    # macOS에서 Clang 컴파일러 사용시
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")
#    add_definitions(-DUTF8)
#else()
#    # Linux에서 GCC 컴파일러 사용시
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=UTF-8 -fexec-charset=UTF-8")
#endif()

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
        중간/5/example-5-9.cpp
        중간/5/example-5-10.cpp
        중간/5/example-5-11.c
        중간/5/book-274-11.cpp
        중간/6/example-6-2.cpp
        중간/6/example-6-3.cpp
        중간/6/example-6-5.cpp
        중간/6/example-6-9.cpp
        중간/6/book-313-1.cpp
        중간/6/example-static.cpp
        중간/6/example-6-10.cpp
        중간/6/example-6-11.cpp
        중간/6/book-314-4.cpp
        중간/7/example-7-1.cpp
        중간/7/example-7-2.cpp
        중간/7/example-7-4.cpp
        중간/7/example-7-5.cpp
        중간/7/example-7-6.cpp
        중간/7/example-7-7.cpp
        중간/7/example-7-8.cpp
        중간/7/example-7-9.cpp
        중간/7/example-7-11.cpp
        중간/7/example-7-13.cpp
        중간/7/example-7-14.cpp
        기말/8/example-8-3.cpp
        기말/8/example-8-7.cpp
        기말/9/example-9-1.cpp
        기말/9/example-9-2.cpp
        기말/9/example-9-3.cpp
        과제/6/main.cpp
        기말/9/example-9-4.cpp
        기말/9/example-9-5.cpp
        기말/9/example-dynamic-binding.cpp
        기말/9/Shape.cpp
        기말/9/Shape.h
        기말/9/Circle.cpp
        기말/9/Circle.h
        기말/9/Rect.cpp
        기말/9/Rect.h
        기말/9/Line.cpp
        기말/9/Line.h
        기말/9/example-9-6.cpp
        기말/9/example-9-7.cpp
        기말/10/example-10-1.cpp
        기말/10/example-10-3.cpp
        기말/10/example-10-5.cpp
        기말/10/book-525-1.cpp
        기말/10/example-10-6.cpp
        기말/10/example-10-7.cpp
        기말/10/example-10-8.cpp
        기말/10/example-10-9.cpp
        기말/10/example-10-10.cpp
        기말/10/example-10-11.cpp
        기말/10/example-10-12.cpp
        기말/10/example-10-13.cpp
        수시/upcasting_downcasting.cpp
        수시/overriding.cpp
        수시/abstract_class.cpp
        과제/9/main.cpp
        기말/13/example-13-7.cpp
        기말/13/MyStack.h
        기말/13/MyStack.cpp)

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
add_executable(example-5-9 중간/5/example-5-9.cpp)
add_executable(book-274-11 중간/5/book-274-11.cpp)
add_executable(example-6-2 중간/6/example-6-2.cpp)
add_executable(example-6-5 중간/6/example-6-5.cpp)
add_executable(example-6-9 중간/6/example-6-9.cpp)
add_executable(book-313-1 중간/6/book-313-1.cpp)
add_executable(example-6-3 중간/6/example-6-3.cpp)
add_executable(example-static 중간/6/example-static.cpp)
add_executable(example-6-10 중간/6/example-6-10.cpp)
add_executable(example-6-11 중간/6/example-6-11.cpp)
add_executable(book-314-4 중간/6/book-314-4.cpp)
add_executable(example-7-1 중간/7/example-7-1.cpp)
add_executable(example-7-2 중간/7/example-7-2.cpp)
add_executable(example-7-4 중간/7/example-7-4.cpp)
add_executable(example-7-5 중간/7/example-7-5.cpp)
add_executable(example-7-6 중간/7/example-7-6.cpp)
add_executable(example-7-7 중간/7/example-7-7.cpp)
add_executable(example-7-11 중간/7/example-7-11.cpp)
add_executable(example-7-13 중간/7/example-7-13.cpp)
add_executable(example-7-14 중간/7/example-7-14.cpp)
add_executable(test test.cpp)
add_executable(example-8-3 기말/8/example-8-3.cpp)
add_executable(example-8-7 기말/8/example-8-7.cpp)
add_executable(example-9-1 기말/9/example-9-1.cpp)
add_executable(example-9-2 기말/9/example-9-2.cpp)
add_executable(example-9-3 기말/9/example-9-3.cpp)
add_executable(main 과제/6/main.cpp 과제/6/Account.cpp 과제/6/Account.h 과제/6/ATMachine.cpp 과제/6/ATMachine.h 과제/6/CustomerSvc.cpp 과제/6/CustomerSvc.h 과제/6/Statistics.cpp 과제/6/Statistics.h)
add_executable(example-9-4 기말/9/example-9-4.cpp)
add_executable(example-9-5 기말/9/example-9-5.cpp)
add_executable(example-dynamic-binding 기말/9/example-dynamic-binding.cpp 기말/9/Shape.cpp 기말/9/Shape.h 기말/9/Circle.cpp 기말/9/Circle.h 기말/9/Rect.cpp 기말/9/Rect.h 기말/9/Line.cpp 기말/9/Line.h)
add_executable(example-9-6 기말/9/example-9-6.cpp)
add_executable(example-9-7 기말/9/example-9-7.cpp)
add_executable(example-10-1 기말/10/example-10-1.cpp)
add_executable(example-10-3 기말/10/example-10-3.cpp)
add_executable(example-10-5 기말/10/example-10-5.cpp)
add_executable(book-525-1 기말/10/book-525-1.cpp)
add_executable(example-10-6 기말/10/example-10-6.cpp)
add_executable(example-10-7 기말/10/example-10-7.cpp)
add_executable(example-10-8 기말/10/example-10-8.cpp)
add_executable(example-10-9 기말/10/example-10-9.cpp)
add_executable(example-10-10 기말/10/example-10-10.cpp)
add_executable(example-10-11 기말/10/example-10-11.cpp)
add_executable(example-10-12 기말/10/example-10-12.cpp)
add_executable(example-10-13 기말/10/example-10-13.cpp)
add_executable(upcasting_downcasting 수시/upcasting_downcasting.cpp)
add_executable(example-10-14 기말/10/example-10-14.cpp)
add_executable(example-10-18 기말/10/example-10-18.cpp)
add_executable(example-10-19 기말/10/example-10-19.cpp)
add_executable(example-10-20 기말/10/example-10-20.cpp)
add_executable(example-11-2 기말/11/example-11-2.cpp)
add_executable(example-11-3 기말/11/example-11-3.cpp)
add_executable(main-9 과제/9/main.cpp
        과제/9/TicketBox.cpp
        과제/9/TicketBox.h
        과제/9/Screen.cpp
        과제/9/Screen.h
        과제/9/Ticket.h
        과제/9/Statistics.cpp
        과제/9/Statistics.h
        과제/9/Pay.h
        과제/9/Pay.cpp
)
add_executable(book-example-583-8 기말/11/book-example-583-8.cpp)
add_executable(book-example-585-10 기말/11/book-example-585-10.cpp)
add_executable(example-13-4 기말/13/example-13-4.cpp)
add_executable(example-13-5 기말/13/example-13-5.cpp)
add_executable(example-13-6 기말/13/example-13-6.cpp)