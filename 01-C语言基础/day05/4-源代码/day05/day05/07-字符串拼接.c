#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0702(void)
{
	char str1[] = "hello";  // [ h e l l o \0 ]
	char str2[] = "world";

	char str3[100];

	int i = 0;		// ѭ�� str1
	while (str1[i] != '\0')   // '\0' != '\0'
	{
		str3[i] = str1[i];  // ѭ���Ž�str1�е�ÿһ��Ԫ�أ�����str3
		i++;
	}					// str3=[h e l l o]
	//printf("%d\n", i);  --> 5

	int j = 0;		// ѭ�� str2
	while (str2[j]) // �ȼ��� while(str2[j] !='\0') �ȼ��� while(str2[j] != 0)
	{
		str3[i+j] = str2[j];
		j++;
	}					// str3=[h e l l o w o r l d]

	// �ֶ���� \0 �ַ����������
	str3[i + j] = '\0';

	printf("str3 = %s\n", str3);

	system("pause");
	return EXIT_SUCCESS;
}
