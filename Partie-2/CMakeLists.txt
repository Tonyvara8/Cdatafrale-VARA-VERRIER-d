cmake_minimum_required(VERSION 3.27)
project(Projet_Part2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_Part2 main.c
        cdataframe.c
        cdataframe.h
        column.c
        column.h)
