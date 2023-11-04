/**
 * @file
 * In diesem Modul werden die Funktionen aus den einzelnen Praktikumsaufgaben geprintet.
 *
 * @author Dennis Stroz
 * @date 2023-10-22
 */
#include <stdio.h>
#include <stdbool.h>
#include "praktikum_1/ppr_prak1.h"
#include "praktikum_2/ppr_prak2.h"
#include "praktikum_3/ppr_prak3.h"

#ifndef PRINT_TASKS_H_
#define PRINT_TASKS_H_

#endif //PRINT_TASKS_H_


/**
 * Diese Funktion printet die Lösungen für die erste Praktikumsaufgabe.
 *
 * @param a: True, wenn die Aufgabe zu ulam_max geprintet werden soll.
 * @param b: True, wenn die Aufgabe zu ulam_twins geprintet werden soll.
 * @param c: True, wenn die Aufgabe zu ulam_multiples geprintet werden soll.
 */
void prak1(bool a, bool b, bool c);

/**
 * Diese Funktion printet die Lösungen für die zweite Praktikumsaufgabe.
 *
 * @param a: True, wenn die Aufgabe zum Printen der Matrizen geprintet werden soll.
 * @param b: True, wenn die Aufgabe zu Determinaten von Matrizen geprintet werden soll.
 */
void prak2(bool a, bool b);

/**
 * Die Funktion printet zur dritten Praktikumsaufgabe einige Test-Samples.
 *
 * @param test: Diagonale. Von oben links nach unten rechts.
 * @param blinker: Blinker, was sich unendlich entwickeln kann.
 * @param glider: Form, was von oben links nach unten rechts wandert.
 * @param octagon: Oktagon was sich öffnet und schliesst.
 */
void prak3(bool test, bool blinker, bool glider, bool octagon);