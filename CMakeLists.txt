cmake_minimum_required (VERSION 3.7)

file(GLOB SOURCE ./*.cpp)

add_executable(SFML_TEST ${SOURCE})
target_link_libraries(SFML_TEST -lsfml-graphics -lsfml-window -lsfml-system)