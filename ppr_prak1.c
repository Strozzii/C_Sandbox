//
// Created by stroz on 21.10.2023.
//
#include "ppr_prak1.h"
#include <stdbool.h>
#include <stdio.h>

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

int ulam_multiples(int limit, int number)
{
	if (number == 1)
	{
		return limit;
	}
	else if (number < 1 || number > limit)
	{
		return -1;
	}

	int output = -1;

	for (int index = 1; index < limit - number + 2; index++)
	{
		int count = 1;
		bool isTwin = true;
		for (int i = index; (i < index + number - 1) && isTwin; i++)
		{
			int v1 = ulam_max(i);
			int v2 = ulam_max(i + 1);
			isTwin = (v1 == v2);
			if (isTwin)
			{
				count++;
			}
			if (count == number)
			{
				output = index;
			}
		}
	}

	return output;
}

void ulam_test(int a0)
{
	if (a0 == 1)
	{
		printf("%d\n", 1);
		printf("Folge ist terminiert!\n");
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
