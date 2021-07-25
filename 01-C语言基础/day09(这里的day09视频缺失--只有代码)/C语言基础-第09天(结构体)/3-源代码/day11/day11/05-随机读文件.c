#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct student {
	int age;
	char name[10];
	int num;
} stu_t;

int main0501(void)
{
	stu_t stu[4] = {
		18, "afei", 10,
		20, "andy", 20,
		30, "lily", 30,
		16, "james", 40
	};
	stu_t s1;

	FILE *fp = fopen("test05.txt", "wb+");
	if (!fp)  // fp == NULL
	{
		perror("fopen error");
		return -1;
	}
	int ret = fwrite(&stu[0], 1, sizeof(stu), fp);  // �Զ�������ʽд�룬
	printf("ret = %d\n", ret);

	fseek(fp, sizeof(stu_t)*2, SEEK_SET);		// ���ļ���ʼλ�ã����ƫ��һ��stu�ṹ��

	ret = fread(&s1, 1, sizeof(s1), fp);
	printf("ret = %d\n", ret);

	printf("1 age= %d, name=%s, num=%d\n", s1.age, s1.name, s1.num);

	int len = ftell(fp); // ��ȡ�ļ���ǰ��дָ��λ�ã����ļ���ʼλ�õ�ƫ������

	printf("len = %d\n", len);

	rewind(fp);	// ���ļ���дָ��ؾ���ʼ��

	ret = fread(&s1, 1, sizeof(s1), fp);

	printf("2 age= %d, name=%s, num=%d\n", s1.age, s1.name, s1.num);

	// ��ȡ�ļ���С��
	fseek(fp, 0, SEEK_END);	// ���ļ���дָ��ŵ��ļ���β��
	len = ftell(fp);
	printf("�ļ���СΪ��%d\n", len);

	fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}

int main0502(void)
{
	FILE *fp = fopen("test0501.txt", "w+");  // "r+"

	int ret = fputs("11111", fp);
	printf("ret 1 = %d\n", ret);		// 0 ��ʾ�ɹ���

	ret = fputs("22222", fp);
	printf("ret 2 = %d\n", ret);

	ret = fputs("33333", fp);
	printf("ret 3 = %d\n", ret);

	char buf[1024] = { 0 };

	//fseek(fp, 5 * 2, SEEK_SET);  // �ı��дָ��λ�á�
	rewind(fp); // ��ʼλ�á�
	char *ptr = fgets(buf, 1024, fp);
	if (ptr == NULL)
		printf("ptr == NULL \n");

	printf("fgets ptr = %s\n", ptr);
	printf("buf = %s\n", buf);

	fclose(fp);
	system("pause");
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main0503(int argc, char *argv[])
{
	FILE *fp = fopen("test1.txt", "r+");

	char buf[6] = { 0 };
	char *ptr = fgets(buf, 6, fp);

	printf("buf=%s, ptr=%s\n", ptr, buf);

	fseek(fp, 0, SEEK_CUR);
	int ret = fputs("AAAAA", fp);
	printf("ret = %d\n", ret);

	fclose(fp);

	system("pause");
	return 0;
}

