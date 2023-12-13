cmake_minimum_required(VERSION 3.5)

project(lab6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab6 main.cpp
    redblacktree.h redblacktree.cpp
    redblacktreenode.h redblacktreenode.cpp
    avltree.h avltree.cpp
    avltreenode.h avltreenode.cpp
    queue.h queue.cpp)

include(GNUInstallDirs)
install(TARGETS lab6
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
