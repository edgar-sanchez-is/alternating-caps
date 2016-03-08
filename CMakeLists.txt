cmake_minimum_required(VERSION 3.3)
project(CSCE_3600_Minor_Assignment_5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    "docs/Minor Assignment 5 Impoementing Mutex Locks.pdf"
    minor5.c)

include_directories(.)

add_executable(CSCE_3600_Minor_Assignment_5 ${SOURCE_FILES})