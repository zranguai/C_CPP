#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0301(void)
{
	int a = 10;
	int b = 20;

	int c = a * b;

	int d = 34 / 10;  // 0.5

	//int m = 98 / 0;

	//printf("m = %d\n", m);

	system("pause");
	return EXIT_SUCCESS;
}

int main0302(void)
{
	int a = 10;
	int b = 50;

	printf("a = %d\n", a++);  // ��ȡֵ��%d, ������

	printf("----a = %d",a);



	printf("b = %d\n", ++b);  // ������,��ȡֵ�� 

	printf("----b = %d\n", b);

	system("pause");
	return EXIT_SUCCESS;
}
