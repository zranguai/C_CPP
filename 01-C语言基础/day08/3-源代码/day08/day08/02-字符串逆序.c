#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


// o e l l h

// �ַ�������
void str_inserse(char *str)
{
	//int i, j;  // str[i] *(str+i)
	char *start = str;					// ��¼��Ԫ�ص�ַ
	char *end = str + strlen(str) - 1;	// ��¼���һ��Ԫ�ص�ַ��

	while (start < end)			// ��Ԫ�ص�ַ�Ƿ� < ���һ��Ԫ�ص�ַ
	{
		char tmp = *start;		// ����ˮ char Ԫ�ؽ���
		*start = *end;
		*end = tmp;
		start++;			// ��Ԫ�ض�Ӧָ�����
		end--;				// βԪ�ض�Ӧָ��ǰ��
	}
}
// �жϻ����ַ���   abcddpba
int str_abcbb(char *str)
{
	char *start = str;		// ��¼��Ԫ�ص�ַ
	char *end = str + strlen(str) - 1;// ��¼���һ��Ԫ�ص�ַ��

	while (start < end)		// ��Ԫ�ص�ַ�Ƿ� < ���һ��Ԫ�ص�ַ
	{
		if (*start != *end)	// �ж��ַ��Ƿ�һ�¡�
		{
			return 0; // 0 ��ʾ�� ����
		}
		start++;
		end--;
	}
	return 1;		// 1 ��ʾ ����
}

int main0201(void)
{
	char str[] = "this is a test";

	str_inserse(str);

	printf("str=%s\n ---------------------\n", str);

	char s2[] = "abcmncba";

	int ret = str_abcbb(s2);

	if (ret == 0)
		printf("���ǻ���\n");
	else if (ret == 1)
		printf("�ǻ���\n");

	system("pause");
	return EXIT_SUCCESS;
}
