//
// Created by de56008 on 02.11.2023.
//
#include <stdbool.h>
#include <stdio.h>

#ifndef PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK3_H
#define PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK3_H

#define ALL_ROWS 10
#define ALL_COLS 10

#endif //PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK3_H


void print_generation(void);

void set_generation_from_string(char string[]);

void get_generation_as_string(char string[]);

bool set_next_generation(void);

void game_of_life(int max_generations);
