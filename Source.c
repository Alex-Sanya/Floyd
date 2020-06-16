#define _CRT_SECURE_NO_WARNINGS// 4 0 1 3 -1 -1 0 1 -1 -1 -1 0 -1 1 -1 -1 0
#include <stdio.h>
#include <malloc.h>

//проверка на целочисленность ввода
void check_int(int* x)
{
	int check;
	while (1)
	{
		check = scanf("%d", x);
		if (check < 1)
		{
			while (getchar() != '\n');
			printf("Wrong input!\n");
			continue;
		}
		if (*x <= 0)
		{
			while (getchar() != '\n');
			printf("Enter a positive number!\n");
			continue;
		}
		return;
	}
}

//размер матрицы
void size_of_matrix(int* vertices)
{
	printf("Enter the number of vertices of the graph: ");
	check_int(vertices);
	if (*vertices == 1)
		do
		{
			printf("Enter a number greater than 1: ");
			check_int(vertices);
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
			printf("From %d to %d: ", i+1, j+1);
			scanf("%d", Graph[i] + j);
		}
	printf("Your adjacency matrix:\n");
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			printf("%d ", Graph[i][j]);
			if (Graph[i][j] <0 )
				Graph[i][j] = _CRT_INT_MAX/2;
		}
		printf("\n");
	}
}

//алгоритм Флойда
void floyd(int **Graph, int vertices)
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

void main()
{
	int vertices = 1, ** Graph;
	size_of_matrix(&vertices);
	Graph = malloc(vertices * sizeof(int));
	for (int i = 0; i < vertices; i++)
		Graph[i] = malloc(sizeof(int) * vertices);
	create_matrix(Graph, vertices);
	floyd(Graph, vertices);
}