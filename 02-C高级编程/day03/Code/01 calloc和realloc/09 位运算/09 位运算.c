#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��λȡ�� ~
void test01()
{
	int num = 2;

	// 010 ȡ��
	// 101 Դ��
	//������ò��뷽ʽ������  110 + 1      =  111

	printf("~num = %d\n", ~num); // -3

}

//��λ�� &
void test02()
{
	int num = 123;
	if (  (num & 1 ) == 1 )
	{
		printf("numΪ����\n");
	}
	else
	{
		printf("numΪż��\n");
	}

}

//��λ�� |
void test03()
{
	int num1 = 5;
	int num2 = 3;
	printf("num1 | num2 =  %d\n", num1 | num2); // 7

}

//��λ���  ^
void test04()
{
	int num1 = 5;
	int num2 = 9;

	/*int tmp = num1;
	num1 = num2;
	num2 = tmp;*/

	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;


	//num1 = num1 + num2;
	//num2 = num1 - num2;
	//num1 = num1 - num2;


	printf("num1 = %d\n", num1);
	printf("num2 = %d\n", num2);

}

//�������� << 
void test05()
{
	int num = 20;  // 20 * 2 ^ 2;
	printf("%d\n", num <<= 2);
}
//�������� >>
void test06()
{
	int num = 20;  // 20 / 2
	printf("%d\n", num >>= 1);
}

int main(){

	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	test06();
	system("pause");
	return EXIT_SUCCESS;
}