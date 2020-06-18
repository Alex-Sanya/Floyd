#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Floyd.h"

//אכדמנטעל װכמיהא
void floyd(int** Graph, int vertices)
{
	int i, j, k;
	for (k = 0; k < vertices; k++)
		for (i = 0; i < vertices; i++)
			for (j = 0; j < vertices; j++)
				if (Graph[i][j] > Graph[i][k] + Graph[k][j])
					Graph[i][j] = Graph[i][k] + Graph[k][j];
	printf("\nNew matrix with the smallest distances between vertices:\n");
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			if (Graph[i][j] == _CRT_INT_MAX / 2)
				Graph[i][j] = 0;
			printf("%d ", Graph[i][j]);
		}
		printf("\n");
	}
}