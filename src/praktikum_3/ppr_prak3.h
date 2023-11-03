//
// Created by de56008 on 02.11.2023.
//
#include <stdbool.h>
#include <stdio.h>

#ifndef PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK3_H
#define PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK3_H

/* Definition der Spielfeldgröße */
#define ALL_ROWS 10
#define ALL_COLS 10

#endif //PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK3_H

/**
 * Diese Funktion gibt den aktuellen Zustand der Generation in der globalen Variable "generatíon" aus.
 */
void print_generation(void);

/**
 * Diese Funktion initialisiert die globale Variable "generation" mit einer Anfangsgeneration mittels Zeichenkette.
 *
 * @param string: Zeichenkette, die die Generation beschreibt. Sie enthält nacheinander die Zeilen der Generation.
 * Eine '1' bedeutet, dass die Zelle ein Lebewesen enthält, und eine '0', dass die Zelle kein Lebewesen enthält.
 * Ein Beispiel für eine Generation wäre: "111000001000010111000100000010".
 */
void set_generation_from_string(char string[]);

/**
 * Diese Funktion liefert die aktuelle Generation als Zeichenkette zurück.
 *
 * @param string: Variable, in der die Zeichenkette abgespeichert werden soll.
 */
void get_generation_as_string(char string[]);

/**
 * Diese Funktion berechnet ausgehend von der aktuellen Generation in "generation" die nächste Generation.
 *
 * @return Liefert True zurück, wenn die nächste Generation sich von der aktuellen unterscheidet, sonst False.
 */
bool set_next_generation(void);

/**
 * Diese Funktion berechnet n-mal die nächsten Generationen und gibt Diese in der Konsole aus.
 *
 * @param max_generations: Anzahl der zu berechnenden Generationen.
 */
void game_of_life(int max_generations);
