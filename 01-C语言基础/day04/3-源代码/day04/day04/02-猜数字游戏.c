#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main0201(void)
{
	srand(time(NULL));	//����������ӡ�

	int n = 0;
	int num = rand() % 100;  // ���������

	for (;;)  // while(1)
	{
		printf("������²�����֣�");
		scanf("%d", &n);
		if (n < num)
		{						// for��while��if ���ִ�����ֻ��һ���� { } ����ʡ��
			printf("��С��\n");
		}
		else if (n > num)	
			printf("�´���\n");	
		else
		{
			printf("���У�����\n");
			break;			// ����
		}
	}
	printf("�����ǣ�%d\n", num);

	system("pause");

	return 0;
}
