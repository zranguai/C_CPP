#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream &cout, Person & p1);

public:

	Person(int a, int b)
	{
		this->m_A = a;
		this->m_B = b;
	}

	//��ͼ���ó�Ա���� ��<<����
	//void operator<<( Person & p)    // p.operator<<(cout)    p<<cout
	//{
	//
	//}

private:
	int m_A;
	int m_B;
};

//����ȫ�ֺ��� ʵ���������������
ostream& operator<<(ostream &cout, Person & p1)
{
	cout << "m_A = " << p1.m_A << " m_B = " << p1.m_B;
	return cout;
}

void test01()
{
	Person p1(10, 10);

	cout << p1 << endl;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}