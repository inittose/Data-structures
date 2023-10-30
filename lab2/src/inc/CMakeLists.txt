add_library(inc "")

target_sources(inc
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/List.cpp
    ${CMAKE_CURRENT_LIST_DIR}/ListItem.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Menu.cpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/List.h
  ${CMAKE_CURRENT_LIST_DIR}/ListItem.h
  ${CMAKE_CURRENT_LIST_DIR}/Menu.h
  )
target_include_directories(inc
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )