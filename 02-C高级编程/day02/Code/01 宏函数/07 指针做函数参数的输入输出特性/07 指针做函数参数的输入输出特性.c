#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�������ԣ� �������������ڴ棬��������ʹ��
void func(char * p)
{
	strcpy(p, "hello world");
}

void test01()
{
	//��test01�з������ڴ棬������ջ��
	char buf[1024] = { 0 };

	func(buf);

	printf("%s\n", buf);

}

void printString(char * str)
{
	printf("%s\n", str + 6);

}

void test02()
{
	char * p = malloc(sizeof(char)* 64);
	memset(p, 0, 64);
	strcpy(p, "hello world");
	printString(p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}


//������ԣ��ڱ��������з����ڴ棬��������ʹ��
void allocateSpace(char ** pp)
{
	char * str = malloc(sizeof(char)* 64);
	memset(str, 0, 64);
	strcpy(str, "helloworld");

	*pp = str;
}
void test03()
{
	char * p = NULL;

	allocateSpace(&p);

	printf("%s\n", p);

}

int main(){

	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}