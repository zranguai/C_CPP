#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show ����" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show ����" << endl;
	}
};


//��ģ���еĳ�Ա����  ������һ��ʼ�����ģ����������н׶�ȷ����T���������Ͳ�ȥ����
template<class T>
class MyClass
{
public:
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}

	T obj;
};

void test01()
{
	MyClass <Person2> p1;
	//p1.func1();
	p1.func2();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}