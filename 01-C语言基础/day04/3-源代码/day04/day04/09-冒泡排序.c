#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0901(void)
{
	int xjp[] = { 12, 32, 14, 62, 27, 8, 89 };

	int n = sizeof(xjp) / sizeof(xjp[0]);	// ����Ԫ�ظ���

	int temp = 0;		// ��ʱ����

	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", xjp[i]);
	}
	printf("\n");

	// ������������ð������
	for (size_t i = 0; i < n-1; i++)		// ��������
	{ 
		for (size_t j = 0; j < n - 1 - i; j++)	// �ڲ������
		{
			if (xjp[j] > xjp[j + 1])		// �������� ����ˮ����
			{
				temp = xjp[j];
				xjp[j] = xjp[j + 1];
				xjp[j + 1] = temp;
			}
		}
	}

	// ��ӡ���������飬ȷ����ȷ�ԡ�
	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", xjp[i]);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}
