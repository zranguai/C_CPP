#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1��������NULL���߷Ƿ��ڴ濽������
void test01()
{
	//char *p = NULL;
	////��pָ����ڴ����򿽱�����
	//strcpy(p, "1111"); //err

	//char *q = 0x1122;
	////��qָ����ڴ����򿽱�����
	//strcpy(q, "2222"); //err		

}


//ָ�������Խ����������
int * doWork()
{
	int a = 10;
	int * p = &a;
	return p;
}

//2��Ұָ��������
void test02()
{
	//2.1 ָ�����δ��ʼ��
	/*int * p;
	printf("%d\n",*p);*/



	//2.2 ָ���ͷź�δ�ÿ�
	char * str  = malloc(100);
	free(str);
	//��ס�ͷź� �ÿգ���ֹҰָ�����
	//str = NULL;

	//free(str);
	//2.3 ��ָ������ظ��ͷš�Ұָ�벻�����ظ��ͷ�

	//2.4 ָ�������Խ����������
	int * p = doWork();
	printf("%d\n", *p);
	printf("%d\n", *p);
}

int main(){
	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}
