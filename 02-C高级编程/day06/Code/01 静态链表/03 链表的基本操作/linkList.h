#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct LinkNode
{
	int num;
	struct LinkNode * next;
};

//��ʼ������
struct LinkNode * initLinkList();

//��������
void foreach_LinkList(struct LinkNode * pHeader);

//��������
void insert_LinkList(struct LinkNode * pHeader, int oldVal, int newVal);

//ɾ������
void delete_LinkList(struct LinkNode * pHeader, int val);

//�������
void clear_LinkList(struct LinkNode * pHeader);

//��������
void destroy_LinkList(struct LinkNode * pHeader);