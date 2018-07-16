cmake_minimum_required (VERSION 3.6)
project (OS_hw_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp Read.cpp Read.h Schedule.cpp Schedule.h Generater.cpp Generater.h)

add_executable(HW2 ${SOURCE_FILES})
