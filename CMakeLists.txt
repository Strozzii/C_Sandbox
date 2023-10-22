cmake_minimum_required(VERSION 3.25)
project(Prozedurale_Programmierung C)

set(CMAKE_C_STANDARD 11)

add_executable(PPR main.c
        src/praktikum_1/ppr_prak1.c
        src/print_tasks.c
        src/print_tasks.h)
