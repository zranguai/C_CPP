#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// int arr[]  �ɶ��Ը���
void printArray(int arr[] , int len) //int arr[]�ȼ���  int * arr
{
	for (int i = 0; i < len;i++)
	{
		printf("%d\n", arr[i]);
	}
}

void test01()
{

	//һά�������ǲ���ָ�룿
	int arr[5] = { 1, 2, 3, 4, 5 };

	printf("%d\n", sizeof(arr));

	//���������������һά���������� ָ���һ��Ԫ�ص�ָ��
	//1��sizeof
	//2����������ȡ��ַ   �õ�����ָ�� �������������鳤��

	
	//printf("%d\n", &arr);
	//printf("%d\n", &arr + 1);
	
	//int * p =  arr;
	int len = sizeof(arr) / sizeof(int);
	printArray(arr, len);

	//arr������  ����һ��ָ�볣�� ָ���ָ�򲻿����޸ĵģ���ָ��ָ���ֵ���Ը� int * const a ; 
	//arr[0] = 1000;
	//arr = NULL;

	//�������� �ɲ�����Ϊ����   �𰸣�����
	int * p = arr;
	p = p + 3;
	printf("%d\n",p[-1]);     //���˿���
	printf("%d\n", *(p - 1)); //����������
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}