#include <stdio.h>

void ulam_test(int a0);

int ulam_max(int a0);

int ulam_twins(int limit);

int ulam_multiples(int limit, int number);

int main()
{
	printf("Test der Ulam-Folge\n_________\n");

	ulam_test(5);
	ulam_test(7);

	printf("Aufgabe: ulam_max\n_________\n");

	printf("%d\n", ulam_max(5));
	printf("%d\n", ulam_max(7));
	printf("%d\n", ulam_max(0));
	printf("%d\n", ulam_max(2147483647));

	printf("Aufgabe: ulam_twins\n_________\n");

	printf("%d\n", ulam_twins(5));
	printf("%d\n", ulam_twins(6));
}

int ulam_max(int a0)
{
	int actual = a0;
	int max = a0;

	while (actual > 0)
	{
		if (actual % 2 == 0)
		{
			actual = actual / 2;
		}
		else
		{
			actual = 3 * actual + 1;
		}

		if (actual > max)
		{
			max = actual;
		}
		if (actual == 1)
		{
			return max;
		}
	}
	return -1;
}

int ulam_twins(int limit)
{
	int index = 1;
	int val1;
	int val2;
	int output = -1;

	for (; index < limit; index++)
	{
		val1 = ulam_max(index);
		val2 = ulam_max(index + 1);

		if (val1 == val2)
		{
			output = index;
		}


	}


	return output;
}

int multiples(int limit, int number)
{
	return 0;
}

void ulam_test(int a0)
{
	if (a0 == 1)
	{
		printf("%d\n", 1);
		printf("Folge ist terminiert!\n\n");
	}
	else if (a0 % 2 == 1)
	{
		printf("%d\n", a0);
		ulam_test(3 * a0 + 1);
	}
	else if (a0 % 2 == 0)
	{
		printf("%d\n", a0);
		ulam_test(a0 / 2);
	}
}