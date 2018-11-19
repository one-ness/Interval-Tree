cmake_minimum_required(VERSION 3.10)
project(IntervalTree)

set(CMAKE_CXX_STANDARD 11)

add_executable(IntervalTree main.cpp Interval.cpp IntervalTree.cpp)