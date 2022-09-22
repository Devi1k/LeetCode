cmake_minimum_required(VERSION 3.21)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(exam head.h WrittenExamination/main.cpp)
add_executable(LeetCode head.h 10DataStructure/225.cpp)
