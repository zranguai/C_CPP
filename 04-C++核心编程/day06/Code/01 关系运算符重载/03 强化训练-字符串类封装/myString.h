#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
	//�����������Ԫ
	friend ostream& operator<<(ostream & cout, MyString & str);
	//��������� ��Ԫ
	friend istream&  operator>>(istream & cin, MyString & str);
public:

	//�вι���
	MyString(char  * str);
	//��������
	MyString(const MyString & str);

	//����=����� 

	MyString& operator=(const char * str);
	MyString& operator=(const MyString & str);

	//����[]�����
	char& operator[](int index);

	//����+�����
	MyString operator+(const char * str);
	MyString operator+(const MyString&str);

	//����==����� 
	bool operator==(const char *str);
	bool operator==(const MyString &str);

	//����
	~MyString();

private:

	char * pString; //ά���ڶ������ٵ��ַ�����

	int m_Size; //�ַ������� ��ͳ��\0

};