#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//��ȱ��1 �� ����Ҫ�����ű�֤��������
#define  MYADD(x,y)  ((x) +(y))
void test01()
{
	int a = 10;
	int b = 20;
	int ret = MYADD(a, b) * 20;
	cout << ret << endl;
}

//��ȱ��2��  ��ʹ�������ţ���Щ������Ȼ��Ԥ�ڲ���

#define MYCOMPARE(a,b)  (((a) < (b)) ? (a) : (b))

//��ͨ���� ���������Ԥ�ڽ������������
void myCompare(int a, int b)
{
	int ret = a < b ? a : b;
	cout << "ret = " << ret << endl;
}

void test02()
{
	int a = 10;
	int b = 20;

	myCompare(++a, b);

	//int ret = MYCOMPARE(++a, b); //Ԥ���� 11 �����Ϊ12   (((++a) < (b)) ? (++a) : (b))

	//cout << "ret = " << ret << endl;

}


//��������
//������������ʵ�ֱ���ͬʱ�ӹؼ��� inline  ������������
//�������� �ô�  �������ȱ�ݣ�������һ�����������������ƣ��Կռ任ʱ�䣬���ʵ���ʱ����չ��
inline void func();
inline void func(){};
//���ڲ��ĳ�Ա���� �ں���ǰ����ʽ���˹ؼ��� inline


int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}