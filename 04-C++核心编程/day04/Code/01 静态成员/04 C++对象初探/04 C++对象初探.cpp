#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//#pragma pack(1)

class Person
{
public:

	int m_A; //ֻ�зǾ�̬��Ա����  �����������

	void func( )  //��Ա����  ���������������
	{
		
	}

	static int m_B; //��̬��Ա����  �������������

	static void func2()//��̬��Ա����  �������������
	{
		
	}

	double m_C;

};
int Person::m_B = 0;

void test01()
{
	//�����sizeof�����1  ԭ��  ÿ������Ӧ�����ڴ����ж�һ�޶��ĵ�ַ����˸��ն������1���ֽڿռ�
	// Person pArr[10]  pArr[0]  pArr[1]
	Person p1;
	//  �ն��� ��С 1  
	cout << "sizeof = " << sizeof(p1) << endl;

}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}