#include <stdio.h>

void ulam_test(int a0);

int ulam_max(int a0);

int ulam_twin(int limit);

int main()
{

	// ulam_test(5);
	// ulam_test(7);

	printf("%d\n", ulam_max(5));
	printf("%d\n", ulam_max(7));
	printf("%d\n", ulam_max(0));
	printf("%d\n", ulam_max(2147483647));
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

int

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