#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

class MyPrint
{
public:
	void operator()(string text)
	{
		cout << text << endl;
	}
};


void MyPrint2(string str)
{
	cout << str << endl;
}

void test01()
{
	MyPrint myPrint;
	myPrint("hello world"); // �º���  ������һ������   ��������

	MyPrint2("hello world"); //��ͨ����
}



class MyAdd
{
public:
	int operator()(int a,int b)
	{
		return a + b;
	}
};

void test02()
{
	MyAdd myAdd;
	cout << myAdd(1, 1) << endl;


	cout << MyAdd()(1, 1) << endl; // ������������ �ص㣺��ǰ��ִ���������ͷ�
}

int main(){

	//test01();
	test02();


	system("pause");
	return EXIT_SUCCESS;
}