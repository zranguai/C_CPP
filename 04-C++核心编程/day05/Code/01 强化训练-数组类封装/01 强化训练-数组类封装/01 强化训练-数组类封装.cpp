#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "myArray.h"


void test01()
{
	MyArray arr;

	for (int i = 0; i < 10;i++)
	{
		arr.pushBack(i);
	}


	for (int i = 0; i < arr.getSize(); i ++)
	{
		cout << arr.getData(i) << endl;
	}


	MyArray arr2(arr);
	for (int i = 0; i < arr2.getSize(); i++)
	{
		cout << arr2.getData(i) << endl;
	}

	arr.setData(0, 1000);

	cout << "arr 0��λ������Ϊ�� " << arr.getData(0) << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr.getData(i) << endl;
	}

	cout << "��������Ϊ�� " << arr.getCapcity() << endl;
	cout << "�����СΪ�� " << arr.getSize() << endl;

	//С���� ����[]��ʽȥ���������е�Ԫ�أ��ɶ���д
	cout << "---------------------" << endl;

	arr[0] = 10000;
	cout << arr[0] << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}