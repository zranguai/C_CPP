#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma pack(show) //�鿴��ǰ����ģ�� ������ģ���ǿ��Ըĵģ��ĳ�2��N�η�

//��һ�����Կ�ʼ  ��0��ʼƫ��
//�ڶ������Կ�ʼ  Ҫ���� �����͵Ĵ�С  ��  ����ģ����  ȡС��ֵ  ��������
//�������Զ��������������������ƫ�ƣ����������Ľ�� Ҫ����  �ṹ��������� �����ģ����  ȡС��ֵ�� ��������

typedef struct _STUDENT{

	int a;    //0 ~ 3      0 ~ 3
	char b;   //4 ~ 7      4
	double c; //8 ~ 15     5 ~ 12
	float d;  //16 ~ 19    13 ~ 16
}Student;


void test01()
{
	printf("sizeof  student  = %d\n", sizeof(Student));

}

//�ṹ��Ƕ�׽ṹ��ʱ���ӽṹ����ڸýṹ����������� �Ͷ���ģ���� ���������ϼ���
typedef struct _STUDENT2{
	char a;  // 0 ~ 7
	Student b; // 8  ~ 31
	double c;  //32 ~ 39
}Student2;

void test02()
{
	printf("sizeof  student  = %d\n", sizeof(Student2));
}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}