#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(char * str)
	{
	
	}
	//explicit��;�� ��ֹ������ʽ����ת����ʽ���������
	explicit MyString(int len)
	{
		
	}
};

void test01()
{


	MyString str1(10);

	MyString str2 = MyString(100);

	//MyString str3 = 10; // "10"

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}