#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include <sys/types.h>
#include <sys/stat.h>

/*
FILE *fp = fopen("test05.txt", "r");

fseek(fp, 0, SEEK_END);

int len = ftell(fp);

printf("�ļ���С��%d\n", len);

fclose(fp);
*/

int main0602(void)
{
	struct stat buf;

	int ret = stat("test05.txt", &buf);  // �����������ں������ý���ʱ���䵱��������ֵ��

	printf("�ļ���С��%d\n", buf.st_size); // �����ļ�����ȡ�ļ���С��

	system("pause");
	return EXIT_SUCCESS;
}
