#include "circle.h"


//Բ��

//���ð뾶
void Circle::setR(int r)
{
	m_R = r;
}
//��ȡ�뾶
int Circle::getR()
{
	return m_R;
}

//����Բ��
void Circle::setCenter(Point p)
{
	m_Center = p;
}

//��ȡԲ��
Point Circle::getCenter()
{
	return m_Center;
}

//�жϵ��Բ��ϵ
void Circle::isInCircleByClass(Point p)
{

	int distance = (m_Center.getX() - p.getX())*(m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY()) *(m_Center.getY() - p.getY());

	int rDistance = m_R * m_R;

	if (distance == rDistance)
	{
		cout << "��Ա�����жϣ�����Բ��" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "��Ա�����жϣ�����Բ��" << endl;
	}
	else
	{
		cout << "��Ա�����жϣ�����Բ��" << endl;
	}
}

