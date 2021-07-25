#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student {
	int age;
	char *name;  // char name[10];  // ջ
	int num;
};

void init_struct(struct student **p)
{
	*p = malloc(sizeof(struct student));	// ���������
	if (*p == NULL) {
		printf("malloc error");
		return ;
	}
	(*p)->age = 10;
	(*p)->name = malloc(sizeof(char)*10);	// �������ڲ�
	strcpy((*p)->name, "hello");
	(*p)->num = 100;
}

int main0503(void)
{
	struct student *p = NULL;
	p = malloc(sizeof(struct student));		// ���������ռ�

	p->age = 100;
	p->name = malloc(sizeof(char)*10);		// �������ڲ�ռ�
	strcpy(p->name, "world");
	p->num = 20;

	printf("age = %d, name=%s, num = %d\n", p->age, p->name, p->num);

	free(p->name);  // ���ͷ��ڲ�
	free(p);		// ���ͷ����

	system("pause");
	return EXIT_SUCCESS;
}

int main0502(void)
{
	struct student *p = NULL;

	init_struct(&p);
	printf("age = %d, name=%s, num = %d\n", p->age, p->name, p->num);

	free(p->name);  // ���ͷ��ڲ�
	free(p);		// ���ͷ����

	system("pause");
	return EXIT_SUCCESS;
}

int main0501(void)
{
	struct student stu;
	stu.age = 19;

	stu.name = malloc(sizeof(char) * 10);  // ��

	strcpy(stu.name, "andy");  // stu.name  �� Ұָ�롣

	stu.num = 10;

	printf("age = %d, name= %s, num= %d\n", stu.age, stu.name, stu.num);

	free(stu.name);
	stu.name = NULL;

	system("pause");
	return EXIT_SUCCESS;
}
