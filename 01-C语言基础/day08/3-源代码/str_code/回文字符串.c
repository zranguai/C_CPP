#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int str_abcba(char *str)
{
	char *start = str;
	char *end = str + strlen(str) - 1;

	while (start < end)
	{
		if (*start != *end)
		{
			return 0;	// ���ǻ��ġ�
		}
		start++;
		end--;
	}
	return 1;	// �ǻ��ġ�
}

int main(void)
{
	char str[] = "hello world";
	
	int ret = str_abcba(str);
	if (ret == 1)
	{
		printf("�ǻ����ַ���\n");	
	}
	else
	{
		printf("���ǻ����ַ���\n");	
	}

	return EXIT_SUCCESS;
}