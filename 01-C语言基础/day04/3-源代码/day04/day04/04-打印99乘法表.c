#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// ����99�˷���
int main0401(void)
{
	for (size_t i = 1; i <=9; i++)
	{
		for (size_t j = 1; j <= i; j++)
		{
			printf("%dx%d=%d\t", j, i, j*i);
		}
		printf("\n");
	}
	system("pause");
	return EXIT_SUCCESS;
}

// ���� 99 �˷���
int main0402(void)
{
	int i, j;

	for (i = 9; i >= 1; i--)		// ��
	{
		for (j = 1; j <= i; j++)		// ��
		{
			printf("%dx%d=%d\t", j, i, j*i);
		}
		putchar('\n');
	}

	system("pause");
	return EXIT_SUCCESS;
}
