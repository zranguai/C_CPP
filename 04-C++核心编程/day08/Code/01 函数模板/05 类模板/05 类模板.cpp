#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
template<class NAMETYPE, class AGETYPE = int > //��ģ���� ������Ĭ�ϲ���
class Person
{
public:
	Person(NAMETYPE name, AGETYPE age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "������ " << this->m_Name << " ���䣺 " << this->m_Age << endl;
	}
	NAMETYPE m_Name;
	AGETYPE m_Age;
};

void test01()
{
	
	//��ģ��ͺ���ģ������
	//1����ģ�岻����ʹ���Զ������Ƶ���ֻ������ʾָ������
	//2����ģ���� ������Ĭ�ϲ���
	//Person p1("�����", 100);

	Person<string > p1("�����", 100);
	p1.showPerson();
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}