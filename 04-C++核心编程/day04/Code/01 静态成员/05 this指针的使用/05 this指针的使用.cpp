#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		//��;1 ��������Ƴ�ͻ
		this->age = age;
	}


	//thisָ�� ��ʽ����ÿ����Ա������
	bool compareAge(Person &p)
	{
		if (this->age == p.age)
		{
			return true;
		}
		return false;
	}


	Person&  personAddPerson(Person &p)
	{
		this->age += p.age;
		return *this; //*this ���Ǳ���
	}

	int age;
};

void test01()
{
	//thisָ�� ָ�� �����õĳ�Ա���� �����Ķ���
	Person p1(10);

	cout << "p1������Ϊ�� " << p1.age << endl;


	Person p2(10);

	bool ret = p1.compareAge(p2);
	if (ret)
	{
		cout << "p1��p2�������" << endl;
	}


	p1.personAddPerson(p2).personAddPerson(p2).personAddPerson(p2); //��ʽ���
	cout << "p1������Ϊ�� " << p1.age << endl;

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}