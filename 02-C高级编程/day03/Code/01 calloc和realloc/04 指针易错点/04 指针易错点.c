#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	char * p = malloc(sizeof(char)* 64);
	char * pp = p; //ͨ��������ʱָ������ڴ棬��ֹ����
	for (int i = 0; i < 10;i++)
	{
		*pp = i + 97;
		printf("%c\n", *pp);
		pp++; //����ָ��λ�ã��ͷų���
	}

	if (p!= NULL)
	{
		free(p);
	}


}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}