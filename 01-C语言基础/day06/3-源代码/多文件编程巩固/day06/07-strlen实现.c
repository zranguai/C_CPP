#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int mystrlen(char arr[]);

int main0701(void)
{
	char abc[] = "hello world";

	int ret = mystrlen2(abc);  // ʵ�ʲ��� abc

	printf("ret = %d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}

// �������� ʵ�� 
int mystrlen(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

// ����ָ��++ ʵ�� 
int mystrlen2(char str[])
{
	char *p = str;
	while (*p != '\0')
	{
		p++;
	}
	return p-str;  // ��������Ԫ�صĸ�����
}

