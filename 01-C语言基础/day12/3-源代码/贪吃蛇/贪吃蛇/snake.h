#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>


#define WIDE 60			// ���
#define HIGH 20			// �߶�

// һ������Ķ���
struct BODY {
	int X;
	int Y;
};

// �����߶���
struct SNAKE {
	struct BODY body[WIDE*HIGH];
	int size;
}snake;			// һ���߶���

				// ����ʳ�����
struct FOOD {
	int X;
	int Y;
}food1;			// һ��ʳ�����

int score = 0;	// ����

int kx = 0;			// �û����� asdw ����һ���������õ��� ����ֵ��
int ky = 0;

int lastX = 0;		// ��β�����ꡣ
int lastY = 0;

int sleepSecond = 400;

// ��������
void initSnake(void);
void initFood(void);
void initUI(void);
void playGame(void);
void initWall(void);
void showScore(void);

#endif
