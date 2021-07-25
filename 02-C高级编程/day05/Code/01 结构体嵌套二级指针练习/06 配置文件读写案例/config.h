#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//������Ϣ �ṹ��
struct ConfigInfo
{
	char key[64];
	char value[64];
};

//��ȡ��Ч����
int getFileLines(char * filePath);

//��⵱ǰ���Ƿ�����Ч��Ϣ
int isValidLines(char *str);

//�����ļ�
void parseFile(char * filePath, int lines , struct  ConfigInfo ** configinfo);

//����key��ȡ��Ӧvalue
char * getInfoByKey(char * key, struct ConfigInfo * configinfo, int len);

//�ͷ��ڴ�
void freeConfigInfo(struct ConfigInfo * configinfo);