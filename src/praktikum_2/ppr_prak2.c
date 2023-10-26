//
// Created by de56008 on 26.10.2023.
//

#include "ppr_prak2.h"

void print_matrix(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%.1f ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

double get_determinant(double matrix[MAX_SIZE][MAX_SIZE], int size)
{
	if (size == 1)
	{
		return matrix[0][0];
	}
	else if (size == 2)
	{
		return (matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]);
	}
	return -1;

}