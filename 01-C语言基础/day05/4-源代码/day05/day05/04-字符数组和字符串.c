#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0401(void)
{
	char str[6] = { 'h', 'e', 'l', 'l', 'o', '\0'};

	char str2[] = "world";  //  == {'w', 'o', 'r', 'l', 'd', '\0'}

	printf("%s\n", str2);

	system("pause");
	return EXIT_SUCCESS;
}

// ͳ���ַ�����ÿ���ַ����ֵĴ���
int main0402(void)
{
	char str[11] = {0};		// helloworld -->  26��Ӣ����ĸ a-z  a:97 d:100

	// scanf("%s", str);
	for (size_t i = 0; i < 10; i++)
	{
		scanf("%c", &str[i]);
	}

	int count[26] = {0};  // ����26��Ӣ����ĸ���ֵĴ����� 

	for (size_t i = 0; i < 11; i++)
	{
		int index = str[i] - 'a';	// �û�������ַ��� count�����е��±�ֵ��
		count[index]++;
	}

	for (size_t i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c�ַ����ַ����г��� %d ��\n", i+'a', count[i]);
		}
	}
	
	system("pause");
	return EXIT_SUCCESS;
}

