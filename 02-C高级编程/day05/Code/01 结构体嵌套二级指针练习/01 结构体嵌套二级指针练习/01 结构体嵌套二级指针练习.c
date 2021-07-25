#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Teacher
{
	char * name;
	char ** students;
};

void allocateSpace(struct Teacher*** teachers)
{
	if (teachers == NULL)
	{
		return;
	}

	//�����ڴ�
	struct Teacher ** ts =  malloc(sizeof(struct Teacher *) * 3);

	//��ÿ����ʦ�����ڴ�
	for (int i = 0; i < 3;i++)
	{
		ts[i] = malloc(sizeof(struct Teacher));


		//����ʦ�����������ڴ�
		ts[i]->name = malloc(sizeof(char)* 64);

		//����ʦ������
		sprintf(ts[i]->name, "Teacher_%d", i + 1);


		//��ѧ������������ڴ�
		ts[i]->students = malloc(sizeof(char *)* 4);

		//��ѧ�������������ڴ� �Լ���ֵ
		for (int j = 0; j < 4;j++)
		{
			ts[i]->students[j] = malloc(sizeof(char)* 64);
			sprintf(ts[i]->students[j], "%s_Student_%d", ts[i]->name, j + 1);
		}
	}

	*teachers = ts;
}

void printTeachers(struct Teacher** pArray)
{
	if (pArray == NULL)
	{
		return;
	}

	for (int i = 0; i < 3;i++)
	{
		printf("%s\n", pArray[i]->name);
		for (int j = 0; j < 4;j++)
		{
			printf("      %s\n", pArray[i]->students[j]);
		}
	}

}

void freeSpace(struct Teacher ** pArray)
{
	if (pArray == NULL)
	{
		return;
	}

	for (int i = 0; i < 3;i++)
	{
		//���ͷ���ʦ����
		if (pArray[i]->name != NULL)
		{
			free(pArray[i]->name);
			pArray[i]->name = NULL;
		}

		//�ͷ�ѧ������
		for (int j = 0; j < 4;j++)
		{
			if (pArray[i]->students[j] != NULL)
			{
				free(pArray[i]->students[j]);
				pArray[i]->students[j] = NULL;
			}
		}
		//�ͷ�ѧ��������
		if (pArray[i]->students != NULL)
		{
			free(pArray[i]->students);
			pArray[i]->students = NULL;
		}

		//�ͷ���ʦ
		if (pArray[i] != NULL)
		{
			free(pArray[i]);
			pArray[i] = NULL;
		}

	}


	//�ͷ���ʦ����
	if (pArray != NULL)
	{
		free(pArray);
		pArray = NULL;
	}

}

void test01()
{
	struct Teacher ** pArray = NULL;
	//�����ڴ�
	allocateSpace(&pArray);

	//��ӡ����
	printTeachers(pArray);

	//�ͷ�����
	freeSpace(pArray);
	pArray = NULL;

}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}