#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0701(void)
{
	int a;
	scanf("%d", &a);

	if (a > 0)
	{
		printf("a > 0\n");
	}
	else
	{
		printf("a <= 0\n");
	}

	system("pause");
	return EXIT_SUCCESS;
}

//�ɼ�
int main0702(void)
{
	int score;		// 100--90 �� 90 -- 70 ���� 70 -- 60 ����  < 60 �

	printf("������ѧ���ɼ���");
	scanf("%d", &score);

	if (score>=90 && score <=100)
	{
		printf("����\n");
	} 
	else if(score < 90 && score >=70)
	{
		printf("����\n");
	}
	else if (score < 70 && score >= 60)
	{
		printf("����\n");
	}
	else
	{
		printf("������\n");
	}



	system("pause");
	return EXIT_SUCCESS;
}

// ��ֻС�������
int main0703(void)
{
	int pig1, pig2, pig3;

	// if (pig1 > pig2 && pig1 > pig3)
	// pig1 > pig2 ? pig1 : pig2;

	printf("��������ֻС�������:");
	scanf("%d %d %d", &pig1, &pig2, &pig3);

	if (pig1 > pig2)		// ���㣬˵��pig1����
	{
		if (pig1 > pig3)
		{
			printf("��һֻС�����أ�����Ϊ��%d\n", pig1);
		}
		else
		{
			printf("��3ֻС�����أ�����Ϊ��%d\n", pig3);
		}
	}   
	else
	{
		if (pig2 > pig3)
		{
			printf("��2ֻС�����أ�����Ϊ��%d\n", pig2);
		}
		else
		{
			printf("��3ֻС�����أ�����Ϊ��%d\n", pig3);
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}

