#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//������������
//1����ͬһ��������
//2������������ͬ
//3���������������͡�˳��ͬ

//class Person
//{
//public:
//	void func()   ��Ա���� ������ȫ�ֺ���
//	{
//	}
//};

void func()
{
	cout << "func()����" << endl;
}

void func(int a)
{
	cout << "func(int a)����" << endl;
}

void func(double a)
{
	cout << "func(double a)����" << endl;
}

void func(int a, double b)
{
	cout << "func(int a ,double b)����" << endl;
}

void func(double a, int b)
{
	cout << "func(double a, int b)����" << endl;
}

//����ֵ�ɲ�������Ϊ�������ص����� �𰸣�������
//int func(int a, double b)
//{
//	cout << "func(int a ,double b)����" << endl;
//}



void test01()
{
	func(1,3.14);
}



//���������� ���������汾
//void myFunc(int a)
//{
//	cout << "myfunc(int a )����" << endl;
//}
void myFunc(int &a) // int & a  = 10;
{
	cout << "myfunc(int &a )����" << endl;
}
void myFunc(const int &a) // const int &a = 10;
{
	cout << "myfunc( const int &a )����" << endl;
}


void test02()
{
	int a = 10;
	//myFunc(a);//��Ҫ��������Գ���

}


//������������Ĭ�ϲ���  ע���������Գ���
void func2(int a , int b = 10)
{

}

void func2(int a)
{

}

void test03()
{
	//func2(10); //���ֶ�����
}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}