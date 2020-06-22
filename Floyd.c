#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Floyd.h"
#include "matrix.h"

//�������� ������
void floyd(int** Graph, int vertices)
{
	int i, j, k;
	for (k = 0; k < vertices; k++)
		for (i = 0; i < vertices; i++)
			for (j = 0; j < vertices; j++)
			{
				if (i == j)
					Graph[i][j] = 0;//���������� ���� �� ������ ���� - 0
				if (Graph[i][j] < 0)
					Graph[i][j] = _CRT_INT_MAX/2;//������ �������������. ������������ �������� int'���� �����
				if (Graph[i][j] > Graph[i][k] + Graph[k][j])
					Graph[i][j] = Graph[i][k] + Graph[k][j];
			}
	printf("\nNew matrix with the smallest distances between vertices:\n");
	print_matrix(Graph, vertices);
}