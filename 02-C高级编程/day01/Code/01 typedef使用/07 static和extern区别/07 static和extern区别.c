#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//static ��̬����
// �ص㣺������ǰ�����ڴ棬�������н��� �������ڽ���  ���ڱ��ļ��ڶ�����ʹ�þ�̬����
// ȫ�������� a
static int a = 10;

void test01()
{
	//�ֲ������� b
	static int b = 20;
}


int main(){

	//���߱����� ��������г��� g_a ��Ҫ�������ⲿ�������ԣ��������ļ���
	extern int g_a;

	printf("g_a = %d\n", g_a);

	system("pause");
	return EXIT_SUCCESS;
}