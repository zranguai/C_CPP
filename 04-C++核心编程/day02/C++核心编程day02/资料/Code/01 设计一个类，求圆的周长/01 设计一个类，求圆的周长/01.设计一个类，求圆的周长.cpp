#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//���һ���࣬��Բ���ܳ�

const double PI = 3.14;

//class + ����
//�ܳ���ʽ ��   2 * pi * m_R
class Circle
{
public: //����Ȩ��

	//���еĺ���  ��Ϊ ��Ա����  ��Ա����
	//��Բ�ܳ�
	double calculateZC()
	{
		return 2 * PI * m_R;
	}

	//���ð뾶
	void setR(int r)
	{
		m_R = r;
	}

	//��ȡ�뾶
	int getR()
	{
		return m_R;
	}


	//���еı���   ��Ϊ��Ա����  ��Ա����
	//�뾶
	int m_R;

};

void test01()
{
	Circle  c1; //ͨ���� ����һ������   ʵ��������
	
	//��c1 �뾶��ֵ
	//c1.m_R = 10;
	c1.setR(10);


	//��c1Բ�ܳ�
	cout << "Բ�İ뾶Ϊ�� " << c1.getR() << endl;
	cout << "Բ���ܳ�Ϊ�� " << c1.calculateZC() << endl;

}



//2 ���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
class Student
{
public:


	//��������
	void setName(string name)
	{
		m_Name = name;
	}

	//����ѧ��
	void setId(int id)
	{
		m_Id = id;
	}

	//��ʾѧ����Ϣ
	void showStudent()
	{
		cout << "������" << m_Name << " ѧ�ţ� " << m_Id << endl;
	}

	//���ԣ�
	//����
	string m_Name;
	//ѧ��
	int  m_Id;
};

void test02()
{
	Student s1;
	s1.m_Name = "����";
	s1.m_Id = 1;

	cout << "������" << s1.m_Name << " ѧ�ţ� " << s1.m_Id << endl;

	Student s2;
	s2.setName("����");
	s2.setId(2);
	s2.showStudent();

	Student s3;
	s3.setName("����");
	s3.setId(3);
	s3.showStudent();
}


int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}