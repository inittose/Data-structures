cmake_minimum_required(VERSION 3.5)

project(lab5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab5 "main.cpp"
    binarytreenode.h binarytreenode.cpp
    binarytree.h binarytree.cpp
    queue.h
    queuenode.h
    treapnode.h treapnode.cpp
    treap.h treap.cpp
    menu.h
    menu.cpp)

include(GNUInstallDirs)
install(TARGETS lab5
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
