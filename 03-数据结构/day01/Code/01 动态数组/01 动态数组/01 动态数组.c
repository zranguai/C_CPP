#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "dynamicArray.h"

////��̬����ṹ��
//struct dynamicArray
//{
//	void ** pAddr; //ά����ʵ�ڶ��������������ָ��
//
//	int m_capacity;  // ��������
//
//	int m_size;   //�����С
//};
//
//
////��ʼ������
//struct dynamicArray * init_DynamicArray(int capacity)
//{
//	if (capacity <= 0)
//	{
//		return NULL;
//	}
//
//	//���������ռ�
//
//	struct dynamicArray * array  = malloc(sizeof(struct dynamicArray));
//	if (array == NULL)
//	{
//		return NULL;
//	}
//
//	//�������ʼ��
//	array->pAddr = malloc(sizeof(void *)* capacity);
//	array->m_capacity = capacity;
//	array->m_size = 0;
//	
//	return array;
//}
//
////��������
//void insert_DynamicArray(struct dynamicArray * array , int pos  , void * data)
//{
//	if ( array == NULL)
//	{
//		return;
//	}
//	if ( data == NULL)
//	{
//		return;
//	}
//
//	//��Чλ��  β��
//	if (pos < 0 || pos > array->m_size)
//	{
//		pos = array->m_size;
//	}
//
//	//�ж��Ƿ����ˣ��������̬��չ
//	if (array->m_size == array->m_capacity)
//	{
//		//1�������¿ռ��С
//		int newCapacity = array->m_capacity * 2;
//
//		//2�������¿ռ�
//		void ** newSpace = malloc(sizeof(void *)* newCapacity);
//
//		//3����ԭ�����ݿ������¿ռ���
//		memcpy(newSpace, array->pAddr, sizeof(void *)* array->m_capacity);
//
//		//4���ͷ�ԭ���ڴ�ռ�
//		free(array->pAddr);
//
//		//5�������¿ռ�ָ��
//		array->pAddr = newSpace;
//
//		//6������������
//		array->m_capacity = newCapacity;
//	}
//
//	//������Ԫ��
//
//	//�ƶ�Ԫ�� ���в�����Ԫ��
//	for (int i = array->m_size - 1; i >= pos; i--)
//	{
//		//��������ƶ�
//		array->pAddr[i + 1] = array->pAddr[i];
//	}
//
//	//����Ԫ�� ���뵽ָ��λ����
//	array->pAddr[pos] = data;
//	//���´�С
//	array->m_size++;
//}
//
//
////��������
//void foreach_DynamicArray(struct dynamicArray * array, void(*myPrint)(void*))
//{
//	if (array == NULL)
//	{
//		return;
//	}
//	if (myPrint == NULL)
//	{
//		return;
//	}
//
//	for (int i = 0; i < array->m_size;i++)
//	{
//		myPrint(array->pAddr[i]);
//	}
//}
//
//
////ɾ������  ��λ��ɾ��
//void removeByPos_DynamicArray(struct dynamicArray * array , int pos)
//{
//	if ( NULL == array)
//	{
//		return;
//	}
//
//	if (pos < 0  || pos > array->m_size - 1)
//	{
//		return;
//	}
//
//	//����ǰ��
//	for (int i = pos; i < array->m_size - 1;i++)
//	{
//		array->pAddr[i] = array->pAddr[i + 1];
//	}
//
//	//���������С
//	array->m_size--;
//
//}
//
////��ֵɾ������
//void removeByValue_DynamicArray(struct dynamicArray * array , void * data , int (* myCompare)(void * ,void *))
//{
//	if ( array == NULL)
//	{
//		return;
//	}
//	if ( data == NULL)
//	{
//		return;
//	}
//
//	for (int i = 0; i < array->m_size;i++)
//	{
//		if (myCompare(array->pAddr[i], data))
//		{
//				//����ҵ�Ҫɾ�������ݣ�i����Ҫɾ���ľ���λ��
//			removeByPos_DynamicArray(array, i);
//			break;
//		}
//	}
//
//}
//
////��������
//void destroy_DynamicArray(struct dynamicArray* array)
//{
//	if (array == NULL)
//	{
//		return;
//	}
//
//	if (array->pAddr != NULL)
//	{
//		free(array->pAddr);
//		array->pAddr = NULL;
//	}
//
//
//	free(array);
//	array = NULL;
//}
//







//����
struct Person
{
	char name[64];
	int age;
};


void myPrintPerson(void *data)
{
	struct Person * p = data;
	printf("������ %s ���䣺%d\n", p->name, p->age);

}

int myComparePerson(void * data1, void *data2)
{
	struct Person *  p1 = data1;
	struct Person *  p2 = data2;

	return  strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

int main(){

	//��ʼ����̬����
	struct dynamicArray * array = init_DynamicArray(5);

	//׼������
	struct Person p1 = { "��ɪ", 18 };
	struct Person p2 = { "槼�", 20 };
	struct Person p3 = { "������", 19 };
	struct Person p4 = { "��", 21 };
	struct Person p5 = { "�����", 999 };
	struct Person p6 = { "���", 999};

	printf("��������ǰ�� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	//��������
	insert_DynamicArray(array, 0, &p1);
	insert_DynamicArray(array, 0, &p2);
	insert_DynamicArray(array, 1, &p3);
	insert_DynamicArray(array, 0, &p4);
	insert_DynamicArray(array, -1, &p5);
	insert_DynamicArray(array, 2, &p6);

	// �� 槼� ��� ������  ��ɪ  �����

	//��������
	foreach_DynamicArray(array, myPrintPerson);


	printf("�������ݺ� ������%d  ��С��%d\n", array->m_capacity, array->m_size);


	//����ɾ�� ��λ��ɾ��
	removeByPos_DynamicArray(array, 2);
	printf("---------------------\n");
	foreach_DynamicArray(array, myPrintPerson);
	printf("ɾ�����ݺ� ������%d  ��С��%d\n", array->m_capacity, array->m_size);

	struct Person  p = { "��ɪ", 18 };
	removeByValue_DynamicArray(array, &p, myComparePerson);
	printf("---------------------\n");
	foreach_DynamicArray(array, myPrintPerson);
	printf("ɾ�����ݺ� ������%d  ��С��%d\n", array->m_capacity, array->m_size);


	//array->pAddr = NULL;
	//array->m_capacity = 0;
	//array->m_size = 0;

	//��������
	destroy_DynamicArray(array);
	array = NULL;

	system("pause");
	return EXIT_SUCCESS;
}