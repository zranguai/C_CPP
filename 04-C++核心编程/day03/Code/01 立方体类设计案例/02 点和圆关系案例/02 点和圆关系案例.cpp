#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "circle.h"
#include "point.h"
/*
���һ��Բ���ࣨAdvCircle������һ�����ࣨPoint����������Բ�Ĺ�ϵ��
����Բ������Ϊx0, y0, �뾶Ϊr���������Ϊx1, y1��
*/

////����
//class Point
//{
//public:
//
//	//���� x ��y
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//��ȡ x ��y
//	int getX()
//	{
//		return m_X;
//	}
//	int getY()
//	{
//		return m_Y;
//	}
//private:
//	int m_X;
//	int m_Y;
//};

//
////Բ��
//class Circle
//{
//public:
//	//���ð뾶
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//��ȡ�뾶
//	int getR()
//	{
//		return m_R;
//	}
//
//	//����Բ��
//	void setCenter(Point p)
//	{
//		m_Center = p;
//	}
//
//	//��ȡԲ��
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//	//�жϵ��Բ��ϵ
//	void isInCircleByClass(Point p)
//	{
//
//		int distance = (m_Center.getX() - p.getX())*(m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY()) *(m_Center.getY() - p.getY());
//
//		int rDistance = m_R * m_R;
//
//		if (distance == rDistance)
//		{
//			cout << "��Ա�����жϣ�����Բ��" << endl;
//		}
//		else if (distance > rDistance)
//		{
//			cout << "��Ա�����жϣ�����Բ��" << endl;
//		}
//		else
//		{
//			cout << "��Ա�����жϣ�����Բ��" << endl;
//		}
//	}
//
//private:
//
//	int m_R; //�뾶
//
//	Point m_Center; // Բ��
//};

//����ȫ�ֺ��� �жϵ��Բ��ϵ
void isInCircle( Circle c , Point p )
{

	int distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) *(c.getCenter().getY() - p.getY());

	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}

}

void test01()
{
	Point p;
	p.setX(10);
	p.setY(9);

	Circle c;
	Point pCenter;
	pCenter.setX(10);
	pCenter.setY(0);
	c.setCenter(pCenter);
	c.setR(10);

	isInCircle(c, p);

	c.isInCircleByClass(p);

}


class A
{
	virtual void func() = 0;
};
class B :public A
{

};
class C :public B
{
};

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}