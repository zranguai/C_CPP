#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * func()
{
	char * p =  malloc(10); //�������ݣ�ֻҪû���ͷţ�������ʹ��
	int c = 10;//��func�п���ʹ�ã�test01��main��������ʹ��
	return p;
}

void test01()
{
	int b = 10; // ��test01 ��func ����ʹ�ã���main�в�������

	func();
}

int main(){

	int a = 10; //��main ��test01 �� func�ж�����ʹ��

	test01();


	system("pause");
	return EXIT_SUCCESS;
}