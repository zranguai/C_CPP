#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// ��ʽ����ת����
int main0601(void)
{
	int a = 321;		

	char ch = a;

	printf("ch = %d\n", ch);

	system("pause");
	return EXIT_SUCCESS;
}

// ǿ������ת��
int main0602(int var)
{
	//int *p = (int *)malloc(100);

	float price = 3.6;
	int weight = 4;

	//double sum = (int)price * weight;

	double sum = (int)(price * weight);

	printf("�۸�%lf\n", sum);

	system("pause");
	return EXIT_SUCCESS;
}
