cmake_minimum_required(VERSION 3.5)

project(lab5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab5 main.cpp
    binarytreenode.h binarytreenode.cpp
    binarytree.h binarytree.cpp
    queue.h queue.cpp
    queuenode.h queuenode.cpp)

include(GNUInstallDirs)
install(TARGETS lab5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
