#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:

	static void func()
	{
		cout << "Base�е�func���� " << endl;
	}

	static void func(int a)
	{
		cout << "Base�е�func(int a)���� " << endl;
	}

	static int m_A;

};

int Base::m_A = 10;


class Son :public Base
{
public:

	static void func()
	{
		cout << "Son�е�func���� " << endl;
	}

	static int m_A;
};
int Son::m_A = 20;

void test01()
{
	//1��ͨ���������
	Son s;
	cout << "m_A = " << s.m_A << endl;
	cout << "Base�е�m_A = " << s.Base::m_A << endl;

	//2��ͨ����������

	cout << "m_A = " << Son::m_A << endl;
	//ͨ�������ķ�ʽ ���� �����������µ�m_A��̬��Ա����
	cout << "Base�е�m_A = " <<  Son::Base::m_A << endl;
}


void test02()
{
	//1��ͨ������
	Son s;
	s.func();
	s.Base::func();


	//2��ͨ������
	Son::func();
	//�������ض��常����ͬ����Ա����������ĳ�Ա���������ص����������а汾����Ҫ�����������
	Son::Base::func(1);
}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}