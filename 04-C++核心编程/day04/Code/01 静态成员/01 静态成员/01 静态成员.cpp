#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class Person
{
public:
	//1����̬��Ա����
	//��̬��Ա���� ������׶ξͷ������ڴ�
	//�������� �������ʼ��
	//��̬��Ա���� ���ж��󶼹���ͬһ������
	static int m_A;


	//2����̬��Ա����
	//���ж��󶼹���ͬһ��func����
	static void func()
	{
		//m_C = 100; //��̬��Ա���� ���ܷ��ʷǾ�̬��Ա����
		m_A = 100; //��̬��Ա���� �ܷ��ʾ�̬��Ա����
		cout << "func����" << endl;
	}

	int m_C;

private:
	static int m_B; //˽�о�̬��Ա���� 

	static void func2()
	{
	
	}
};

int Person::m_A = 0;
int Person::m_B = 0;


void test01()
{
	//1��ͨ��������з���
	Person p1;
	cout << p1.m_A << endl;

	Person p2;
	p2.m_A = 100;

	cout << p1.m_A << endl;

	//2��ͨ���������з���
	cout << Person::m_A << endl;

	//��̬��Ա���� Ҳ���з���Ȩ�޵ģ�˽��Ȩ��������ʲ���
	//cout << Person::m_B << endl;

}

void test02()
{
	//ͨ������
	Person p1;
	p1.func();
	//ͨ������
	Person::func();


	//Person::func2();  ��̬��Ա����Ҳ���з���Ȩ�޵�


}

int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}