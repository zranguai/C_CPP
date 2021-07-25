#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//�쳣�Ļ���
class BaseException
{
public:
	virtual void printError() = 0;
};

//��ָ���쳣
class NULLPointerException :public BaseException
{
public:
	virtual void printError()
	{
		cout << "��ָ���쳣" << endl;
	}
};

//Խ���쳣
class OutOfRangeException :public BaseException
{
public:
	virtual void printError()
	{
		cout << "Խ���쳣" << endl;
	}

};

void doWork()
{
	//throw NULLPointerException();
	throw OutOfRangeException();
}

void test01()
{
	try
	{
		doWork();
	}
	catch (BaseException & e)
	{
		e.printError();
	}
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}