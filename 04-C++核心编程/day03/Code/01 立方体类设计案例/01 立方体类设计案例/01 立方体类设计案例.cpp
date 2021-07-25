#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


/*
�����������(Cube)���������������( 2*a*b + 2*a*c + 2*b*c )�����( a * b * c)��
�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ���ȡ�
*/

class Cube
{
public:
	//���ó����
	void setL(int l)
	{
		m_L = l;
	}
	void setW(int w)
	{
		m_W = w;
	}
	void setH(int h)
	{
		m_H = h;
	}
	//��ȡ�����
	int getL()
	{
		return m_L;
	}
	int getW()
	{
		return m_W;
	}
	int getH()
	{
		return m_H;
	}

	//����� 
	int calculateS()
	{
		return 2 * m_L*m_W + 2 * m_W*m_H + 2 * m_L*m_H;
	}

	//�����
	int calculateV()
	{
		return m_L * m_W * m_H;
	}

	//���ó�Ա���� �ж��������Ƿ����
	bool compareCubeByClass( Cube &c )
	{
		return m_L == c.getL() &&  m_W == c.getW() && m_H == c.getH();
	}

	
private:
	int m_L; //��
	int m_W; //��
	int m_H; //��
};


//����ȫ�ֺ��� �ж������������Ƿ����
bool compareCube( Cube &c1, Cube &c2 )
{
	/*if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
	{
	return true;
	}
	return false;*/

	return c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH();
}

void test01()
{
	Cube c1;
	c1.setL(10);
	c1.setW(10);
	c1.setH(10);

	cout << "c1���Ϊ�� " << c1.calculateS() << endl; //600
	cout << "c1���Ϊ�� " << c1.calculateV() << endl; //1000

	Cube c2;
	c2.setL(10);
	c2.setW(10);
	c2.setH(10);

	//����ȫ�ֺ����ж� c1 �� c2�Ƿ����

	bool ret = compareCube(c1, c2);
	if (ret)
	{
		cout << "c1 �� c2 ���" << endl;
	}
	else
	{
		cout << "c1 �� c2 �����" << endl;
	}


	//���ó�Ա���� �ж�  c1 �� c2�Ƿ����
	ret = c1.compareCubeByClass(c2);
	if (ret)
	{
		cout << "��Ա�����жϣ�c1 �� c2 ���" << endl;
	}
	else
	{
		cout << "��Ա�����жϣ�c1 �� c2 �����" << endl;
	}

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}