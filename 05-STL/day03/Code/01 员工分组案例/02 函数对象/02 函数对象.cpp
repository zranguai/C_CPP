#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyPrint
{
public:
	void operator()(int num)
	{
		cout << num << endl;
		m_Count++;
	}

	int m_Count = 0;
};

void myPrint02(int num)
{
	cout << num << endl;
}

void test01()
{
	MyPrint myPrint;
	myPrint(100); //������һ����Ķ�����˳�Ϊ��������Ҳ�зº���

	myPrint02(100);
}


void test02()
{
	//�������� ��������ͨ�����ĸ������ӵ���Լ�״̬

	MyPrint myPrint;
	myPrint(100);
	myPrint(100);
	myPrint(100);
	myPrint(100);

	cout << "���ô���Ϊ�� " << myPrint.m_Count << endl;
}


//�������������Ϊ��������
void doPrint(MyPrint myPrint , int num)
{
	myPrint(num);
}

void test03()
{
	doPrint(MyPrint(), 1000);
}

int main(){

	//test01();
	//test02();
	test03();

	system("pause");
	return EXIT_SUCCESS;
}