#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

template<class T1,class T2>
class Person;

template<class T1,class T2>
void printPerson2(Person<T1, T2> &p);

template<class T1,class T2>
void printPerson3(Person<T1, T2>&p)
{
	cout << "����ʵ�� --- ������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
	//1����Ԫ���� ����ʵ��
	friend void printPerson(Person<T1, T2> &p)
	{
		cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
	}

	//2����Ԫ���� ����ʵ��
	friend void printPerson2<>(Person<T1, T2> &p);

	
	friend void printPerson3<>(Person<T1, T2> &p);
public:
	Person(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

template<class T1,class T2>
void printPerson2(Person<T1, T2> &p)
{
	cout << "����ʵ�� --- ������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;
}

void test01()
{
	Person <string, int> p("Tom", 100);
	printPerson(p);
	printPerson2(p);
	printPerson3(p);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}