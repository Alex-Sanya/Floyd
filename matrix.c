#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrix.h"
#include "utl.h"

//размер матрицы
void size_of_matrix(int* vertices)
{
	printf("Enter the number of vertices of the graph: ");
	check_enter(vertices);
	while (*vertices < 2)
		{
			printf("Enter a number greater than 1: ");
			check_enter(vertices);
		}
}

//вывод на печать матрицы
void print_matrix(int** Graph, int vertices)
{
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			if (Graph[i][j] == _CRT_INT_MAX / 2)//аналог бесконечности. Максимальное знаковое int'овое число
				Graph[i][j] = -1;
			if (Graph[i][j] < 0)
				printf("%d ", Graph[i][j]);
			else
				printf(" %d ", Graph[i][j]);
		}
		printf("\n");
	}
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
			check_enter(Graph[i] + j);
		}
	printf("Your adjacency matrix:\n");
	print_matrix(Graph, vertices);
}