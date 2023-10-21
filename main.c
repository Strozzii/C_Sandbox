/**
 * @mainpage Prozedurale Programmierung - Praktikumsaufgaben
 *
 * Dieses Projekt realisiert die Aufgaben des PPR-Praktikums.
 *
 * @author Dennis Stroz
 * @date 2023-10-21
 */

#include <stdio.h>
#include "src/ppr_prak1.h"

/**
 * Entry-Point des Programms.
 *
 * @return Compilerspezifischer Rückgabewert.
 */
int main()
{
	/* Aufgabe 1 */
	printf("\nAufgabe: ulam_max\n_________\n");
	printf("%d\n", ulam_max(5));
	printf("%d\n", ulam_max(7));
	printf("%d\n", ulam_max(0));
	printf("%d\n", ulam_max(2147483647));

	/* Aufgabe 2 */
	printf("\nAufgabe: ulam_twins\n_________\n");
	printf("%d\n", ulam_twins(5));
	printf("%d\n", ulam_twins(6));

	/* Aufgabe 3 */
	printf("\nAufgabe: ulam_multiples\n_________\n");
	printf("%d\n", ulam_multiples(10, 2));
	printf("%d\n", ulam_multiples(1000, 3));
	printf("%d\n", ulam_multiples(108, 3));
	printf("%d\n", ulam_multiples(391, 6));

}

