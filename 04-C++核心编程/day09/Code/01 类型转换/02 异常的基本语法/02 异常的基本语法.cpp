#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class MyException
{
public:
	void printError()
	{
		cout << "���Լ����쳣" << endl;
	}
};

class Person
{
public:
	Person()
	{
		cout << "Person��Ĭ�Ϲ��캯������" << endl;
	}
	~Person()
	{
		cout << "Person��������������" << endl;
	}
};

int myDivision(int a , int b)
{
	if ( b == 0)
	{
		//return -1;
		//throw 1; //�׳�int���͵��쳣
		//throw 'a'; //�׳�char���͵��쳣
		//throw 3.14; //�׳�double���͵��쳣
		/*string str = "abc";
		throw str;*/


		//��try����鿪ʼ����throw�׳��쳣֮ǰ������ջ�ϵ����ݶ��ᱻ�ͷŵ���
		//�ͷŵ�˳��ʹ���˳���෴�ģ�����������ǳ�Ϊջ����
		Person p1;
		Person p2;


		throw MyException(); //�׳� MyException����������
	}

	return a / b;
}

void test01()
{
	int a = 10;
	int b = 0;

	//C���Դ����쳣 ��ȱ�ݣ�����ֵ��ͳһ������ֵֻ��һ�����޷������ǽ�������쳣
	//int ret =myDivision(a, b);
	//if ( ret == -1)
	//{
	//	cout << "�쳣" << endl;
	//}

	try
	{
		myDivision(a, b);
	}
	catch (int)
	{
		cout << "int�����쳣����" << endl;
	}
	catch (char)
	{
		cout << "char�����쳣����" << endl;
	}
	catch (double)
	{
		//�������쳣�����ǲ��봦�����������׳�����쳣
		//�쳣�����к������д������û���κδ��������Զ����� terminate �������ó����ж�
		throw;
		cout << "double�����쳣����" << endl;
	}
	catch (MyException e)
	{
		e.printError();
	}
	catch (...)
	{
		cout << "���������쳣����" << endl;
	}
	
}

int main(){

	try
	{
		test01();
	}
	catch (double)
	{
		cout << "double������ double�����쳣����" << endl;
	}
	catch (...)
	{
		cout << "main������ ���������쳣����" << endl;
	}

	


	system("pause");
	return EXIT_SUCCESS;
}