#include <stdio.h>
#include "ppr_prak1.h"

int main()
{
	printf("Test der Ulam-Folge\n_________\n");

	ulam_test(5);

	printf("\nAufgabe: ulam_max\n_________\n");

	printf("%d\n", ulam_max(5));
	printf("%d\n", ulam_max(7));
	printf("%d\n", ulam_max(0));
	printf("%d\n", ulam_max(2147483647));

	printf("\nAufgabe: ulam_twins\n_________\n");

	printf("%d\n", ulam_twins(5));
	printf("%d\n", ulam_twins(6));

	printf("\nAufgabe: ulam_multiples\n_________\n");

	printf("%d\n", ulam_multiples(10, 2));
	printf("%d\n", ulam_multiples(1000, 3));
	printf("%d\n", ulam_multiples(108, 3));
	printf("%d\n", ulam_multiples(391, 6));

}

