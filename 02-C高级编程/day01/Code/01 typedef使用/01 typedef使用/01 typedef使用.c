//#define _CRT_SECURE_NO_WARNINGS   //VS��ʹ�ô�ͳ�⺯�� �Ὠ����_s����ȫ������������ûᱨ���� C4996
#include<stdio.h>   //��׼   i input ����   o  output  ���
#include<string.h>  //���ַ�������  strcat strstr strcmp strcpy
#include<stdlib.h>  //malloc   free



//1��typedefʹ��  ���Լ� struct�ؼ���
//���������
//struct Person
//{
//	char name[64];
//	int age;
//};
//
////�﷨�� typedef  ԭ��   ����
//typedef struct Person  myPerson;


typedef struct Person
{
	char name[64];
	int age;
}myPerson;

void test01()
{
	struct Person p = { "aaa", 10 };

	myPerson p2 = { "bbb", 20 };

}


//2��������������
void test02()
{
	typedef char * PCHAR;
	PCHAR p1, p2;
	//char *p1, p2;

	char *p3, *p4;
}

//3�������ֲ��
typedef int  MYINT;
void test03()
{
	MYINT a = 10;

	MYINT b = 10;

}



//main ���� �������
int main1(){

	//char buf[1024];
	//strcpy(buf, "hello world");
	//printf("%s\n", buf);



	system("pause");  //����  �밴���������
	
	return EXIT_SUCCESS; //���سɹ��˳�  0
}