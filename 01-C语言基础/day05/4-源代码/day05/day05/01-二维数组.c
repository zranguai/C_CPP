#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0101(void)
{
	int arr[3][4] = {	{2, 7, 8, 5}, 
						{75, 8, 9, 8}, 
						{26, 37, 99, 9} };
	for (size_t i = 0; i < 3; i++)		//��
	{
		for (size_t j = 0; j < 4; j++)  //��
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("����Ĵ�СΪ��%u\n", sizeof(arr));
	printf("�����еĴ�С��%u\n", sizeof(arr[0]));
	printf("����һ��Ԫ�صĴ�С��%u\n", sizeof(arr[0][0]));

	printf("����=�ܴ�С/һ�д�С��%d\n", sizeof(arr)/ sizeof(arr[0]));
	printf("����=�д�С/һ��Ԫ�ش�С��%d\n", sizeof(arr[0])/ sizeof(arr[0][0]));

	printf("arr= %p\n", arr);
	printf("&arr[0] = %p\n", &arr[0][0]);
	printf("arr[0] = %p\n", arr[0]);

	system("pause");
	return EXIT_SUCCESS;
}


// ��ά����ĳ�ʼ��
int main0102(void)
{
	int arr[][2] = { 1, 3, 4, 6, 7 };

	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);

	for (size_t i = 0; i < row; i++)		//��
	{
		for (size_t j = 0; j < col; j++)  //��
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("����Ĵ�СΪ��%u\n", sizeof(arr));
	printf("�����еĴ�С��%u\n", sizeof(arr[0]));
	printf("����һ��Ԫ�صĴ�С��%u\n", sizeof(arr[0][0]));

	printf("����=�ܴ�С/һ�д�С��%d\n", sizeof(arr) / sizeof(arr[0]));
	printf("����=�д�С/һ��Ԫ�ش�С��%d\n", sizeof(arr[0]) / sizeof(arr[0][0]));

	printf("arr= %p\n", arr);
	printf("&arr[0] = %p\n", &arr[0][0]);
	printf("arr[0] = %p\n", arr[0]);

	system("pause");
	return EXIT_SUCCESS;
}