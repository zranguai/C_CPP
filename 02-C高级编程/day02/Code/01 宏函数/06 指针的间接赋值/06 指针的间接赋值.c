#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//��Ӹ�ֵ��������
// һ����ͨ����  �� ָ�����   ��  һ��ʵ�κ�һ���β�
// ������ϵ
// * �����ڴ�

void changeValue(int *a) // int * a = &a2;
{
	*a = 1000;
}

void test01()
{
	int  a = 10;
	int * p = NULL;


	p = &a;

	*p = 100;

	int a2 = 10;
	changeValue(&a2);

	printf("%d\n", a2);
	printf("%d\n", &a2);
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}