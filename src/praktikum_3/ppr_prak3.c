//
// Created by de56008 on 02.11.2023.
//

#include "ppr_prak3.h"

char generation[ALL_ROWS][ALL_COLS];  /* Globale Variable zur Darstellung der Generation */

void print_generation(void)
{
	for (int row = 0; row < ALL_ROWS; row++)
	{
		printf("+");
		for (int col = 0; col < ALL_COLS; col++)
		{
			printf("---+");
		}
		printf("\n");

		printf("|");
		for (int col = 0; col < ALL_COLS; col++)
		{
			/* Prüfe, ob an Stelle der aktuellen Stelle eine 1 ist */
			if (generation[row][col])
			{
				printf(" o |");
			}
			else
			{
				printf("   |");
			}
		}
		printf("\n");
	}

	printf("+");
	for (int col = 0; col < ALL_COLS; col++)
	{
		printf("---+");
	}
	printf("\n");
}

void set_generation_from_string(char string[])
{
	int row = 0;
	int col = 0;

	for (int i = 0; i < ALL_ROWS * ALL_COLS; i++)
	{
		char c = string[i];
		if (c == '0' || c == '1')
		{
			generation[row][col] = c - '0'; /* Konvertiere Zeichen '0' oder '1' in Zahl 0 oder 1 */
			col++;
			if (col == ALL_COLS)
			{
				col = 0;
				row++;
			}
		}
	}
}

void get_generation_as_string(char string[])
{
	int index = 0;

	for (int row = 0; row < ALL_ROWS; row++)
	{
		for (int col = 0; col < ALL_COLS; col++)
		{
			string[index] = generation[row][col] + '0'; /* Konvertiere Zahl 0 oder 1 in Zeichen '0' oder '1' */
			index++;
		}
	}
}

bool set_next_generation(void)
{
	bool generation_changed = false;

	unsigned char temp_generation[ALL_ROWS][ALL_COLS]; /* Kopie der aktuellen Generation */

	for (int row = 0; row < ALL_ROWS; row++)
	{
		for (int col = 0; col < ALL_COLS; col++)
		{
			temp_generation[row][col] = generation[row][col]; /* Kopie erstellen */
		}
	}

	for (int row = 0; row < ALL_ROWS; row++)
	{
		for (int col = 0; col < ALL_COLS; col++)
		{
			int neighbors = 0;

			/* Anzahl der lebenden Nachbarn ermitteln */
			for (int dr = -1; dr <= 1; dr++)
			{
				for (int dc = -1; dc <= 1; dc++)
				{
					if (dr == 0 && dc == 0) continue; /* Die Zelle selbst nicht zählen */
					int r = row + dr;
					int c = col + dc;
					if (r >= 0 && r < ALL_ROWS && c >= 0 && c < ALL_COLS)
					{
						neighbors += temp_generation[r][c];
					}
				}
			}

			/* Überlebens- und Geburtsregeln anwenden */
			if (temp_generation[row][col] == 1)
			{
				if (neighbors < 2 || neighbors > 3)
				{
					generation[row][col] = 0; // Zelle stirbt
					if (generation_changed == false)
					{
						generation_changed = true;
					}
				}
			}
			else
			{
				if (neighbors == 3)
				{
					generation[row][col] = 1; /* Zelle wird geboren */
					if (generation_changed == false)
					{
						generation_changed = true;
					}
				}
			}
		}
	}

	return generation_changed;
}

void game_of_life(int max_generations)
{
	for (int generation_num = 0; generation_num <= max_generations; generation_num++)
	{
		printf("Generation %d:\n", generation_num);
		print_generation();

		bool changed = set_next_generation();

		if (!changed)
		{
			printf("Generation stabil, das Spiel endet.\n");
			break;
		}
	}
}
