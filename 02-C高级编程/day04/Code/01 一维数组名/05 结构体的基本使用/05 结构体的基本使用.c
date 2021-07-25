#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//struct Person
//{
//	char name[64];
//	int age;
//};
//typedef struct Person myPerson;

typedef struct Person
{
	char name[64];
	int age;
}myPerson;

void test01()
{
	struct Person p = { "Tom", 18 };
	myPerson p2 = { "Jerry", 20 };
}


struct Person2
{
	char name[64];
	int age;
}myPerson2 = { "aaa", 20 };

void test02()
{
	printf("����:%s ����%d\n", myPerson2.name, myPerson2.age);
}

//�����ṹ��
struct 
{
	char name[64];
	int age;
}myPerson3 = { "bbb", 30 };

void test03()
{
	printf("����:%s ����%d\n", myPerson3.name, myPerson3.age);
}

//�ṹ�崴��
void test04()
{
	//������ջ��
	struct Person p = { "aaa", 10 };

	printf("������%s  ���䣺 %d\n", p.name, p.age);

	//�����ڶ���
	struct Person * p2 = malloc(sizeof(struct Person));
	strcpy(p2->name, "bbb");
	p2->age = 20;

	printf("������%s  ���䣺 %d\n", p2->name, p2->age);

	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
}


void printArray( struct Person personArray[]  ,int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("���� �� %s ������ : %d \n", personArray[i].name, personArray[i].age);
	}
}
//�ṹ��������鴴��
void test05()
{
	//��ջ�Ϸ����ڴ�
	struct Person persons[] =
	{
		{ "aaa", 10 },
		{ "bbb", 20 },
		{ "ccc", 30 },
		{ "ddd", 40 },
	};
	int len = sizeof(persons) / sizeof(struct Person);
	//printArray(persons, len);


	//�ڶ��������ڴ�
	struct Person * pArray = malloc(sizeof(struct Person) * 4);
	for (int i = 0; i < 4;i++)
	{
		sprintf(pArray[i].name, "name_%d", i + 1);
		pArray[i].age = 18 + i;
	}
	
	printArray(pArray, 4);

	if (pArray != NULL)
	{
		free(pArray);
		pArray = NULL;
	}

}


int main(){
	//test02();
	//test03();
	//test04();
	test05();


	system("pause");
	return EXIT_SUCCESS;
}