#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//calloc
void test01()
{
	//int * p = malloc(sizeof(int)* 10);

	int * p = calloc(10, sizeof(int)); //calloc �����ڶ�������malloc��ͬ���� calloc���ʼ������Ϊ0

	for (int i = 0; i < 10;i++)
	{
		printf("%d\n", p[i]);
	}

	if ( p != NULL)
	{
		free(p);
		p = NULL;
	}

}


//realloc  ���·����ڴ�
void test02()
{
	int * p = malloc(sizeof(int)* 10);

	for (int i = 0; i < 10;i++)
	{
		p[i] = i + 100;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", p[i]);
	}

	printf("%d\n", p);

	//������·�����ڴ��ԭ������ô�����ʼ���¿ռ�Ϊ0
	p = realloc(p, sizeof(int)* 20);

	printf("%d\n", p);

	for (int i = 0; i < 20; i++)
	{
		printf("%d\n", p[i]);
	}

	//������·�����ڴ��ԭ��С����ô�ͷź���ռ䣬ֻ��Ȩ�޲�������ռ�
	p = realloc(p, sizeof(int)* 5);
	printf("%d\n", p);
	printf("%d\n", p[0]);
	printf("%d\n", p[5]);
}




int main(){



	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}