#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "utl.h"

//�������� �� ������������ �����
void check_enter(int* x)
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
