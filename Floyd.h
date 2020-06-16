#ifndef	_FLOYD_H
#define _FLOYD_H

//проверка на целочисленность ввода
void check_int(int* x);

//размер матрицы
void size_of_matrix(int* vertices);

//создание матрицы
void create_matrix(int** Graph, int vertices);

//алгоритм Флойда
void floyd(int** Graph, int vertices);

#endif//_FLOYD_H