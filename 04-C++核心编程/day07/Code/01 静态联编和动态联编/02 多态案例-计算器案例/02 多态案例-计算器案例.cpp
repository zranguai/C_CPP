#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <string>

//class calculator
//{
//public:
//
//	int getResult( string oper)
//	{
//		if (oper == "+")
//		{
//			return m_A + m_B;
//		}
//		else if (oper == "-")
//		{
//			return m_A - m_B;
//		}
//		else if (oper == "*")
//		{
//			return m_A * m_B;
//		}
//		
//	}
//
//	int m_A;
//	int m_B;
//};

//���ԭ�� �� ����ԭ��
// ����չ���п���  ���޸Ľ��йر�

//���ö�̬ʵ�ּ�����
class AbstractCalculator
{
public:

	//���麯��
	//���һ�����а����˴��麯������ô�������޷�ʵ����������,�����ͨ�����ǳ�Ϊ ������
	//����������� ����Ҫ��д �����еĴ��麯��������Ҳ���ڳ�����
	virtual int getResult() = 0;

	//virtual int getResult()
	//{
	//	return 0;
	//}

	int m_A;
	int m_B;
};
//�ӷ�������
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A + m_B;
	}
};

//����������
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A - m_B;
	}
};

//�˷�������
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult()
	{
		return m_A * m_B;
	}
};

class Test :public AbstractCalculator
{
	int getResult(){ return 0; };
};

void test01()
{
	//calculator c;
	//c.m_A = 10;
	//c.m_B = 10;
	//cout << c.getResult("+") << endl;


	AbstractCalculator * calculator = new AddCalculator;

	calculator->m_A = 100;
	calculator->m_B = 200;

	cout << calculator->getResult() << endl;

	delete calculator;

	calculator = new SubCalculator;
	calculator->m_A = 100;
	calculator->m_B = 200;

	cout << calculator->getResult() << endl;

}

int main(){

	//test01();

	//AbstractCalculator abc;   ���������޷�ʵ���������
	//Test t; //�������д����Ĵ��麯�� ��Ҳ�޷�ʵ��������

	system("pause");
	return EXIT_SUCCESS;
}