#include "print_tasks.h"

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

void prak2(bool a, bool b)
{

	double test_1[10][10] = {{ 1 }};

	double test_2[10][10] = {{ 0, 1 },
							 { 1, 0 }};

	double test_3[10][10] = {{ 0, 1, 2 },
							 { 3, 2, 1 },
							 { 1, 1, 0 }};
	if (a)
	{
		print_matrix(test_1, 1);
		print_matrix(test_2, 2);
		print_matrix(test_3, 3);
	}

	if (b)
	{
		printf("%.1f\n", get_determinant(test_1, 1));
		printf("%.1f\n", get_determinant(test_2, 2));
		printf("%.1f\n", get_determinant(test_3, 3));
	}

}