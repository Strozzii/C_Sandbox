/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// 						   IMPORTS & DEKLARATIONEN 						     ////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ppr_prak3.h"

/**
 * Definition des Spielfelds mithilfe von Spalten- und Zeilenanzahl.
 */
#define ALL_ROWS 10
#define ALL_COLS 10

/**
 * Anzahl Felder des Spielfelds.
 */
#define GRID_SIZE (ALL_ROWS * ALL_COLS)

/**
 * Berechnet aus der Spielfeldgröße den benötigten Speicher in aufgerundeten ganzen Bytes.
 */
#define ALL_BYTES ((GRID_SIZE + 7) / 8)

/**
 * Die aktuelle Generation als 1D-Vektor mit der errechneten Größe in ALL_BYTES.
 */
unsigned char generation[ALL_BYTES];


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////// 						       FUNKTIONEN								     ////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_generation_from_string(const char string[])
{
	/*
	 * Jeweils ein Index um auf das richtige Byte im Vektor zu zeigen und ein Index um auf das entsprechende
	 * Bit im Byte zu zeigen.
	 */
	int byte_index;
	int bit_index;

	/* Setze alle Bytes in 'generation' auf 0, damit das Ergebnis durch das logische ODER verfälscht wird. */
	memset(generation, 0, ALL_BYTES);

	/*
	 * Iteriere durch den String und setze an der entsprechenden Bit-Stelle ein 'Alive-Bit', wenn das aktuelle
	 * Zeichen des Strings gleich '1' ist.
	 */
	for (int i = 0; i < GRID_SIZE; i++)
	{
		byte_index = i / 8;
		bit_index = i % 8;
		generation[byte_index] |= (string[i] == '1' ? (1 << bit_index) : 0);
	}
}

void print_generation(void)
{
	int row;            /* Zeilenindex */
	int col;            /* Spaltenindex */
	int index;          /* Index, was auf eine Zelle im Spielfeld zeigt */
	int byte_index;     /* Index des aktuellen Bytes */
	int bit_index;      /* Index des aktuellen Bits */
	char cell;          /* Speichert das entsprechende Symbol, was eine lebende oder tote Zelle darstellt */

	/* Dieser Teil printet den oberen Rand entsprechend der Spaltengröße. */
	printf("+");
	for (col = 0; col < ALL_COLS; col++)
	{
		printf("---+");
	}
	printf("\n");

	/* Ab hier wird der nötige Rest geprintet. */
	for (row = 0; row < ALL_ROWS; row++)
	{
		/* Logik um die einzelnen Zellen zu printen. */
		for (col = 0; col < ALL_COLS; col++)
		{
			index = row * ALL_COLS + col;
			byte_index = index / 8;
			bit_index = index % 8;
			cell = (generation[byte_index] & (1 << bit_index)) ? 'o' : ' ';
			printf("| %c ", cell);
		}
		printf("|\n+");

		/* Logik um die 'Zwischenwände' zu printen. */
		for (col = 0; col < ALL_COLS; col++)
		{
			printf("---+");
		}
		printf("\n");
	}
}

void get_generation_as_string(char string[])
{
	int row;            /* Zeilenindex */
	int col;            /* Spaltenindex */
	int index;          /* Index, was auf eine Zelle im Spielfeld zeigt und auf die aktuelle Position im String */
	int byte_index;     /* Index des aktuellen Bytes */
	int bit_index;      /* Index des aktuellen Bits */
	char cell;          /* Speichert das entsprechende Symbol, was eine lebende oder tote Zelle darstellt */

	/*
	 * Iteriere zeitgleich durchs Spielfeld und durch den String und setze an der aktuellen Position des Strings '1',
	 * wenn sich im Spielfeld eine 'lebende Zelle' befindet.
	 */
	for (row = 0; row < ALL_ROWS; row++)
	{
		for (col = 0; col < ALL_COLS; col++)
		{
			index = row * ALL_COLS + col;
			byte_index = index / 8;
			bit_index = index % 8;
			cell = (generation[byte_index] & (1 << bit_index)) ? '1' : '0';
			string[index] = cell;
			index++;
		}
	}

	string[index] = '\0'; /* Nullterminierung der Zeichenkette */
}

