#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1������ģ�����ͨ����������
template<class T>
T myAdd(T a , T b)
{
	return a + b;
}

int myAdd2(int a, int b)
{
	return a + b;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//myAdd(a, c); //���ʹ���Զ������Ƶ����ǲ����Է�����ʽ����ת����

	cout << myAdd2(a, c) << endl; //��ͨ���� ���Է�����ʽ����ת��
}


//2������ģ�����ͨ�����ĵ��ù���
template<class T>
void myPrint(T a ,T b)
{
	cout << "����ģ�����" << endl;
}

/*
����ģ��ͨ���������Ͳ�����ͬ�ĺ���  --- ͨ������ģ������ĺ���  ��Ϊ ģ�庯��
void myPrint(int a ,int b)
{
cout << "����ģ�����" << endl;
}

void myPrint(double a ,double b)
{
cout << "����ģ�����" << endl;
}
*/

template<class T>
void myPrint(T a, T b ,T c)
{
	cout << "����ģ��(T a, T b ,T c)����" << endl;
}

void myPrint(int a, int b)
{
	cout << "��ͨ��������" << endl;
}



void test02()
{
	//1���������ģ�����ͨ���������Ե��ã���ô���ȵ�����ͨ����
	int a = 10;
	int b = 20;
	//myPrint(a, b);

	//2�������ǿ�Ƶ��ú���ģ�壬����ʹ�ÿ�ģ������б�
	myPrint<>(a, b);

	//3������ģ��Ҳ���Է�����������
	myPrint(a, b, 10);

	//4���������ģ���ܲ������õ�ƥ�䣬��ô����ʹ�ú���ģ��
	char c = 'c';
	char d = 'd';
	myPrint(c, d);

}

int main(){

	//test01();

	test02();

	system("pause");
	return EXIT_SUCCESS;
}