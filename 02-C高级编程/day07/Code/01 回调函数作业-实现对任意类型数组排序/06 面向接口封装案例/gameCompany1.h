#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Player
{
	char name[64]; //�������
	int level; //��ҵȼ�
	int  exp; //��Ҿ���
};

//��ʼ����Ϸ  ����1  ���ָ��   ����2  �������
void INIT_GAME_COMPANY1(void ** player, char * name);

//����ս��  ����ս���Ƿ�ʤ�� 1������ʤ��  0������ʧ��   ����1  ���  ����2 ��Ϸ�����Ѷ�
int FIGHT_GAME_COMPANY1(void * player, int gameDiff);

//�鿴�����Ϣ
void PRINT_GAME_COMPANY1(void * player);

//�뿪��Ϸ
void EXIT_GAME_COMPANY1(void * player);

//�ж���Ϸ�Ƿ�ʤ��
int isWin(int winRate, int diff);