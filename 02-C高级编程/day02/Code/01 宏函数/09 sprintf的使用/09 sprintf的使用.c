#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	char buf[1024];
	//memset(buf, 0, 1024);
	//sprintf(buf, "���� %d �� %d��  %d��", 2018, 6, 30);

	//printf("%s\n", buf);


	//2. ƴ���ַ���
	//memset(buf, 0, 1024);
	//char str1[] = "hello";
	//char str2[] = "world";
	//int len = sprintf(buf, "%s%s", str1, str2); //����ֵ���ַ������� ������\0
	//printf("buf:%s len:%d\n", buf, len);

	//3. ����ת�ַ���
	//memset(buf, 0, 1024);
	//int num = 100;
	//sprintf(buf, "%d", num);
	//printf("buf:%s\n", buf);


	int num = 100;
	//���ÿ�� �Ҷ���
	memset(buf, 0, 1024);
	sprintf(buf, "%8d", num);
	printf("buf:%s\n", buf);
	////���ÿ�� �����
	memset(buf, 0, 1024);
	sprintf(buf, "%-8d", num);
	printf("buf:%sa\n", buf);
	//ת��16�����ַ��� Сд
	memset(buf, 0, 1024);
	sprintf(buf, "0x%x", num);
	printf("buf:%s\n", buf);

	//ת��8�����ַ���
	memset(buf, 0, 1024);
	sprintf(buf, "0%o", num);
	printf("buf:%s\n", buf);



}

int main(){

	test01();
		

	system("pause");
	return EXIT_SUCCESS;
}