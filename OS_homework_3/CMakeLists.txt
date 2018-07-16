cmake_minimum_required (VERSION 3.6)
project(OS_hw_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES Page.cpp Page.h main.cpp)

add_executable(HW3 ${SOURCE_FILES})