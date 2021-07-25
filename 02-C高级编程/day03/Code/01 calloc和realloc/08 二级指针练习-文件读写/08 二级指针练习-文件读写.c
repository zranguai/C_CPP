#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��ȡ��Ч����
int getFileLines(FILE * pFile)
{
	if (pFile == NULL)
	{
		return -1;
	}

	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf,1024,pFile) != NULL)
	{
		//printf("%s", buf);
		lines++;
	}

	//���ļ��������
	fseek(pFile, 0, SEEK_SET);
	return lines;

}

//��ȡ���ݷ��뵽pArray��
void readFileData(FILE * pFile, int len, char ** pArray)
{
	if (pFile == NULL)
	{
		return;
	}
	if (len <= 0 )
	{
		return;
	}
	if ( pArray ==NULL)
	{
		return;
	}
	char buf[1024] = { 0 };
	int index = 0;
	while (fgets(buf, 1024, pFile) != NULL)
	{
		/*
		aaaaaaaaaa
		bbbb
		cccccc
		*/
		int currentLen = strlen(buf) +1 ;
		char * currentStrP = malloc(sizeof(char)* currentLen);
		strcpy(currentStrP, buf);
		pArray[index++] = currentStrP;

		memset(buf, 0, 1024);
	}

}

void showFileData(char ** pArray, int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("%d�е�����Ϊ %s", i + 1, pArray[i]);
	}
	
}

void test01()
{
	//���ļ�
	FILE * pFile =	fopen("./test.txt", "r");
	if (pFile == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}

	//ͳ����Ч����
	int len =  getFileLines(pFile);
	//printf("�ļ�����Ч����Ϊ��%d\n", len);
	char ** pArray =  malloc(sizeof(char *)* len);

	//��ȡ�ļ��е����ݲ��ҷ��뵽 pArray��
	readFileData(pFile, len, pArray);

	//��ȡ����
	showFileData(pArray , len);

	//�ͷŶ�������
	for (int i = 0; i < len; i++)
	{
		if (pArray[i] != NULL)
		{
			free(pArray[i]);
			pArray[i] = NULL;
		}
	}
	free(pArray);
	pArray = NULL;
	//�ر��ļ�
	fclose(pFile);
}

int main(){


	test01();


	system("pause");
	return EXIT_SUCCESS;
}