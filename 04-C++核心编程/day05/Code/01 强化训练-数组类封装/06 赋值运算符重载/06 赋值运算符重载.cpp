#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//������ Ĭ�ϸ�һ����4������   Ĭ�Ϲ���   ����   �������� ��ֵ������  operator= (ֵ����)
class Person
{
public:
	Person(char * name, int age)
	{
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
		this->m_Age = age;
	}

	//���� =
	Person& operator=( const Person &p)
	{
		//���ж�ԭ�������ͷ������ݣ���������ͷ�
		if (this->m_Name != NULL)
		{
			delete [] this->m_Name;
			this->m_Name = NULL;
		}

		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
		return *this;
	}

	//��������
	Person(const Person & p)
	{
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);
		this->m_Age = p.m_Age;
	}

	~Person()
	{
		if (this->m_Name!=NULL)
		{
			delete [] this->m_Name;
			this->m_Name = NULL;
		}
	}

	char * m_Name;
	int m_Age;
};


void test01()
{
	Person p1("Tom",10);
	
	Person p2("Jerry",19);
	p2 = p1;

	Person p3("", 0);
	p3 = p2 = p1;


	Person p4 = p3;

	cout << "p1������ "<< p1.m_Name << "  p1���䣺 " << p1.m_Age << endl;
	cout << "p2������ "<< p2.m_Name << "  p2���䣺 " << p2.m_Age << endl;
	cout << "p3������ " << p3.m_Name << " p3���䣺 " << p3.m_Age << endl;

}

int main(){

	test01();

	/*int a = 10;
	int b = 20;
	int c;
	c = a = b;
	cout << "a = " << a << " b = " << b << " c = " << c << endl;*/


	system("pause");
	return EXIT_SUCCESS;
}