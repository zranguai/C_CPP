#include "gameCompany1.h"

//��ʼ����Ϸ  ����1  ���ָ��   ����2  �������
void INIT_GAME_COMPANY1(void ** player, char * name)
{
	struct Player * player1 = malloc(sizeof(struct Player));

	if (player1 == NULL)
	{
		printf("��ʼ��ʧ��\n");
		return;
	}

	*player = player1;

	strcpy(player1->name, name);
	player1->level = 0;
	player1->exp = 0;

}

//����ս��  ����ս���Ƿ�ʤ�� 1������ʤ��  0������ʧ��   ����1  ���  ����2 ��Ϸ�����Ѷ�
int FIGHT_GAME_COMPANY1(void * p, int gameDiff)
{
	struct Player * player = p;

	int addExp = 0;  //���Ӿ���ֵ

	switch (gameDiff)
	{
	case 1:
		addExp = isWin(90, 1);
		break;
	case 2:
		addExp = isWin(50, 2);
		break;
	case 3:
		addExp = isWin(30, 3);
		break;
	default:
		break;
	}

	//�ۻ����鵽�������
	player->exp += addExp;
	player->level = player->exp / 10;

	if (addExp == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}


}

//�ж���Ϸ�Ƿ�ʤ��
int isWin(int winRate, int diff)
{
	int random = rand() % 100 + 1;  // 1 ~ 100
	if (random <= winRate)
	{
		return diff * 10;
	}
	else 
	{
		return 0;
	}
}


//�鿴�����Ϣ
void PRINT_GAME_COMPANY1(void * p)
{
	struct Player * player = p;
	printf("���<%s> ------ ��ǰ�ȼ���<%d>�� ----- ��ǰ���飺 <%d> \n", player->name, player->level, player->exp);
}

//�뿪��Ϸ
void EXIT_GAME_COMPANY1(void * player)
{
	if ( player==NULL)
	{
		return;
	}

	free(player);
	player = NULL;
}