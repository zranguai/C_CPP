#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

struct  Person
{
	//����Ȩ��
public:
	char name[64];
	int age;

	void PersonEat()
	{
		printf("%s�ڳ��˷�\n", name);
	}
};

struct Dog
{
	//����Ȩ��
public:
	char name[64];
	int age;

	void DogEat()
	{
		printf("%s�ڳԹ���\n", name);
	}
};

//C++��װ ���  �����Ժ���Ϊ��Ϊһ�����壬�����������е�����

//�ڶ������ �����Ժ���Ϊ  ����Ȩ�޿���

void test01()
{
	struct Person p;
	strcpy(p.name, "����");

	p.PersonEat();

	//p.DogEat();
}


//struct��class ����
//class Ĭ��Ȩ��  ˽��Ȩ��  �� structĬ��Ȩ���� ����Ȩ��
//����Ȩ��
// public  ����Ȩ��    ��Ա ����  ���� �����Է���	 
// private ˽��Ȩ��    ��Ա ����  ���Է���  ����  �����Է���  ���Ӳ����Է��ʸ��׵�privateȨ������
// protected ����Ȩ��  ��Ա ����  ���Է���  ����  �����Է���  ���ӿ��Է��ʸ��׵�protectedȨ������

class Person2
{
public:
	string m_Name; //����Ȩ��

protected:
	string m_Car;  //����Ȩ��

private:
	int  m_pwd;  //˽��Ȩ��

public:

	void func()
	{
		m_Name = "����";
		m_Car = "������";
		m_pwd = 123456;
	}

};

void test02()
{
	Person2 p;
	p.m_Name = "����"; //����Ȩ��  ������Է���
//	p.m_Car = "��˹��˹"; //����Ȩ��  ������ʲ���
//	p.m_pwd = 123; //˽��Ȩ��  ���ⲻ���Է���
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}