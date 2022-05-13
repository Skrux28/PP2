cmake_minimum_required(VERSION 3.20)
project(PP2)

set(CMAKE_C_STANDARD 99)

include_directories(SDL)

add_executable(PP2 main.c game.c interface.c initialGame.c game.h utility.h utility.c)

target_link_libraries(PP2 mingw32 SDL2main SDL2)
