#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	//int &ref = 10;

	const int &ref = 10; // ����const֮��  �൱��д��   int temp = 10;  const int &ref = temp;

	int *p = (int *)&ref;
	*p = 10000;

	cout << ref << endl;
}

void showValue(const int &a)
{
	//a = 100000;

	cout << "a = " << a << endl;

}
//�������õ�ʹ�ó��� ���κ����е��βΣ���ֹ�����
void test02()
{
	int a = 100;
	showValue(a);

}

int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}