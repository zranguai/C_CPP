#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�ڵ�ṹ��
struct LinkNode
{
	//ֻά��ָ����
	struct LinkNode*next;
};

//����ṹ��
struct LList
{
	struct LinkNode pHeader;
	int m_Size;
};

typedef void * LinkList;

//��ʼ������
LinkList init_LinkList()
{
	struct LList * myList = malloc(sizeof(struct LList));

	if (myList == NULL)
	{
		return NULL;
	}

	myList->pHeader.next = NULL;
	myList->m_Size = 0;

	return myList;
}

//����
void insert_LinkList(LinkList list ,  int pos , void * data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LList * myList = list;
	if (pos < 0 || pos >myList->m_Size - 1)
	{
		//��Чλ�ý���β��
		pos = myList->m_Size;
	}

	//�û�����ǰ4���ֽ� ��������ʹ��
	struct LinkNode * myNode = data;

	//�Ҳ���ڵ��ǰ���ڵ�
	struct LinkNode * pCurrent = &myList->pHeader;

	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}
	//pCurrent��ǰ���ڵ�λ��


	//����ָ��ָ��
	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	//����������
	myList->m_Size++;
}

//��������
void foreach_LinkList(LinkList list, void(*myForeach)(void *))
{
	if (list == NULL)
	{
		return;
	}

	struct LList * myList = list;

	struct LinkNode * myNode = myList->pHeader.next;

	for (int i = 0; i < myList->m_Size;i++)
	{
		myForeach(myNode);
		myNode = myNode->next;
	}

}

//ɾ���ڵ� ��λ��ɾ��
void removeByPos_ListList( LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}

	struct LList * mylist = list;

	if (pos < 0 ||  pos > mylist->m_Size - 1)
	{
		return;
	}

	//�Ҵ�ɾ���ڵ��ǰ��λ��
	struct LinkNode * pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos;i++)
	{
		pCurrent = pCurrent->next;
	}

	//��¼��ɾ���ڵ�
	struct LinkNode * pDel = pCurrent->next;


	//����ָ��ָ��
	pCurrent->next = pDel->next;

	//free(pDel); //�������û������ٵģ��û������ͷ�

	//���³���
	mylist->m_Size--;
}

//��������
void destroy_LinkList( LinkList list)
{
	if (list == NULL)
	{
		return;
	}

	free(list);
	list = NULL;

}






//����

struct Person
{
	void * node;
	char name[64];
	int age;
};


void myPrintPerson(void * data)
{
	struct Person * p = data;
	printf("������ %s  ���䣺 %d \n", p->name, p->age);
}

void test01()
{

	//��ʼ������
	LinkList mylist = init_LinkList();

	//��������
	struct Person p1 = { NULL,"aaa", 10 };
	struct Person p2 = { NULL,"bbb", 20 };
	struct Person p3 = { NULL,"ccc", 30 };
	struct Person p4 = { NULL,"ddd", 40 };
	struct Person p5 = { NULL,"eee", 50 };

	//����ڵ�
	insert_LinkList(mylist, 0, &p1);
	insert_LinkList(mylist, 0, &p2);
	insert_LinkList(mylist, 1, &p3);
	insert_LinkList(mylist, -1, &p4);
	insert_LinkList(mylist, 0, &p5);


	//��������
	// eee bbb  ccc aaa ddd
	foreach_LinkList(mylist, myPrintPerson);

	//ɾ�� aaa
	removeByPos_ListList(mylist, 3);
	printf("-----------------------\n");
	foreach_LinkList(mylist, myPrintPerson);

	//��������
	destroy_LinkList(mylist);
	mylist = NULL;

}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}