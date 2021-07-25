#include "config.h"

int getFileLines(char * filePath)
{
	FILE * file = fopen(filePath, "r");
	if (file == NULL)
	{
		return -1;
	}

	char buf[1024] = { 0 };
	int lines = 0;
	while ( fgets(buf,1024,file) != NULL)
	{
		if (isValidLines(buf))
		{
			lines++;
		}
		memset(buf, 0, 1024);
	}

	return lines;

	fclose(file);
}

int isValidLines(char *str)
{
	if (strchr(str, ':') == NULL)
	{
		return 0; //���ؼ� ������Ч��
	}

	return 1;
}

//�����ļ�
void parseFile(char * filePath, int lines, struct  ConfigInfo ** configinfo)
{
	struct ConfigInfo * info = malloc(sizeof(struct ConfigInfo) * lines);

	if (info == NULL)
	{
		return;
	}

	FILE * file = fopen(filePath, "r");
	if (file == NULL)
	{
		return;
	}
	char buf[1024] = { 0 };
	int index = 0;
	while ( fgets(buf,1024,file ) != NULL)
	{
		if (isValidLines(buf))
		{
			//��Ч��Ϣ ��ȥ����
			//��� key��value����
			//heroName:aaaa\n
			memset(info[index].key, 0, 64);
			memset(info[index].value, 0, 64);
			char * pos = strchr(buf, ':');
			strncpy(info[index].key, buf, pos - buf);
			strncpy(info[index].value, pos + 1, strlen(pos + 1)-1);
			index++;
		}
		memset(buf, 0, 1024);
	}
	*configinfo = info;
}

char * getInfoByKey(char * key, struct ConfigInfo * configinfo, int len)
{
	for (int i = 0; i < len;i++)
	{
		if (strcmp(key, configinfo[i].key) == 0)
		{
			return configinfo[i].value;
		}
	}

	return NULL;
}

//�ͷ��ڴ�
void freeConfigInfo(struct ConfigInfo * configinfo)
{
	if (configinfo != NULL)
	{
		free(configinfo);
		configinfo = NULL;
	}
}