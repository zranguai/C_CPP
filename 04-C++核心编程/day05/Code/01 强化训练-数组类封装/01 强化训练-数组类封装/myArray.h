#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


class MyArray
{
public:

	MyArray(); //Ĭ�Ϲ��� ���Ը�100����

	MyArray(int capacity); //�вι���

	MyArray(const MyArray & arr); //��������

	//β�巨
	void pushBack(int val);

	//����λ����������
	void setData(int pos, int val);

	//����λ�û�ȡ����
	int getData(int pos);

	//��ȡ��������
	int getCapcity();

	//��ȡ�����С
	int getSize();

	//����
	~MyArray();

	//����[]�����
	int& operator[](int index);
	

private:
	int m_Capacity; //��������
	int m_Size; //�����С
	int *pAddress; //��ʵ�ڶ������ٵ������ָ��
};

