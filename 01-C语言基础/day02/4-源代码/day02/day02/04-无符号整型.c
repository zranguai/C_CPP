#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0401(void)
{
	size_t var = 10;
	printf("var = %u\n", var);

	unsigned int a = 10u;  // ��д�� unsigned int a = 10;
	unsigned short b = 20u;// ��д�� unsigned short b = 20;
	unsigned long c = 30Lu; 
	unsigned long long d = 40LLu;

	printf("unsigned int ������ֵ��%u\n", a);
	printf("unsigned short ������ֵ��%hu\n", b);
	printf("unsigned long ������ֵ��%lu\n", c);
	printf("unsigned long long ������ֵ��%llu\n", d);

	system("pause");

	return EXIT_SUCCESS;
}
