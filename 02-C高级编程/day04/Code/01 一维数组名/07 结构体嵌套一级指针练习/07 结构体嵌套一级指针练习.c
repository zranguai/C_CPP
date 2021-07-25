#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
	char * name;
	int age;
};

struct Person ** allocateSpace()
{
	struct Person ** temp = malloc(sizeof(struct Person *) * 3);

	for (int i = 0; i < 3;i++)
	{
		//�����ṹ���ڴ�
		temp[i] = malloc(sizeof(struct Person));

		//���ṹ������ �����ڶ��� 
		temp[i]->name = malloc(sizeof(char)* 64);

		//��������ֵ
		sprintf(temp[i]->name, "name_%d", i + 1);

		temp[i]->age = 18 + i;
	}


	return temp;
}

void printPerson(struct Person ** pArray, int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("������ %s ���䣺 %d\n", pArray[i]->name, pArray[i]->age);
	}


}

void freeSpace(struct Person ** pArray , int len)
{
	if ( pArray == NULL)
	{
		return;
	}
	if (len <= 0)
	{
		return;
	}

	for (int i = 0; i < 3;i++)
	{
		if (pArray[i]->name != NULL)
		{
			printf("%s���ͷ���\n", pArray[i]->name);
			free(pArray[i]->name);
			pArray[i]->name = NULL;
		}

		free(pArray[i]);
		pArray[i] = NULL;
	}

	free(pArray);
	pArray = NULL;
}

void test01()
{
	struct Person ** pArray = NULL;

	pArray = allocateSpace();


	//��ӡ����
	printPerson(pArray, 3);

	//�ͷ��ڴ�
	freeSpace(pArray,3);
	pArray = NULL;
}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}