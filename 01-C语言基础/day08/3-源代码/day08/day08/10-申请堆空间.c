#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main1001(void)
{
	//int arr[1000000] = {10, 20, 40};
	int *p = (int *)malloc(sizeof(int) * 10);
	//char *str = (char *)malloc(sizeof(char)*10);
	if (p == NULL)
	{
		printf("malloc error\n");
		return -1;
	}
	char *tmp = p;  // ��¼malloc���صĵ�ֵַ������free

	// д���ݵ� malloc �ռ䡣
	for (size_t i = 0; i < 10; i++)
	{
		p[i] = i + 10;
	}
	// ����malloc�ռ��е�����
	//for (size_t i = 0; i < 10; i++)
	//{
	//	printf("%d ", *(p+i));
	//}
	for (size_t i = 0; i < 10; i++)
	{
		printf("%d ", *p);
		p++;
	}

	// �ͷ�������ڴ档
	free(tmp);
	p = NULL;

	system("pause");
	return EXIT_SUCCESS;
}