bool set_next_generation(void)
{
	int row;                    /* Zeilenindex */
	int col;                    /* Spaltenindex */
	int index;                  /* Index, was auf eine Zelle im Spielfeld zeigt */
	int byte_index;             /* Index des aktuellen Bytes */
	int bit_index;              /* Index des aktuellen Bits */
	int live_neighbors;         /* Speichert die Anzahl der Nachbarn einer Zelle */
	bool generation_changed;    /* Zustand, ob Generation sich mindestens einmal geändert hat */

	unsigned char next_generation[ALL_BYTES];    /* Speicher der nächsten Generation */

	/* Kopieren der aktuellen Generation, um die nächste Generation zu berechnen. */
	memcpy(next_generation, generation, sizeof(generation));

	/* Anfangszustand False, falls sich die Generation nicht ändert. */
	generation_changed = false;

	/*
	 * Iteriere durch gesamte Spielfeld und zähle die lebendigen Nachbarn jeder Zelle und wende die Regeln
	 * von 'Game of Life' an.
	 *
	 * Lebendige Zellen:
	 * 			- Überleben, wenn sie 2 oder 3 Nachbarn besitzen
	 * 			- Sterben, bei Unterbevölkerung (< 2 Nachbarn) oder überbevölkerung (> 3 Nachbarn)
	 *
	 * Tote Zellen:
	 * 			- Wiederbelebung, wenn genau 3 Nachbarn vorhanden sind
	 */
	for (row = 0; row < ALL_ROWS; row++)
	{
		for (col = 0; col < ALL_COLS; col++)
		{
			index = row * ALL_COLS + col;
			byte_index = index / 8;
			bit_index = index % 8;

			/* Zählen der lebenden Nachbarn */
			live_neighbors = get_live_neighbors(row, col);

			/*
			 * Anwenden der Regeln des Game of Life.
			 * Prüfe, ob Zelle lebendig oder tot ist.
			 */

			/* Zelle lebt */
			if (generation[byte_index] & (1 << bit_index))
			{
				if (live_neighbors < 2 || live_neighbors > 3)
				{
					/* Zelle stirbt wegen Unter- oder Überbevölkerung */
					next_generation[byte_index] &= ~(1 << bit_index);
					generation_changed = true;
				}
			}
				/* Zelle tot */
			else
			{
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
	int generation_number;      /* Aktuelle Generation */
	bool generation_changed;    /* Zustand, ob sich Generation geändert hat. Bewirkt Schleifenabbruch. */

	for (generation_number = 0; generation_number < max_generations; generation_number++)
	{
		/* Ausgabe der aktuellen Generation mit ihrer Nummer */
		printf("Generation %d:\n", generation_number);
		print_generation();

		/* Berechnen der nächsten Generation */
		generation_changed = set_next_generation();

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
	/* Laufindex, um auf einen Nachbarn zu zeigen */
	int i;
	int j;

	/* Speichert, die Anzahl lebender Nachbarn einer Zelle */
	int live_neighbors;

	/* Zeile und Spalte des jeweiligen Nachbarn im Spielfeld */
	int neighbor_row;
	int neighbor_col;

	/* Indizes des jeweiligen Nachbarn im Vektor */
	int neighbor_index;
	int neighbor_byte_index;
	int neighbor_bit_index;

	live_neighbors = 0;

	/*
	 * Iteriere um das aktuelle Feld und fange beim Nachbarn obenlinks im Feld an bis zum Nachbarn unten rechts.
	 */
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			/* Überspringe das aktuelle Feld */
			if (i == 0 && j == 0)
				continue;

			neighbor_row = row + i;
			neighbor_col = col + j;

			/* Prüfe, ob sich der Nachbar noch im Spielfeld befindet. */
			if (neighbor_row >= 0 && neighbor_row < ALL_ROWS && neighbor_col >= 0 && neighbor_col < ALL_COLS)
			{
				neighbor_index = neighbor_row * ALL_COLS + neighbor_col;
				neighbor_byte_index = neighbor_index / 8;
				neighbor_bit_index = neighbor_index % 8;

				/* Inkrementiere den Zähler, wenn sich an der aktuellen Position ein lebendiger Nachbar befindet. */
				if (generation[neighbor_byte_index] & (1 << neighbor_bit_index))
					live_neighbors++;
			}
		}
	}

	return live_neighbors;
}


