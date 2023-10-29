cmake_minimum_required(VERSION 3.10)

project(List)

set(SOURCE_LIB List.cpp ListItem.cpp Menu.cpp)

add_library(List STATIC ${SOURCE_LIB})