#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Person
{
public: //�������������Ҫ������ȫ��������

	//���캯��
	//û�з���ֵ  ����дvoid
	//������ �� ������ͬ
	//�����в���  �����Է�������
	//���캯�� �ɱ������Զ�����һ�� �����ֶ�����
	Person()
	{
		cout << "Person�Ĺ��캯������" << endl;
	}
	

	//��������
	//û�з���ֵ   ����дvoid
	//������ ��������ͬ  ������ǰ �� ~
	//�������в��� �������Է�������
	//�������� Ҳ���ɱ������Զ�����һ�Σ������ֶ�����
	~Person()
	{
		cout << "Person��������������" << endl;
	}

};

void test01()
{
	Person p;

}

int main(){

	test01();

	

	system("pause");
	return EXIT_SUCCESS;
}