#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ڵ�Ľṹ��
struct LinkNode
{
	int num; //������
	struct LinkNode * next; //ָ����
};

void test01()
{
	//�����ڵ�
	struct LinkNode node1 = { 10, NULL };
	struct LinkNode node2 = { 20, NULL };
	struct LinkNode node3 = { 30, NULL };
	struct LinkNode node4 = { 40, NULL };
	struct LinkNode node5 = { 50, NULL };

	//������ϵ
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	//��������
	struct LinkNode * pCurrent = &node1;

	while (pCurrent != NULL)
	{
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}


}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}