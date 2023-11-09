#include "ppr_prak3.h"


/* Konstanten zur Festlegung der Spielfeldgröße */
#define ALL_ROWS 10
#define ALL_COLS 10

#define ALL_BYTES ((ALL_ROWS * ALL_COLS + 7) / 8)

/* Globale Variable zur Speicherung der aktuellen Generation */
unsigned char generation[ALL_BYTES];

void set_generation_from_string(char string[])
{
	memset(generation, 0, ALL_BYTES);

	for (int i = 0; i < ALL_ROWS * ALL_COLS; i++)
	{
		int byte_index = i / 8;
		int bit_index = i % 8;
		generation[byte_index] |= (string[i] == '1' ? (1 << bit_index) : 0);
	}
}

void print_generation(void)
{
	printf("+");
	for (int col = 0; col < ALL_COLS; col++)
	{
		printf("---+");
	}
	printf("\n");
	for (int row = 0; row < ALL_ROWS; row++)
	{
		for (int col = 0; col < ALL_COLS; col++)
		{
			int index = row * ALL_COLS + col;
			int byte_index = index / 8;
			int bit_index = index % 8;
			char cell = (generation[byte_index] & (1 << bit_index)) ? 'o' : ' ';
			printf("| %c ", cell);
		}
		printf("|\n+");
		for (int col = 0; col < ALL_COLS; col++)
		{
			printf("---+");
		}
		printf("\n");
	}
}

void get_generation_as_string(char string[])
{

	int index = 0;

	for (int row = 0; row < ALL_ROWS; row++)
	{
		for (int col = 0; col < ALL_COLS; col++)
		{
			int byte_index = (row * ALL_COLS + col) / 8;
			int bit_index = (row * ALL_COLS + col) % 8;
			char cell = (generation[byte_index] & (1 << bit_index)) ? '1' : '0';
			string[index] = cell;
			index++;
		}
	}

	string[index] = '\0'; /* Nullterminierung der Zeichenkette */
}

bool set_next_generation(void)
{
	/* Kopieren der aktuellen Generation, um die nächste Generation zu berechnen */
	unsigned char next_generation[(ALL_ROWS * ALL_COLS + 7) / 8];
	memcpy(next_generation, generation, sizeof(generation));

	bool generation_changed = false;

	for (int row = 0; row < ALL_ROWS; row++)
	{
		for (int col = 0; col < ALL_COLS; col++)
		{
			int index = row * ALL_COLS + col;
			int byte_index = index / 8;
			int bit_index = index % 8;

			/* Zählen der lebenden Nachbarn */
			int live_neighbors = get_live_neighbors(row, col);

			/* Anwenden der Regeln des Game of Life */
			if (generation[byte_index] & (1 << bit_index))
			{
				/* Zelle ist lebendig */
				if (live_neighbors < 2 || live_neighbors > 3)
				{
					/* Zelle stirbt wegen Unter- oder Überbevölkerung */
					next_generation[byte_index] &= ~(1 << bit_index);
					generation_changed = true;
				}
			}
			else
			{
				/* Zelle ist tot */
				if (live_neighbors == 3)
				{
					/* Zelle wird belebt */
					next_generation[byte_index] |= (1 << bit_index);
					generation_changed = true;
				}
			}
		}
	}

	/* Kopieren der berechneten nächsten Generation in die globale Variable */
	memcpy(generation, next_generation, ALL_BYTES);

	return generation_changed;
}

void game_of_life(int max_generations)
{
	int generation_number = 0;

	for (; generation_number < max_generations; generation_number++)
	{
		/* Ausgabe der aktuellen Generation mit ihrer Nummer */
		printf("Generation %d:\n", generation_number);
		print_generation();

		/* Berechnen der nächsten Generation */
		bool generation_changed = set_next_generation();

		/* Wenn sich die Generation nicht mehr ändert, brich die Schleife ab */
		if (!generation_changed)
		{
			printf("Generation stoppt!\n");
			break;
		}
	}
}

int get_live_neighbors(int row, int col)
{
	int live_neighbors = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			/* Überspringe das aktuelle Feld */
			if (i == 0 && j == 0)
				continue;

			int neighbor_row = row + i;
			int neighbor_col = col + j;

			if (neighbor_row >= 0 && neighbor_row < ALL_ROWS && neighbor_col >= 0 && neighbor_col < ALL_COLS)
			{
				int neighbor_index = neighbor_row * ALL_COLS + neighbor_col;
				int neighbor_byte_index = neighbor_index / 8;
				int neighbor_bit_index = neighbor_index % 8;

				if (generation[neighbor_byte_index] & (1 << neighbor_bit_index))
					live_neighbors++;
			}
		}
	}

	return live_neighbors;
}


