#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
	�㷨�Ż�
	memcmp(str , subStr ,3 ) == 0;
*/
int myStrstr(char * str , char * subStr)
{
	int num = 0;
	while (*str != '\0')
	{
		if (*str != *subStr)
		{
			num++;
			str++;
			continue;
		}

		//����������ʱָ�� �����ζԱ�
		char * tmpStr = str;
		char * tmpSubstr = subStr;

		while (*tmpSubstr != '\0')
		{
			if (*tmpStr != *tmpSubstr)
			{
				//ƥ��ʧ��
				num++;
				str++;
				break;
			}
			tmpStr++;
			tmpSubstr++;
		}
		if (*tmpSubstr == '\0')
		{
			//ƥ��ɹ�
			return num;
		}

	}

	return -1;
}

void test01()
{
	char * str = "abdnfcdefgdfasdfaf";

	int ret = myStrstr(str, "dnf");

	if ( ret != -1)
	{
		printf("�ҵ����Ӵ���λ��Ϊ��%d\n", ret);
	}
	else
	{
		printf("δ�ҵ��Ӵ�\n");
	}

}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}