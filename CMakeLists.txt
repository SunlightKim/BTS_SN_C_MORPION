cmake_minimum_required(VERSION 3.23)
project(C_MORPION C)

set(CMAKE_C_STANDARD 23)

add_executable(C_MORPION main.c func/game.c inc/game.h)
