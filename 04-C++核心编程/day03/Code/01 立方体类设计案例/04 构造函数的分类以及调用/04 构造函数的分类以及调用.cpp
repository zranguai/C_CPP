#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���캯������
//���ղ������ࣺ �޲ι���(Ĭ�Ϲ��캯��) �� �вι���
//�������ͷ��ࣺ ��ͨ���캯��    �������캯��
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
	Person(const Person &p )  
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

//���캯���ĵ���
void test01()
{
	//Person p;

	//1�����ŷ�
	//Person p1(10);
	//Person p2(p);

	//ע������һ 
	//��Ҫ�����ŷ� �����޲ι��캯��  Person p3();  ��������Ϊ�����Ǻ���������
	

	//2����ʾ��
	//Person p3 = Person(10); //�вι���
	//Person p4 = Person(p3); //��������

	//Person(10); //��������  �ص㣺 ��ǰ��ִ����� �����ͷ�

	//cout << "aaa" << endl;

	//ע�������
	//��Ҫ�ÿ������캯�� ��ʼ�� �������� Person(p3); ��������Ϊ Person p3����ʵ����  ����Ѿ���p3  p3���ض���

	
	//3����ʽ��  
	Person p5 = 10; //Person p5 = Person(10);
	Person p6 = p5;



}

int main(){
	test01();
	//Person p(18);
	//Person p2(p);
	//cout << "p2�����䣺 " << p2.m_Age << endl;


	system("pause");
	return EXIT_SUCCESS;
}