cmake_minimum_required(VERSION 3.5)
project(dining_philosophers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -pthread")

set(SOURCE_FILES main.cpp chopstick.cpp chopstick.h philosopher.cpp philosopher.h)
add_executable(dining_philosophers ${SOURCE_FILES})