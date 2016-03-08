cmake_minimum_required(VERSION 3.3)
project(CSCE_3600_Minor_Assignment_5)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -lpthread -Wall")

set(SOURCE_FILES minor5.c)

include_directories(.)

add_executable(minor5 ${SOURCE_FILES})