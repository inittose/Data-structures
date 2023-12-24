cmake_minimum_required(VERSION 3.5)

project(lab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab3 main.cpp
    stack.h stack.cpp
    ringbuffer.h ringbuffer.cpp
    queuestack.h queuestack.cpp
    stackitem.h stackitem.cpp
    queuering.h queuering.cpp
    menu.cpp menu.h main.cpp queuering.cpp queuering.h ringbuffer.cpp ringbuffer.h stack.cpp stack.h stackitem.cpp stackitem.h
)

include(GNUInstallDirs)
install(TARGETS lab3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
