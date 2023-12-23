cmake_minimum_required(VERSION 3.5)

project(lab4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lab4 main.cpp
    hashtableitem.h hashtableitem.cpp
    hashtable.h hashtable.cpp
    dictionary.h dictionary.cpp
    menu.h menu.cpp)

include(GNUInstallDirs)
install(TARGETS lab4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
