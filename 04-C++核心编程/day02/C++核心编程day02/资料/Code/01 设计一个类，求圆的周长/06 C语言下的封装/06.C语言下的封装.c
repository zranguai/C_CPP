#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Person
{
	char  name[64];
	int age;
};

void PersonEat(struct Person * p)
{
	printf("%s�ڳ��˷�\n",p->name);
}

void test01()
{
	struct Person p;
	strcpy(p.name, "����");
	p.age = 10;

	PersonEat(&p);
}


struct Dog
{
	char name[64];
	int age;
};

void DogEat(struct Dog * dog)
{
	printf("%s�ڳԹ���\n", dog->name);
}

void test02()
{
	struct Dog d;
	strcpy(d.name, "����");
	d.age = 100;

	DogEat(&d);


	struct Person p;
	strcpy(p.name, "����");

	DogEat(&p);

}



int main(){
//	test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}