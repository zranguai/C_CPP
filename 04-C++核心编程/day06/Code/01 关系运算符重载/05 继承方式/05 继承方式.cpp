#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

/////////////////   �����̳�  ////////////////
class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Base1
{
public:

	void func()
	{
		m_A = 100; //������ ����Ȩ�� �����б�Ϊ  ����Ȩ��
		m_B = 100; //������ ����Ȩ�� �����б�Ϊ  ����Ȩ��
		//m_C = 100;// ������˽�г�Ա�������޷�����
	}
};

void test01()
{
	Son1 s1;
	s1.m_A = 100; //��Son1�� m_A�ǹ���Ȩ��  ������Է���
	//s1.m_B = 100; //��Son1�� m_B�Ǳ���Ȩ��  ���ⲻ���Է���
}


/////////////////   �����̳�  ////////////////
class Base2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 : protected Base2
{
public:
	void func()
	{
		m_A = 100;//������ ����Ȩ�� �����б�Ϊ  ����Ȩ��
		m_B = 100;//������ ����Ȩ�� �����б�Ϊ  ����Ȩ��
		//m_C = 100;//������˽�г�Ա�������޷�����
	}
};

void test01()
{
	Son2 s;
	//s.m_A = 100;  //������ ����Ȩ�� �޷�����
	//s.m_B = 100;  //������ ����Ȩ�� �޷�����
	//s.m_C = 100; //���౾��û�з���Ȩ��
}


/////////////////   ˽�м̳�  ////////////////
class Base3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
class Son3 :private Base3
{
public:
	void func()
	{
		m_A = 100;  //������ ����Ȩ�� �����б�Ϊ  ˽��Ȩ��
		m_B = 100;  //������ ����Ȩ�� �����б�Ϊ  ˽��Ȩ��
		//m_C = 100;//������˽�г�Ա�������޷�����
	}
};
class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 100;//��Son3�� �Ѿ���Ϊ˽��Ȩ�ޣ�GrandSon3���ʲ���
		//m_B = 100;
	}
};
void test03()
{
	Son3 s;
	//s.m_A = 100;//��Son3�б�Ϊ˽��Ȩ�ޣ�������ʲ���
	//s.m_B = 100;//��Son3�б�Ϊ˽��Ȩ�ޣ�������ʲ���

}

int main(){



	system("pause");
	return EXIT_SUCCESS;
}