#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void func(int a ,char c)
{
	printf("hello world\n");
}

void test01()
{
	//1���ȶ�����������ͣ���ͨ�����Ͷ��庯��ָ��
	typedef void(FUNC_TYPE)(int, char);

	FUNC_TYPE * pFunc = func;
	//pFunc(10, 'a');

	//2�����������ָ�����ͣ�ͨ�����Ͷ��庯��ָ�����
	typedef void( * FUNC_TYPE2)(int, char);

	FUNC_TYPE2 pFunc2 = func;
	//pFunc2(20, 'b');


	//3��ֱ�Ӷ��庯��ָ�����
	void(*pFunc3)(int, char) = func;
	pFunc3(30, 'c');

	//����ָ�� �� ָ�뺯�� ����
	//����ָ��  ָ���˺�����ָ��
	//ָ�뺯��  ��������ֵ��ָ��ĺ���
}


//����ָ�������
void func1()
{
	printf("func1 ������\n");
}

void func2()
{
	printf("func2 ������\n");
}

void func3()
{
	printf("func3 ������\n");
}

void test02()
{
	void(*pArray[3])(); 

	pArray[0] = func1;
	pArray[1] = func2;
	pArray[2] = func3;

	for (int i = 0; i < 3;i++)
	{
		pArray[i]();
	}
}

int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}