#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��sizeof����  �ǲ���һ���������������Ǻ��� ������ ������ 
void test01()
{
	printf("size of int = %d\n", sizeof(int));

	double d = 3.14;
	
	printf("size of d = %d\n", sizeof d);
}

//2��sizeof ����ֵ���� �޷������� unsigned int
void test02()
{
	//unsigned int a = 10;
	////��unsigned int �� int�����㣬��ת����ͳһ unsigned int��������
	//if (a  - 20 > 0)
	//{
	//	printf("����0\n");
	//}
	//else
	//{
	//	printf("С��0\n");
	//}

	if ( sizeof(int) - 5 >0)
	{
		printf("����0\n");
	}
	else
	{
		printf("С��0\n");
	}

}

//sizeof ��;��ͳ�����鳤�� , ������������������ʱ�򣬻��˻�Ϊָ�룬ָ�������е�һ��Ԫ�ص�λ��
void calculateArray(int arr[])
{
	printf("array length = %d\n", sizeof(arr));
}

void test03()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	calculateArray(arr);
	//printf("array length = %d\n", sizeof(arr));

}

int main(){

	//test01();
	//test02();
	test03();

	

	system("pause");
	return EXIT_SUCCESS;
}