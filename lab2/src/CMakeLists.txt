add_executable(automata main.cpp)
  
add_subdirectory(inc)

target_link_libraries(automata
  PRIVATE
    inc
  )