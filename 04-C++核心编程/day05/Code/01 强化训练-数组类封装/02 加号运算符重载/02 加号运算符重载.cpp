#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(){};
	Person(int a, int b) :m_A(a), m_B(b)
	{};

	//���ó�Ա����ʵ�ּӺ����������
	//Person operator+(Person &p)
	//{
	//	Person temp;
	//	temp.m_A = this->m_A + p.m_A;
	//	temp.m_B = this->m_B + p.m_B;
	//	return temp;
	//}

	int m_A;
	int m_B;
};


//����ȫ�ֺ���ʵ�ּӺ����������
Person operator+(Person &p1, Person &p2)
{
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}

Person operator+(Person &p1, int num)
{
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}


void test01()
{
	Person p1(10, 10);
	Person p2(20, 20);

	Person p3 = p1 + p2;
	//Person p3 = operator+(p1, p2); //ȫ�ֺ�������

	//Person p3 = p1.operator+(p2); //��Ա��������

	cout << "p3.m_A = " << p3.m_A << " p3.m_B = " << p3.m_B << endl;


	//���������  �ɲ����Է��� �������أ�  ����

	//p1 + 10;

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}