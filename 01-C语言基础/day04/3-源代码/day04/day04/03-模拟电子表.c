#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int main0301(void)
{
	int i, j, k;

	// Сʱ
	for (i = 0; i < 24; i++)
	{
		// ����
		for (j = 0; j < 60; j++)
		{
			// ��
			for (k = 0; k < 60; k++)
			{
				printf("%02d:%02d:%02d\n", i, j, k);
				Sleep(960);
				system("cls");  // ����
			}
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}
