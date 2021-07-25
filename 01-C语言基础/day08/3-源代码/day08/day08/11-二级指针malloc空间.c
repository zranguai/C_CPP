#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void)
{
	int **p = malloc(sizeof(int *) * 3);	// int **p ==> int *p[10]; ==> [ int *, int *, int * ]

	for (size_t i = 0; i < 3; i++)
	{
		p[i] = malloc(sizeof(int) * 5);
	}

	// ʹ�ÿռ� -- д
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			p[i][j] = i + j;
		}
	}

	// ʹ�ÿռ� -- ��
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			printf("%d ", *(*(p+i)+j));  // p[i][j] == *(p+i)[j] == *(*(p+i)+j)
		}
		printf("\n");
	}

	// �ͷſռ�ʱ��Ӧ���ͷ��ڲ�ռ䡣
	for (size_t i = 0; i < 3; i++)
	{
		free(p[i]); //*(p+i)
		p[i] = NULL;
	}
	// �ͷ����ռ�
	free(p);
	p = NULL;

	system("pause");
	return EXIT_SUCCESS;
}
