#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����ָ��Ķ��巽ʽ
//1���ȶ����������ͣ���ͨ�����Ͷ�������ָ��
void test01()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	typedef int(ARRARY_TYPE)[5];//ARRARY_TYPE ������5��int����Ԫ�ص����� ����������
	
	/*ARRARY_TYPE arr2;
	for (int i = 0; i < 5;i++)
	{
		arr2[i] = 100 + i;
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr2[i]);
	}*/

	ARRARY_TYPE * arrP = &arr;
	// *arrP == arr == ������
	for (int i = 0; i < 5;i++)
	{
		printf("%d\n", (*arrP)[i]);
	}

}

void test02()
{
	//�ȶ�������ָ�����ͣ���ͨ�����Ͷ�������ָ��
	int arr[5] = { 1, 2, 3, 4, 5 };

	typedef int(*ARRARY_TYPE)[5];

	ARRARY_TYPE arrP = &arr;

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", (*arrP)[i]);
	}

}

void test03()
{
	//ֱ�Ӷ�������ָ�����

	int arr[5] = { 1, 2, 3, 4, 5 };

	int(* p )[5] = &arr;

	for (int i = 0; i < 5;i++)
	{
		printf("%d\n", (*p)[i]);
	}

}

int main(){

	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}