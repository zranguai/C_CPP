#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// while �Ļ����÷�
int main1001(void)
{
	int a = 1;
	do
	{
		a++;
		printf("a = %d\n", a);
	} while (a < 10);

	system("pause");
	return EXIT_SUCCESS;
}

// ˮ�ɻ�����һ����λ��������λ�ϵ����ֵ������͵��ڱ����֡� 
int main1002(void)
{
	int a, b, c;
	int num = 100;

	do {
		a = num % 10;		// ��λ
		b = num / 10 % 10;	// ʮλ
		c = num / 100;		// ��λ

		if (a*a*a + b*b*b + c*c*c == num)
		{
			printf("%d\n", num);
		}
		num++;

	} while (num < 1000);

	system("pause");
	return EXIT_SUCCESS;
}


