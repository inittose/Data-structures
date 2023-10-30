add_library(inc "")

target_sources(inc
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Stack.cpp
    ${CMAKE_CURRENT_LIST_DIR}/RingBuffer.cpp
    ${CMAKE_CURRENT_LIST_DIR}/StackItem.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Menu.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Stack.h
    ${CMAKE_CURRENT_LIST_DIR}/RingBuffer.h
    ${CMAKE_CURRENT_LIST_DIR}/StackItem.h
    ${CMAKE_CURRENT_LIST_DIR}/Menu.h
  )
target_include_directories(inc
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )