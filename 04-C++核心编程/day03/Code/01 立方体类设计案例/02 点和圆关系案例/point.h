#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//����
class Point
{
public:

	//���� x ��y
	void setX(int x);

	void setY(int y);

	//��ȡ x ��y
	int getX();

	int getY();

private:
	int m_X;
	int m_Y;
};

