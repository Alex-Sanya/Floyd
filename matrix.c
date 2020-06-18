#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrix.h"
#include "utl.h"

//размер матрицы
void size_of_matrix(int* vertices)
{
	printf("Enter the number of vertices of the graph: ");
	check_enter(vertices);
	if (*vertices == 1)
		do
		{
			printf("Enter a number greater than 1: ");
			check_enter(vertices);
		} while (*vertices == 1);
}

//создание матрицы
void create_matrix(int** Graph, int vertices)
{
	printf("Enter the length of the ribs.\n");
	printf("If there is no rib, enter '-1'.\n");
	for (int i = 0; i < vertices; i++)
		for (int j = 0; j < vertices; j++)
		{
			printf("From %d to %d: ", i + 1, j + 1);
			scanf("%d", Graph[i] + j);
		}
	printf("Your adjacency matrix:\n");
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			printf("%d ", Graph[i][j]);
			if (Graph[i][j] < 0)
				Graph[i][j] = _CRT_INT_MAX / 2;
		}
		printf("\n");
	}
}