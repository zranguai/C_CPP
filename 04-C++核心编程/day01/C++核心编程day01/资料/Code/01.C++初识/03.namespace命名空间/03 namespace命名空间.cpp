#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "game1.h"
#include "game2.h"

//1�������ռ���;�� ������Ƴ�ͻ
void test01()
{
	KingGlory::goAtk();

	LOL::goAtk();
}

//2�������ռ��� ���Է�  �������������ṹ�塢��...
namespace A
{
	int m_A;
	void func();
	struct Person
	{};
	class Animal
	{};
}

//3�������ռ� ����Ҫ������ȫ����������
void test02()
{
	//namespace B{}; �������������ֲ�������
}

//4�������ռ����Ƕ�������ռ�
namespace B
{
	int m_A = 10;
	namespace C
	{
		int m_A = 20;
	}
}
void test03()
{
	cout << "B�ռ��µ�m_A = " << B::m_A << endl;
	cout << "C�ռ��µ�m_A = " << B::C::m_A << endl;
}

//5�������ռ��ǿ��ŵģ�������ʱ�������ռ�����µĳ�Ա
namespace B
{
	int m_B = 100;
}
void test04()
{
	cout << "B�ռ��µ�m_A = " << B::m_A << endl;
	cout << "B�ռ��µ�m_B = " << B::m_B << endl;
}

//6�������ռ������������
namespace
{
	int m_C = 1000;
	int m_D = 2000; 
	//��д�������ռ�������ģ��൱��д��  static int m_C = 1000; static int m_D = 2000;
}

void test05()
{
	cout << "m_C = " << m_C   << endl;
	cout << "m_D = " << ::m_D << endl;
}

//7�������ռ���������
namespace veryLongName
{
	int m_E = 10000;
	void func()
	{
		cout << "aaa" << endl;
	}
}



void test06()
{
	namespace veryShortName = veryLongName;
	cout << veryShortName::m_E << endl;
	cout << veryLongName::m_E << endl;

}

int main(){
	//test01();
	//test03();
	//test04();
	//test05();
	test06();
	

	system("pause");
	return EXIT_SUCCESS;
}