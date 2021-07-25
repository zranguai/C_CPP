#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ṩһ����ӡ���������Դ�ӡ�������͵�����
void printText( void * data , void(*myPrint)(void *) )
{
	myPrint(data);

}



void myPrintInt(void * data)
{
	int * num = data;
	printf("%d\n", *num);
}

void test01()
{
	int a = 10;
	printText(&a, myPrintInt);
}


struct Person
{
	char name[64];
	int age;
};

void myPrintPerson(void * data)
{
	struct Person * p = data;
	printf("������ %s ���䣺 %d\n", p->name, p->age);
}

void test02()
{
	struct Person p = { "Tom", 18 };

	printText(&p, myPrintPerson);

}

int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}