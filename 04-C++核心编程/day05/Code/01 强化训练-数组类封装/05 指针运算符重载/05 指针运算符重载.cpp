#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{	
		cout << "Person���вι������" << endl;
		this->m_Age = age;
	}

	void showAge()
	{
		cout << "����Ϊ�� "<< this->m_Age << endl;
	}

	~Person()
	{
		cout << "Person����������" << endl;
	}

	int m_Age;
};

class SmartPoint
{
public:
	SmartPoint(Person * person)
	{
		this->m_person = person;
	}

	//����->�����
	Person * operator->()
	{
		return this->m_person;
	}
	//���� * �����
	Person& operator*()
	{
		return *m_person;
	}
	~SmartPoint()
	{
		if (this->m_person)
		{
			delete this->m_person;
			this->m_person = NULL;
		}
	}
private:
	Person * m_person;
};

void test01()
{
	//Person * p = new Person(18);
	//(*p).showAge();
	//p->showAge();
	//delete p;


	//��������ָ�� ���� new������person���ͷŲ���
	SmartPoint sp(new Person(18));

	sp->showAge(); // ����sp->->showAge(); ��������Ϊ sp->showAge();

	(*sp).showAge();

}


int main(){
	test01();

	system("pause");
	return EXIT_SUCCESS;
}