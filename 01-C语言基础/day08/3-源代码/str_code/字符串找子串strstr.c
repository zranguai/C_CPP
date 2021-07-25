#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

char *my_strstr(char *str, char *substr)
{
	char *pstr = str;		// ���� str ��ָ��
	char *temp = str;		// ��¼�ع�λ�õ�ָ��
	char *psub = substr;		// ���� substr ��ָ��

	while (*pstr)			// ���� ԭ�ַ�����	
	{
		temp = pstr;		// ��¼λ��									

		while (*pstr == *psub && *pstr != '\0')				
		{
			pstr++;			// һ�������
			psub++;			// һ�������
		}
		if (*psub == '\0')								
		{
			return temp;
		}
		// �ع�
		psub = substr;											
		pstr = temp;												

		pstr++;			// �����һ���ַ���								
	}
	
	return NULL;
}

int main(void)
{
	char str[] = "helhellolo world";
	char substr[] = "hello";
	
	printf("%s\n", my_strstr(str, substr));
	
	system("pause");
	
	return EXIT_SUCCESS;
}
