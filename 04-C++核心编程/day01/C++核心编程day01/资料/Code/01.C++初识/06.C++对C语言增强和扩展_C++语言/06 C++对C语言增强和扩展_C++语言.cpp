#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1��ȫ�ֱ��������ǿ  C++�����ض���
int a;
//int a = 10;

//2�����������ǿ ����ֵ��⡢�β����ͼ�⡢�������ò�������
int getRectS(int w,int h)
{

	return w *h;
}
void test01()
{
	printf("%d\n", getRectS(10, 10));
}


//3������ת�������ǿ
void test02()
{
	char * p = (char *)malloc(64);
}

//4��struct��ǿ  C++���Էź����������ṹ����������Լ򻯹ؼ��� struct
struct Person
{
	int age;
	void func()
	{
		age++;
	}
};

void test03()
{
	Person p;
	p.age = 17;
	p.func();
	cout << "p��age = " << p.age << endl;
}

//5��bool������չ  C������ û���������  C++��bool����
bool flag = true; // bool���� ����  ��ͼ�   true  ---- ��(1)    false  ---- ��(0)

void test04()
{
	cout << sizeof(bool) << endl; //�����1���ֽ�
	//flag = false;
	//flag = 100; //����0������תΪ1
	cout << flag << endl;
}

//6����Ŀ�������ǿ
void test05()
{
	//?:
	int a = 10;
	int b = 20;

	printf("ret = %d\n", a > b ? a : b);

	(a < b ? a : b )= 100; // C++�·��ص��Ǳ���  b = 100

	printf("a = %d\n", a);
	printf("b = %d\n", b);
}


//7��const��ǿ
//ȫ��const   ��C���Խ���һ��
const int m_A = 100;
void test06()
{
	//m_A = 200;
	//int * p = (int *)&m_A;

	//*p = 200;


	//�ֲ�const
	const int m_B = 100;
	//m_B = 200;
	int * p = (int *)&m_B;
	*p = 200;
	cout << "m_B = " << m_B << endl;

	int arr[m_B]; //C++��const���εı��� ��Ϊ���� �����Գ�ʼ������

}


int main(){
	//test01();
	//test03();
	//test04();
	//test05();
	test06();


	system("pause");
	return EXIT_SUCCESS;
}