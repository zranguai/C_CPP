#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0201(void)
{
/*
56 78 92
45 67 93
29 83 88
93 56 89
72 83 81
*/
	int scores[5][3] = {1, 2, 4, 5, 6, 7, 8, 9};

	int row = sizeof(scores) / sizeof(scores[0]);
	int col = sizeof(scores[0]) / sizeof(scores[0][0]);

	// ��ȡ 5 ��ѧ����3�Ź��γɼ�
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			scanf("%c", &scores[i][j]);
		}
	}
	// ��һ��ѧ�����ܳɼ�
	for (size_t i = 0; i < row; i++) // ÿ��ѧ��
	{
		int sum = 0;
		for (size_t j = 0; j < col; j++)// ÿ��ѧ���ĳɼ�
		{
			sum += scores[i][j];
		}
		printf("��%d��ѧ�����ܳɼ�Ϊ��%d\n", i+1, sum);
	}
	//��һ�Ź��ε��ܳɼ�
	for (size_t i = 0; i < col; i++)  // �ڼ��Ź���
	{
		int sum = 0;
		for (size_t j = 0; j < row; j++)  // ÿ�Ź��εĵڼ���ѧ��
		{
			sum += scores[j][i];
		}
		printf("��%d�Ź��ε��ܳɼ�Ϊ��%d\n", i + 1, sum);
	}


	system("pause");
	return EXIT_SUCCESS;
}
