#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main0801(void)
{
	int score;
	scanf("%d", &score);

	switch (score/10)
	{
	case 10:		//	 100 -- 90 ����
	case 9:	    
		printf("����\n");
		break;
	case 8:			//   70 -- 90 ����
	case 7:
		printf("����\n");
		//break;
	case 6:		   // 70 - 60 ����
		printf("����\n");
		//break;
	default:
		printf("������\n");
		break;		
	}

	system("pause");
	return EXIT_SUCCESS;
}
