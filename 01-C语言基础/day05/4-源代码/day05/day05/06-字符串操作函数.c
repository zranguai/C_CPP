#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//gets
int main0601(void)
{
	char str[10];

	printf("��ȡ���ַ���Ϊ��%s", gets(str));

	system("pause");
	return EXIT_SUCCESS;
}

//fgets
int main0602(void)
{
	char str[10];

	printf("��ȡ���ַ���Ϊ��%s", fgets(str, sizeof(str), stdin));

	system("pause");
	return EXIT_SUCCESS;
}

//puts
int main0603(void)
{
	char str[] = "hello world\n";

	int ret = puts(str);	// puts("hello world");

	printf("ret = %d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}

//fputs
int main0604(void)
{
	char str[] = "hello world\n";

	//int ret = fputs(str, stdout);	// 

	int ret = fputs("hello world\n", stdout);

	printf("ret = %d\n", ret);

	system("pause");
	return EXIT_SUCCESS;
}

// strlen() ���� �� ��ȡ�ַ����� ��Ч���ȣ� ������\0
int main0605(void)
{
	char str[] = "hello\0world";

	printf("sizeof(str) = %u\n", sizeof(str));

	printf("strlen(str) = %u\n", strlen(str));

	system("pause");
	return EXIT_SUCCESS;
}

// ʵ��strlen����
int main0606(void)
{
	char str[] = "hello world";

	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	printf("%d\n", i);

	// �ȼ��� printf("%d\n", strlen(str));

	system("pause");
	return EXIT_SUCCESS;
}

// ���װ�
int main0607(void)
{
	char str[] = "hello\0world";

	int i = 0;
	while (str[i++]);

	printf("%d\n", i-1);
	// �ȼ��� printf("%d\n", strlen(str));

	system("pause");
	return EXIT_SUCCESS;
}


