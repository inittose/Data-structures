cmake_minimum_required(VERSION 3.10)

project(lab2)

set(SOURCE_EXE main.cpp)

include_directories(source)

add_executable(lab2 ${SOURCE_EXE})

add_subdirectory(source)

target_link_libraries(lab2 source)	