#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



void read_file06()
{
	char ch = 0;

	FILE *fp = fopen("06test.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}

	while (1)
	{
		ch = fgetc(fp);

		if (feof(fp))
		{
			break;
		}
		printf("%d\n", ch);
	}

	fclose(fp);
}

void test_feof()
{
	FILE *fp = fopen("06test.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return ;
	}
	while (1)
	{
		printf("û�е����ļ���β\n");
		fgetc(fp);				// һ�ζ�һ���ַ��������ַ�ֱ�Ӷ�����
		if (feof(fp))
		{
			break;
		}
	}
	fclose(fp);
}
void write_file06()
{
	FILE *fp = fopen("06test.txt", "w");
	if (fp == NULL)
	{
		perror("fopen error");
		return;
	}
	fputc('a', fp);
	fputc('b', fp);
	fputc(-1, fp);
	fputc('c', fp);
	fputc('d', fp);
	fputc('\n', fp);

	fclose(fp);
}

int main0601(void)
{
	//write_file06();
	//read_file06();
	test_feof();

	system("pause");
	return EXIT_SUCCESS;
}