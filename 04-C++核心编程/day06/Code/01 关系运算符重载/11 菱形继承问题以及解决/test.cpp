#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//������
class Animal
{
public:
	int m_Age; // ����
};

//Animal��Ϊ �����

//����
class Sheep : virtual public Animal{};
//����
class Tuo : virtual public Animal{};

//����
class SheepTuo : public Sheep, public Tuo
{
};


void test01()
{
	SheepTuo st;

	st.Sheep::m_Age = 10;
	st.Tuo::m_Age = 20;

	cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;
	cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "age = " << st.m_Age << endl;

	//��������̳к�sheep��tuo���� �̳���һ��  vbptrָ��   �����ָ��   ָ�����һ�� ������  vbtable
	//�������м�¼��  ƫ���� ��ͨ��ƫ���� �����ҵ�Ψһ��һ��m_Age
}


void test02()
{
	SheepTuo st;
	st.m_Age = 10;

	//ͨ��Sheep�ҵ� ƫ����
	//*(int *)&st �����õ��� ��������
	cout << *((int *)*(int *)&st + 1) << endl;

	//ͨ��Tuo �ҵ�ƫ����
	cout << *((int *)*((int *)&st + 1) + 1) << endl;

	//ͨ��ƫ����  ����m_Age

	cout << "m_Age = " << ((Animal *)((char *)&st + *((int *)*(int *)&st + 1)))->m_Age << endl;

	cout << "m_Age = " << *((int *)((char *)&st + *((int *)*(int *)&st + 1))) << endl;
}

int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}