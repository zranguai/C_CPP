#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>
class Person
{
public:
	//��������
	void setName(string name)
	{
		m_Name = name;
	}
	//��ȡ����
	string getName()
	{
		return m_Name;
	}

	//��ȡ����
	int getAge()
	{
		return m_Age;
	}

	//��������
	void setAge(int age)
	{
		if ( age < 0 || age > 150)
		{
			cout << "�����������" << endl;
			return;
		}
		m_Age = age;
	}

	//��������
	void setLover(string lover)
	{
		m_Lover = lover;
	}

private:
	string m_Name;  //����  �ɶ���д
	int m_Age = 18;      //����  �ɶ� ��д��0 ~ 150֮�䣩
	string m_Lover; //����  ֻд
};

void test01()
{
	Person p;
	//���Խ�char * ��ʽ����ת��Ϊ string
	p.setName("����");
	cout << "������ " << p.getName() << endl;

	//��ȡ����
	p.setAge(100);
	cout << "���䣺 " << p.getAge() << endl;

	//��������
	p.setLover("�Ծ�");

	//cout << "���������ǣ�"<< p.m_Lover <<endl; //������ֻдȨ��  �ⲿ���ʲ���

}

//����Ա���Զ�����Ϊ˽�кô����Լ����Կ��ƶ�дȨ��
//���Զ��������� ����Ч����֤
int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}