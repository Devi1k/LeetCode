cmake_minimum_required(VERSION 3.21)
project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(exam head.h WrittenExamination/main.cpp)
add_executable(LeetCode head.h 6DynamicProgramming/72.cpp)
