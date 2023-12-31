/**
 * @file
 * In diesem Modul werden die Aufgaben zu "Conway's Game of Life" umgesetzt.
 *
 * @author Dennis Stroz
 * @date 2023-11-04
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK3_H
#define PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK3_H

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
void set_generation_from_string(const char string[]);

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


/**
 * Diese Hilfsfunktion zählt die lebenden Nachbarn eines Bits.
 *
 * @param row: Zeile des Bits
 * @param col: Spalte des Bits
 *
 * @return Anzahl der lebenden Nachbarn die sich ringsrum des Bits befinden.
 */
int get_live_neighbors(int row, int col);
