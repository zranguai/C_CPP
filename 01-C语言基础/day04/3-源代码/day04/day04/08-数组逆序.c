#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// ����Ԫ������
int main0801(void)
{
	int arr[] = {1, 6, 8, 0, 4, 3, 9, 2};  // {2, 9, 3, 4, 0, 8, 6, 1}
	int len = sizeof(arr) / sizeof(arr[0]); //����Ԫ�ظ���

	int i = 0;				// i��ʾ�������Ԫ���±�
	int j = len - 1;		// ��ʾ��������һ��Ԫ���±�
	int xijinping = 0;		// ��ʱ���� 

	// ���� ����Ԫ�أ�������
	while (i < j)
	{
		xijinping = arr[i];		// ����ˮ����������
		arr[i] = arr[j];
		arr[j] = xijinping;
		i++;
		j--;
	}
	// ��ӡ������� ����
	for (size_t n = 0; n < len; n++)
	{
		printf("%d ", arr[n]);
	}
	printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}

