#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void write_rand()
{
	FILE *fp = fopen("test02.txt", "w");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}

	srand(time(NULL)); // ���������

	for (size_t i = 0; i < 10; i++)
	{
		fprintf(fp, "%d\n", rand() % 100);  // �����ɵ������д���ļ�
	}
	
	fclose(fp);
}


void BubbleSort(int * src, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (src[j] > src[j + 1])
			{
				int temp = src[j];
				src[j] = src[j + 1];
				src[j + 1] = temp;
			}
		}
	}
}

void read_rand02()
{
	int arr[10], i = 0;

	FILE *fp = fopen("test02.txt", "r");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}

	while (1)
	{
		fscanf(fp, "%d\n", &arr[i]);// ���ļ��ж�ȡһ�����������������arr
		i++;
		if (feof(fp))				// �ȴ洢�����жϣ���ֹ���һ��Ԫ�ض�ʧ
			break;
	}
	BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));  // �Զ�ȡ����������������

	fclose(fp);							// �ر��ļ�
	fp = fopen("test02.txt", "w");		// ����w��ʽ���ļ��� ���ԭδ�����ļ���
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}
	for (size_t i = 0; i < 10; i++)
		fprintf(fp, "%d\n", arr[i]);	// д�ź�������鵽�ļ�

	fclose(fp);
}

int main0201(void)
{
	write_rand();

	getchar();

	read_rand02();

	system("pause");
	return EXIT_SUCCESS;
}
