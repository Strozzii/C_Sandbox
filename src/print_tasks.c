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
	double test_1[MAX_SIZE][MAX_SIZE] = {{ 5.0 }};

	double test_2[MAX_SIZE][MAX_SIZE] = {{ 4.0, 1.0 },
										 { 8.0, 5.0 }};

	double test_3[MAX_SIZE][MAX_SIZE] = {{ 2.0, 6.0, 3.0 },
										 { 0.0, 7.0, 1.0 },
										 { 9.0, 4.0, 8.0 }};

	double test_4[MAX_SIZE][MAX_SIZE] = {{ 5.0, 2.0, 1.0, 9.0 },
										 { 0.0, 6.0, 3.0, 7.0 },
										 { 4.0, 8.0, 0.0, 1.0 },
										 { 2.0, 3.0, 7.0, 5.0 }};

	double test_5[MAX_SIZE][MAX_SIZE] = {{ 8.0, 1.0, 7.0, 2.0, 0.0 },
										 { 5.0, 4.0, 3.0, 6.0, 9.0 },
										 { 2.0, 7.0, 0.0, 8.0, 1.0 },
										 { 3.0, 5.0, 9.0, 6.0, 4.0 },
										 { 1.0, 2.0, 7.0, 0.0, 8.0 }};

	double test_6[MAX_SIZE][MAX_SIZE] = {{ 3.0, 7.0, 1.0, 8.0, 2.0, 0.0 },
										 { 6.0, 9.0, 5.0, 4.0, 3.0, 1.0 },
										 { 2.0, 0.0, 8.0, 7.0, 6.0, 5.0 },
										 { 4.0, 3.0, 2.0, 9.0, 8.0, 0.0 },
										 { 7.0, 1.0, 6.0, 5.0, 4.0, 2.0 },
										 { 5.0, 2.0, 0.0, 1.0, 9.0, 7.0 }};

	double test_7[MAX_SIZE][MAX_SIZE] = {{ 4.0, 9.0, 0.0, 1.0, 5.0, 2.0, 8.0 },
										 { 6.0, 3.0, 8.0, 7.0, 0.0, 1.0, 4.0 },
										 { 7.0, 5.0, 2.0, 9.0, 6.0, 3.0, 1.0 },
										 { 2.0, 8.0, 7.0, 1.0, 4.0, 0.0, 6.0 },
										 { 3.0, 1.0, 4.0, 6.0, 2.0, 7.0, 9.0 },
										 { 0.0, 4.0, 5.0, 3.0, 1.0, 9.0, 8.0 },
										 { 9.0, 6.0, 2.0, 8.0, 7.0, 5.0, 0.0 }};

	double test_8[MAX_SIZE][MAX_SIZE] = {{ 7.0, 4.0, 2.0, 0.0, 8.0, 9.0, 1.0, 6.0 },
										 { 3.0, 5.0, 1.0, 7.0, 6.0, 4.0, 8.0, 0.0 },
										 { 9.0, 1.0, 0.0, 3.0, 5.0, 7.0, 2.0, 4.0 },
										 { 6.0, 8.0, 9.0, 2.0, 1.0, 0.0, 4.0, 3.0 },
										 { 2.0, 7.0, 4.0, 6.0, 9.0, 8.0, 3.0, 1.0 },
										 { 0.0, 3.0, 7.0, 5.0, 4.0, 2.0, 6.0, 9.0 },
										 { 1.0, 6.0, 5.0, 4.0, 0.0, 3.0, 7.0, 8.0 },
										 { 4.0, 2.0, 8.0, 1.0, 7.0, 6.0, 9.0, 5.0 }};

	double test_9[MAX_SIZE][MAX_SIZE] = {{ 5.0, 3.0, 1.0, 8.0, 4.0, 7.0, 2.0, 0.0, 6.0 },
										 { 7.0, 6.0, 8.0, 9.0, 0.0, 5.0, 4.0, 3.0, 1.0 },
										 { 2.0, 9.0, 4.0, 1.0, 8.0, 3.0, 0.0, 7.0, 5.0 },
										 { 6.0, 0.0, 3.0, 7.0, 5.0, 1.0, 9.0, 4.0, 2.0 },
										 { 4.0, 2.0, 5.0, 0.0, 6.0, 9.0, 8.0, 1.0, 3.0 },
										 { 1.0, 7.0, 0.0, 5.0, 2.0, 4.0, 3.0, 9.0, 8.0 },
										 { 3.0, 1.0, 7.0, 4.0, 9.0, 8.0, 5.0, 2.0, 0.0 },
										 { 8.0, 4.0, 6.0, 2.0, 3.0, 0.0, 1.0, 5.0, 9.0 },
										 { 9.0, 5.0, 2.0, 3.0, 7.0, 6.0, 7.0, 8.0, 4.0 }};

	double test_10[MAX_SIZE][MAX_SIZE] = {{ 8.0, 4.0, 7.0, 5.0, 2.0, 3.0, 0.0, 9.0, 6.0, 1.0 },
										  { 0.0, 5.0, 6.0, 3.0, 9.0, 1.0, 4.0, 8.0, 7.0, 2.0 },
										  { 2.0, 1.0, 3.0, 7.0, 8.0, 6.0, 0.0, 4.0, 5.0, 9.0 },
										  { 9.0, 7.0, 8.0, 0.0, 4.0, 2.0, 5.0, 6.0, 1.0, 3.0 },
										  { 6.0, 3.0, 5.0, 4.0, 1.0, 9.0, 7.0, 2.0, 8.0, 0.0 },
										  { 1.0, 2.0, 4.0, 8.0, 3.0, 5.0, 9.0, 7.0, 0.0, 6.0 },
										  { 7.0, 0.0, 1.0, 2.0, 6.0, 8.0, 3.0, 5.0, 9.0, 4.0 },
										  { 5.0, 6.0, 9.0, 1.0, 7.0, 0.0, 2.0, 3.0, 4.0, 8.0 },
										  { 3.0, 8.0, 0.0, 6.0, 5.0, 4.0, 8.0, 1.0, 2.0, 7.0 },
										  { 4.0, 9.0, 2.0, 9.0, 0.0, 7.0, 6.0, 0.0, 3.0, 5.0 }};

	if (a)
	{
		print_matrix(test_1, 1);
		print_matrix(test_2, 2);
		print_matrix(test_3, 3);
		print_matrix(test_4, 4);
		print_matrix(test_5, 5);
		print_matrix(test_6, 6);
		print_matrix(test_7, 7);
		print_matrix(test_8, 8);
		print_matrix(test_9, 9);
		print_matrix(test_10, 10);
	}

	if (b)
	{
		printf("%.1f\n", get_determinant(test_1, 1));
		printf("%.1f\n", get_determinant(test_2, 2));
		printf("%.1f\n", get_determinant(test_3, 3));
		printf("%.1f\n", get_determinant(test_4, 4));
		printf("%.1f\n", get_determinant(test_5, 5));
		printf("%.1f\n", get_determinant(test_6, 6));
		printf("%.1f\n", get_determinant(test_7, 7));
		printf("%.1f\n", get_determinant(test_8, 8));
		printf("%.1f\n", get_determinant(test_9, 9));
		printf("%.1f\n", get_determinant(test_10, 10));
	}

}

void prak3(bool test, bool blinker, bool glider, bool octagon)
{
	if(blinker)
	{
		set_generation_from_string("0000000000 0000000000 0000000000 0010000000 0010000000 0010000000 0000000000 0000000000 0000000000 0000000000");
		game_of_life(10);
	}
	if(glider)
	{
		set_generation_from_string("0100000000 0010000000 1110000000 0000000000 0000000000 0000000000 0000000000 0000000000 0000000000 0000000000");
		game_of_life(50);
	}
	if(octagon)
	{
		set_generation_from_string("0001100000 0010010000 0100001000 1000000100 1000000100 0100001000 0010010000 0001100000 0000000000 0000000000");
		game_of_life(50);
	}

}