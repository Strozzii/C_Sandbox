/**
 * @file
 * In diesem Modul werden die Aufgaben zu Matrizen und Determinanten umgesetzt. Dieses Blatt umfasst zwei Aufgaben.
 *
 * @author Dennis Stroz
 * @date 2023-10-28
 */
#ifndef PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK2_H
#define PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK2_H
#define MAX_SIZE 10  /* Maximale Größe der quadratischen Matrizen */

#include <stdio.h>

#endif //PROZEDURALE_PROGRAMMIERUNG_PPR_PRAK2_H

/**
 * Diese Funktion gibt in der Konsole die Werte einer n x n - Matrix aus.
 *
 * @param matrix: Auszugebene Matrix.
 * @param size: Größe n der n x n - Matrix.
 */
void print_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size);

/**
 * Diese Funktion berechnet die Determinante einer n x n - Matrix mithilfe des Laplaceschen Entwicklungssatz.
 *
 * @param matrix: n x n - Matrix zu der die Determinante berechnet werden soll.
 * @param size: Größe n der n x n - Matrix.
 *
 * @return Gibt die Determinante zurück. Bei unsinnigen Eingaben wird 0.0 zurückgegeben und es wird eine Fehlermeldung
 * in der Konsole ausgegeben.
 */
double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size);


