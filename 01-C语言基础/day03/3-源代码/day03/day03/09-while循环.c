#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// �� 7 
int main0901(void)
{
	int num = 1;

	while (num <= 100)
	{
		if ((num % 7 == 0) || (num % 10 == 7) || (num / 10 == 7))		// ��λ��10λ��7�ı���
		{
			printf("������\n");
		}
		else
		{
			printf("%d\n", num);
		}
		num++;  // ����
	}

	system("pause");
	return EXIT_SUCCESS;
}
