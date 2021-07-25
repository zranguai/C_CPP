#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// ��������Ԫ�ص� 4 �ַ���
int main0501(void)
{
	int a[] = {1, 2, 4, 5, 6, 7, 8, 9, 0};

	int n = sizeof(a) / sizeof(a[0]);

	int *p = a;

	printf("sizeof(a) = %u\n", sizeof(a));
	printf("sizeof(p) = %u\n", sizeof(p));

	for (size_t i = 0; i < n; i++)
	{
		//printf("%d "), a[i];
		//printf("%d ", *(a+i));  // a[i] == *(a+i)
		//printf("%d ", p[i]);
		printf("%d ", *(p+i));  // p[i] = *(p+i)
	}
	printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}

// ʹ��ָ��++��������Ԫ��
int main0502(void)
{
	int arr[] = { 1, 2, 4, 5, 6, 7, 8, 9, 0 };
	int *p = arr;
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("first p = %p\n", p);

	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", *p);
		p++;  // p = p+1;   һ�μӹ�һ��int��С�� һ��Ԫ�ء�
	}
	putchar('\n');

	printf("last p = %p\n", p);

	system("pause");
	return EXIT_SUCCESS;
}

// �ۺ���ϰ
int main0503(void)
{
	int arr[10];
	int n = sizeof(arr) / sizeof(arr[0]);
	int *p = arr;

	for (size_t i = 0; i < n; i++)
	{
		*(p + i) = 10 + i;  //*(p + i) == arr[i]
	}						// p ָ��������׵�ַ��

	for (size_t i = 0; i < n; i++)
	{
		printf("%d ", *p);
		p++;
	}						// pָ��ָ��һ����Ч���ڴ�����pΪ Ұָ�롣
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}


