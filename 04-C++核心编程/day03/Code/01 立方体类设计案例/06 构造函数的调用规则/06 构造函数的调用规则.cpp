#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1�����������һ���� �������3������    Ĭ�Ϲ��죨��ʵ�֣�   ������������ʵ�֣�   �������죨ֵ������
//2����������Լ��ṩ�� �вι��캯�����������Ͳ����ṩĬ�Ϲ��캯����������Ȼ���ṩ�������캯��
//3����������Լ��ṩ�� �������캯�����������Ͳ����ṩ�������캯��
class Person
{
public:

	Person()
	{
		cout << "Ĭ�Ϲ��캯������" << endl;
	}

	Person(int age)
	{
		m_Age = age;
		cout << "�вι��캯������" << endl;
	}

	Person(const Person &p)
	{
		m_Age = p.m_Age;
		cout << "�������캯������" << endl;
	}

	~Person()
	{
		cout << "������������" << endl;
	}

	int m_Age;
};

void test01()
{
	Person p1;//�ṩ���������Ҫ�Լ��ṩĬ�Ϲ��죬�������
	p1.m_Age = 20;

	Person p2(p1);

	cout << "p2������Ϊ�� " << p2.m_Age << endl;

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}