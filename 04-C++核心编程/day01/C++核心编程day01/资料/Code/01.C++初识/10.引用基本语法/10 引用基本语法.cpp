#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���û����﷨��  ����  &���� = ԭ��
void test01()
{
	int a = 10;
	int &b = a;

	b = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}


void test02()
{
	int a = 10;
	//int &b; //���ñ���Ҫ��ʼ��

	int &b = a;

	//����һ����ʼ���󣬾Ͳ�����������������

	int c = 100;

	b = c; // ��ֵ

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}

//�����齨������
void test03()
{
	//1��ֱ�ӽ�������
	int arr[10];
	int(&pArr)[10] = arr;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = 100 + i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << pArr[i] << endl;
	}


	//2���ȶ�����������ͣ���ͨ������ ��������
	typedef int(ARRAY_TYPE)[10];
	//����  &���� = ԭ��
	ARRAY_TYPE & pArr2 = arr;

	for (int i = 0; i < 10; i++)
	{
		cout << pArr2[i] << endl;
	}

}

int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}