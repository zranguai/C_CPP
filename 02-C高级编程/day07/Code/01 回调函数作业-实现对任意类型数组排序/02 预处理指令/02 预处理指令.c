#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1 ��ͷ�ļ�����  "" <>����
// ""�����Զ���ͷ�ļ�
// <> ����ϵͳͷ�ļ�

//2�� �� ����  
//  ������������
//  �������� undefж�غ�
//  �곣�� û���������͵�

//�� ����
//  ����С��Ƶ��ʹ�õĺ���д�ɺ꺯��
//  �����ű�֤����������
//  �ŵ㣺�Կռ任ʱ��

void test01()
{
	#define  MAX 1024
	//#undef  MAX
}

//3�� ��������
//#define  DEBUG
#ifdef DEBUG
void func()
{
	printf("Debug�汾����\n");
}
#else 
	//�Զ�����������
#if 0
void func()
{
	printf("Release1�汾����\n");
}
#else 
void func()
{
	printf("Release2�汾����\n");
}
#endif


#endif



//�����
void doWork(char * p)
{
	if (p == NULL)
	{
		printf("�ļ��� %s �� %d �� ������\n", __FILE__, __LINE__);
		printf("���ڣ�%s\n", __DATE__);
		printf("ʱ�䣺%s\n", __TIME__);
		return;
	}


}
void test02()
{
	doWork(NULL);
	
}


int main(){

	//printf("MAX = %d\n", MAX);
	//func();
	test02();


	system("pause");
	return EXIT_SUCCESS;
}