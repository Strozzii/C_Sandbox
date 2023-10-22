//
// Created by stroz on 22.10.2023.
//

#include "print_tasks.h"
#include "praktikum_1/ppr_prak1.h"

void prak1(bool a, bool b, bool c)
{
	/* Aufgabe 1 */
	if (a)
	{
		printf("\nAufgabe: ulam_max\n_________\n");
		printf("%d\n", ulam_max(5));
		printf("%d\n", ulam_max(7));
		printf("%d\n", ulam_max(0));
		printf("%d\n", ulam_max(2147483647));
	}

	/* Aufgabe 2 */
	if (b)
	{
		printf("\nAufgabe: ulam_twins\n_________\n");
		printf("%d\n", ulam_twins(5));
		printf("%d\n", ulam_twins(6));
	}

	/* Aufgabe 3 */
	if (c)
	{
		printf("\nAufgabe: ulam_multiples\n_________\n");
		printf("%d\n", ulam_multiples(10, 2));
		printf("%d\n", ulam_multiples(1000, 3));
		printf("%d\n", ulam_multiples(108, 3));
		printf("%d\n", ulam_multiples(391, 6));
		printf("%d\n", ulam_multiples(115, 2));
	}
}