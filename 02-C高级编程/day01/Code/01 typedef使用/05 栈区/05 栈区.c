#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int * myFunc()
{
	int a = 10;
	return &a;
}

void test01()
{
	//�ֲ�����a���ѱ��ͷţ��������û��Ȩ�޲�������ڴ�ռ�
	int * p = myFunc();
	printf("*p = %d\n", *p);
	printf("*p = %d\n", *p);
}


char * getString()
{
	char str[] = "hello world";
	return str;
}

void test02()
{
	char * p = NULL;
	p = getString();
	printf("%s\n", p);
}



int main(){

	//test01();
	test02();


	system("pause");
	return EXIT_SUCCESS;
}