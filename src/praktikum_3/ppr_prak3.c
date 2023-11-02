//
// Created by de56008 on 02.11.2023.
//

#include "ppr_prak3.h"

char generation[ALL_ROWS][ALL_ROWS];

void print_generation(void)
{
	char vert_limiter[ALL_COLS * 4 + 1] = {'+'};
	int counter = 0;
	for (int i = 1; i < (ALL_COLS * 4 + 1); i++)
	{
		if (counter < 3)
		{
			vert_limiter[i] = '-';
			counter++;
		}
		else
		{
			vert_limiter[i] = '+';
			counter = 0;
		}
	}

	char horiz_limiter[ALL_COLS * 4 + 1] = {'|'};
	int counter2 = 0;
	for (int i = 1; i < (ALL_COLS * 4 + 1); i++)
	{
		if (counter2 < 3)
		{
			horiz_limiter[i] = ' ';
			counter2++;
		}
		else
		{
			horiz_limiter[i] = '|';
			counter2 = 0;
		}
	}

	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s\n", vert_limiter);
	printf("%s\n", horiz_limiter);
	printf("%s", vert_limiter);




}