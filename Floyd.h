#ifndef	_FLOYD_H
#define _FLOYD_H

//�������� �� ��������������� �����
void check_int(int* x);

//������ �������
void size_of_matrix(int* vertices);

//�������� �������
void create_matrix(int** Graph, int vertices);

//�������� ������
void floyd(int** Graph, int vertices);

#endif//_FLOYD_H