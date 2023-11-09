cmake_minimum_required(VERSION 3.5)

project(qtlab3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(qtlab3 main.cpp
    stack.h stack.cpp
    ringbuffer.h ringbuffer.cpp
    queue.h queue.cpp
    stackitem.h stackitem.cpp
    iotool.h iotool.cpp
    queuering.h queuering.cpp
    iotool.cpp iotool.h main.cpp queue.cpp queue.h queuering.cpp queuering.h ringbuffer.cpp ringbuffer.h stack.cpp stack.h stackitem.cpp stackitem.h
)

include(GNUInstallDirs)
install(TARGETS qtlab3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
