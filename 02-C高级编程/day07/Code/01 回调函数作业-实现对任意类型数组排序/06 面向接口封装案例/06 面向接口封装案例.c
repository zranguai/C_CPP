#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "gameCompany1.h"
#include <time.h>

//��ʼ����Ϸ  ����1  ���ָ��   ����2  �������
typedef void(*INIT_GAME)(void ** player , char * name);

//����ս��  ����ս���Ƿ�ʤ�� 1������ʤ��  0������ʧ��   ����1  ���  ����2 ��Ϸ�����Ѷ�
typedef int(*FIGHT_GAME)(void * player, int gameDiff);

//�鿴�����Ϣ
typedef void(*PRINT_GAME)(void * player);

//�뿪��Ϸ
typedef void(*EXIT_GAME)(void * player);


void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME printGame, EXIT_GAME exitGame)
{
	//��ʼ����Ϸ
	void * player = NULL;
	printf("������������\n");
	char userName[64];
	scanf("%s", userName);

	init(&player, userName);

	//�����Ѷ� ����
	int diff = -1;

	while (1)
	{
		getchar();
		system("cls");
		printf("��ѡ����Ϸ�Ѷȣ�\n");
		printf("1����\n");
		printf("2���е�\n");
		printf("3������\n");

		scanf("%d", &diff);

		getchar(); //ȡ�߻��з�

		//ս��
		int ret = fight(player, diff);
		if (ret == 0)
		{

			printf("��Ϸʧ��\n");
			break;
		}
		else
		{
			printf("��ս�ɹ�����ҵ�ǰ��Ϣ���£�\n");

			printGame(player);
		}

	}

	
	//�ر���Ϸ
	exitGame(player);
}

int main(){

	srand((unsigned int)time(NULL));

	playGame(INIT_GAME_COMPANY1, FIGHT_GAME_COMPANY1, PRINT_GAME_COMPANY1, EXIT_GAME_COMPANY1);

	system("pause");
	return EXIT_SUCCESS;
}