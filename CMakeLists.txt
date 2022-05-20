cmake_minimum_required(VERSION 3.20)
project(PP2)

set(CMAKE_C_STANDARD 99)

include_directories(SDL)

add_executable(PP2 main.c game.c game.h utility.h utility.c initial.c initial.h interface.c interface.h)

target_link_libraries(PP2 mingw32 SDL2main SDL2 SDL2_image SDL2_ttf)



