#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyOutOfRangeException:public exception
{
public:

	MyOutOfRangeException( const char * str)
	{
		//const char * ������ʽ����ת��Ϊ string  ��֮������
		this->m_errorInfo = str;
	}

	MyOutOfRangeException(string str)
	{
		this->m_errorInfo = str;
	}

	virtual const char *  what() const
	{
		//��string תΪ const char * 
		return m_errorInfo.c_str();
	}

	string m_errorInfo;
};

class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			throw MyOutOfRangeException( string( "���������0��150֮��"));
		}
		else
		{
			this->m_Age = age;
		}
	}

	int m_Age;
};


void test01()
{
	try
	{
		Person p(1000);
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}


}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}