#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��void �����ͣ�������ͨ��void����������ԭ���޷���void�����ͱ��������ڴ�
void test01()
{
	//void  a = 10;
}

//2����;�� �޶���������ֵ,�޶���������
void test02(void)
{
	//return 10;
}

//3��void *   ����ָ��  ���ܼ���ָ��,��������ָ�붼��4���ֽ�
void test03()
{
	//printf("size of void* = %d\n", sizeof(void *));
	void * p = NULL;

	int * pInt = NULL;
	char * pChar = NULL;

	pChar = (char *)pInt;

	pChar = p; //����ָ��  ���Բ�ͨ��ǿ������ת����ת����������ָ��

}

int main(){
	
	//test02(10);
	test03();


	system("pause");
	return EXIT_SUCCESS;
}