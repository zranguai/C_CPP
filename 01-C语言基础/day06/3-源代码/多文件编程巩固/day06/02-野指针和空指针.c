#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Ұָ��1
int main0201(void)
{
	/*
	int *p;

	*p = 2000;

	printf("*p = %d\n", *p);
	*/
	system("pause");
	return EXIT_SUCCESS;
}

// Ұָ��2
int main0202(void)
{
	int m;
	//int *p = 1000;   // 0-255 ȷ����������ϵͳ
	int *p = 0x0bfcde0000;

	p = &m;

	*p = 2000;

	printf("*p = %d\n", *p);

	system("pause");
	return EXIT_SUCCESS;
}

// ��ָ��
int main0203(void)
{
	int *p = NULL;   // NULL == 0

	// .....
	// lllll

	// .....

	if (p != NULL)
	{
		*p = 300;
		printf("*p = %d\n", *p);
	}

	system("pause");
	return EXIT_SUCCESS;
}
