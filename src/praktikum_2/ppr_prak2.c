#include "ppr_prak2.h"

void print_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
	/* Iteriere durch alle Zeilen der Matrix */
	for (int i = 0; i < size; i++)
	{
		/* Iteriere durch alle Spalten der Matrix */
		for (int j = 0; j < size; j++)
		{
			printf("%.1f ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/**
 * Diese Hilfsfunktion dient dazu Untermatrizen einer Matrix zu erzeugen und handhabt das Vorzeichen für den
 * Laplaceschen Entwicklungssatz.
 *
 * @param matrix: n x n - Matrix zu der die Untermatrizen gebaut werden sollen.
 * @param size: Größe n der n x n - Matrix.
 * @param row: Zeile, an der sich die Entwicklung orientieren soll. Standardwert ist 0.
 * @param col: Spalte, die bei der Entwicklung ignoriert werden soll. Dieser Wert ist variabel um die verschiedenen
 * 			   Untermatrizen zu bauen und entscheidet das Vorzeichen.
 *
 * @return Determinante der erzeugten Untermatrizen durch indirekte Rekursion.
 */
double cofactor(double matrix[MAX_SIZE][MAX_SIZE], int size, int row, int col)
{
	double minor[MAX_SIZE][MAX_SIZE];

	/* Laufvariablen für die eingehende Matrix */
	int i;
	int j;

	/* Laufvariablen der Untermatrix */
	int minorRow = 0;
	int minorCol = 0;

	/*
	 * Durchlaufe sämtliche Werte der eingehenden Matrix und überspringe eine Iteration, wenn die Indizes den Werten
	 * von row und col entsprechen, um nur auf die entsprechenden Werte für die Untermatrix zu zeigen, die in Dieser
	 * auch gespeichert werden.
	 */
	for (i = 0; i < size; i++)
	{
		if (i == row)
			continue;

		for (j = 0; j < size; j++)
		{
			if (j == col)
				continue;

			minor[minorRow][minorCol] = matrix[i][j];
			minorCol++;
		}

		minorRow++;
		minorCol = 0;
	}

	return col % 2 == 0 ? get_determinant(minor, size - 1)
						: -get_determinant(minor, size - 1);
}

double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
	/*
	 * Die Determinante von einer n x n - Matrix kann sehr simpel berechnet werden, wenn n < 3.
	 * Die komplexe Berechnung findet statt, wenn n > 2 && n < 11.
	 * Nicht berücksichtigte Angaben werfen eine Fehlermeldung in der Konsole aus und geben 0.0 zurück.
	 */
	if (size == 1)
	{
		return matrix[0][0];
	}
	else if (size == 2)
	{
		return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	}
	else if (size > 2 && size < 11)
	{
		double det = 0;  /* Startwert der Determinante */

		/* Iteriere entlang der ersten Zeile gemäß dem Entwicklungssatz */
		for (int j = 0; j < size; j++)
		{
			/* Summenbildung mit Aufruf der Hilfsfunktion, die die Untermatrizen mit Vorzeichen liefert */
			det += matrix[0][j] * cofactor(matrix, size, 0, j);
		}
		return det;
	}
	else
	{
		printf("FEHLER!");
		return 0.0;
	}
}