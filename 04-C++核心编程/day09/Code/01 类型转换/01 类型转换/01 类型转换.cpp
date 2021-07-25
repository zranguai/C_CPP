#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1����̬����ת��  static_cast
void test01()
{
	//����������������֮��ת��
	char a = 'a';

	double d = static_cast<double>(a);

	cout << d << endl;

}

class Base{ virtual void func(){} };
class Son :public Base{ virtual void func(){} };
class Other{};

void test02()
{
	Base * base = NULL;
	Son * son = NULL;

	//�﷨��   static_cast<Ŀ������>(ԭ����)
	//����֮���ָ��������ÿ���ת��
	//��base תΪ Son *   ��ת��  ��������ת��  ����ȫ
	Son * son2 = static_cast<Son *> (base);

	//son  תΪ Base*    ��ת��  ��������ת��  ��ȫ
	Base * base2 = static_cast<Base*>(son);


	//base תΪOther*
	//Other * other = static_cast<Other*>(base);  ת����Ч

}


//��̬����ת��  dynamic_cast
void test03()
{
	//������������������֮��ת��
	//char c = 'c';
	//double d = dynamic_cast<double>(c);
}

void test04()
{
	Base * base = new Son;
	Son * son = NULL;

	//��base תΪ Son *  ��ת�� ����ȫ  ��������˶�̬����ôת�����ǰ�ȫ��
	Son * son2 = dynamic_cast<Son*>(base);


	//son תΪ Base*  ��ת��  ��ȫ
	Base * base2 = dynamic_cast<Base*>(son);

	//base ת Other*
	//Other* other = dynamic_cast<Other*>(base); //�޷�ת��
}

//����ת��  const_cast
void test05()
{
	//�����Խ���ָ����������const_castת��
	const int * p = NULL;
	int * pp = const_cast<int*>(p);

	const int * ppp =  const_cast<const int *>(pp);


	//const int a = 10;
	//int b = const_cast<int>(a);


	int num = 10;
	int &numRef = num;

    const int& num2 = const_cast<const int&>(numRef);

}

//���½���ת��  reinterpret_cast ���ȫһ��ת����������ʹ��
void test06()
{
	int a = 10;
	int * p = reinterpret_cast<int*>(a);

	Base * base = NULL;
	//base ת Other *
	Other * other = reinterpret_cast<Other *>(base);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}