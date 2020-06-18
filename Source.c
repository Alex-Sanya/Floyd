#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "Floyd.h"
#include "matrix.h"
#include "utl.h"

//нахождение кратчайших путей между парами вершин
void main()
{
	int vertices = 1, ** Graph;
	size_of_matrix(&vertices);
	Graph = malloc(vertices * sizeof(int));
	for (int i = 0; i < vertices; i++)
		Graph[i] = malloc(sizeof(int) * vertices);
	create_matrix(Graph, vertices);
	floyd(Graph, vertices);
	for (int i = 0; i < vertices; i++)
		free(Graph[i]);
	free(Graph);
}