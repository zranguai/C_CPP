#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		this->m_A = 10;
	}

	void func()
	{
		cout << "Base�е�func����" << endl;
	}

	void func(int a)
	{
		cout << "Base�е�func(int)����" << endl;
	}

	int m_A;
};

class Son :public Base
{
public:

	Son()
	{
		this->m_A = 20;
	}

	void func()
	{
		cout << "Son�е�func����" << endl;
	}

	int m_A;
};




void test01()
{
	Son s1;

	cout << "s1.m_A = " <<  s1.m_A << endl;

	//���ǿ������������� ���ʸ����е�ͬ����Ա
	cout << "Base�е�m_A = " << s1.Base::m_A << endl;
}

void test02()
{
	Son s1;
	s1.func();
	s1.Base::func(10);

	//���������¶����˸����е�ͬ����Ա����������ĳ�Ա������ ���ص��������������ذ汾��ͬ����Ա������������������ʾָ������

}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}