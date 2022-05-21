cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_C_STANDARD 99)

include_directories(SDL)

add_executable(test test.c ../game.c ../game.h ../utility.h ../utility.c ../initial.c ../initial.h)

target_link_libraries(test mingw32 SDL2main SDL2 SDL2_image SDL2_ttf CUnit)



