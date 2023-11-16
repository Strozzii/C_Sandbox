cmake_minimum_required(VERSION 3.23.2)
project(Prozedurale_Programmierung C)

set(CMAKE_C_STANDARD 11)

add_executable(PPR main.c
        src/print_tasks.c
        src/print_tasks.h
        src/praktikum_1/ppr_prak1.c
        src/praktikum_2/ppr_prak2.c
        src/praktikum_2/ppr_prak2.h
        src/praktikum_3/ppr_prak3.h
        src/praktikum_3/ppr_prak3.c src/praktikum_4/huffman_common.c src/praktikum_4/huffman_common.h src/praktikum_4/io.c src/praktikum_4/io.h src/praktikum_4/huffman.c src/praktikum_4/huffman.h src/praktikum_4/main.c src/praktikum_4/main.h)
