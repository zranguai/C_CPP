#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct LinkNode
{
	int num;
	struct LinkNode * next;
};

void test01()
{
	//�����ڵ�
	struct LinkNode * node1 = malloc(sizeof(struct LinkNode));
	struct LinkNode * node2 = malloc(sizeof(struct LinkNode));
	struct LinkNode * node3 = malloc(sizeof(struct LinkNode));
	struct LinkNode * node4 = malloc(sizeof(struct LinkNode));
	struct LinkNode * node5 = malloc(sizeof(struct LinkNode));

	//��������ֵ
	node1->num = 100;
	node2->num = 200;
	node3->num = 300;
	node4->num = 400;
	node5->num = 500;

	//������ϵ
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	//��������
	struct LinkNode * pCurrent = node1;
	while (pCurrent!=NULL)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}

	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	node1 = NULL;
	node2 = NULL;
	node3 = NULL;
	node4 = NULL;
	node5 = NULL;
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}