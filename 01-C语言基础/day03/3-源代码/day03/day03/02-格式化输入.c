#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// ��ȡ�û����� ����
int main0201(void)
{
	int a;

	scanf("%d", &a);		// &����ʾȡ������a�ĵ�ַ������a�Ŀռ�

	printf("a = %d\n", a);

	system("pause");
	return EXIT_SUCCESS;
}

int main0202(void)
{
	char ch1, ch2, ch3;	//	��������ͬ���Ͷ��������

	scanf("%c%c%c", &ch1, &ch2, &ch3);	// &����ʾȡ������ch�ĵ�ַ������a�Ŀռ�

	printf("ch1 = %c\n", ch1);
	printf("ch2 = %c\n", ch2);
	printf("ch3 = %c\n", ch3);

	system("pause");
	return EXIT_SUCCESS;
}

int main0203(void)
{
	int a1, a2, a3;	//	��������ͬ���Ͷ��������

	scanf("%d %d %d", &a1, &a2, &a3);	// &����ʾȡ������ch�ĵ�ַ������a�Ŀռ�

	printf("a1 = %d\n", a1);
	printf("a2 = %d\n", a2);
	printf("a3 = %d\n", a3);

	system("pause");
	return EXIT_SUCCESS;
}

int main0204(void)
{
	char a[5];			// ��СΪ5�ֽڵ�����

	scanf("%s", a);		// �����û��������룬д������a��

	printf("a = %s\n", a);

	system("pause");
	return EXIT_SUCCESS;
}

int main0205(void)
{
	char a[50];			// ��СΪ50�ֽڵ�����

	scanf("%s", a);		// �����û��������룬д������a��

	printf("a = %s\n", a);

	system("pause");

	return EXIT_SUCCESS;
}

int main0206(void)
{
	char ch;

	ch = getchar();		// �����û����룬���ؽ��յ���ASCII��

	printf("ch = %c\n", ch);

	putchar(ch);
	putchar('\n');

	system("pause");

	return EXIT_SUCCESS;
}
