#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}

	Person(int age)
	{
		m_Age = age;
		cout << "Person���вι��캯������" << endl;
	}


	//�������캯��
	Person(const Person &p)
	{
		cout << "Person�Ŀ������캯������" << endl;
		m_Age = p.m_Age;
	}

	//��������
	~Person()
	{
		cout << "Person��������������" << endl;
	}

	int m_Age;

};


//1�����Ѿ������õĶ�������ʼ���µĶ���
void test01()
{
	Person p1(18);

	Person p2 = Person(p1);

	cout << "p2�����䣺" << p2.m_Age<< endl;

}

//2��ֵ���ݵķ�ʽ ������������ֵ
void doWork(Person p)
{

}
void test02()
{
	Person p1(100);

	doWork(p1);

}

//3����ֵ��ʽ ���ؾֲ�����
Person doWork2()
{
	Person p;
	return p;
}

void test03()
{
	Person p = doWork2();
}

/*	
	�������Ż������ release�汾�����������£�
	void doWork2( Person &p ){};

	Person p;
	doWork2(p);
*/



int main(){
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}