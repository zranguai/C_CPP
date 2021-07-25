#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//�����ַ���д�ļ���fgetc(), fputc()

void test01()
{
	//д�ļ�

	FILE * f_write = fopen("./test01.txt", "w+");

	if (f_write == NULL)
	{
		return;
	}

	char buf[] = "this is first test";
	for (int i = 0; i < strlen(buf);i++)
	{
		fputc(buf[i], f_write);
	}

	fclose(f_write);

	//���ļ�
	FILE * f_read = fopen("./test01.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	char ch;
	while ( (ch = fgetc(f_read)) != EOF  )  // EOF  Enf of File
	{
		printf("%c", ch);
	}
	fclose(f_read);
}


//�����ж�д�ļ���fputs(), fgets()
void test02()
{
	//д�ļ�
	FILE * f_write = fopen("./test02.txt", "w");
	if (f_write == NULL)
	{
		return;
	}
	char * buf[] =
	{
		"�����յ���\n",
		"���κ�����\n",
		"˭֪���в�\n",
		"����������\n",
	};

	for (int i = 0; i < 4;i++)
	{
		fputs(buf[i], f_write);
	}

	fclose(f_write);

	//���ļ�
	FILE * f_read = fopen("./test02.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	while ( !feof(f_read ))
	{
		char buf[1024] = { 0 };
		fgets(buf, 1024, f_read);
		printf("%s", buf);
	}

	fclose(f_read);
}

//���տ��д�ļ���fread(), fwirte()
struct Hero
{
	char name[64];
	int age;
};
void test03()
{
	//д�ļ�  wb�����Ʒ�ʽ
	FILE * f_write = fopen("./test03.txt", "wb");
	if (f_write == NULL)
	{
		return;
	}

	struct Hero heros[4] = 
	{
		{ "��ɪ" , 18 },
		{ "����", 28 },
		{ "槼�", 19 },
		{ "�����", 99 },
	};

	for (int i = 0; i < 4;i++)
	{
		//����1 ���ݵ�ַ  ����2  ���С   ����3  �����   ����4  �ļ�ָ��
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}

	fclose(f_write);

	//���ļ�  
	FILE * f_read = fopen("./test03.txt", "rb");  // read binary
	if (f_read == NULL)
	{
		return;
	}

	struct Hero temp[4];
	//����1 ���ݵ�ַ  ����2  ���С   ����3  �����   ����4  �ļ�ָ��
	fread(&temp, sizeof(struct Hero), 4, f_read);

	for (int i = 0; i < 4;i++)
	{
		printf("����:%s  ���䣺%d \n", temp[i].name, temp[i].age);
	}
	fclose(f_read);
}

//���ո�ʽ����д�ļ���fprintf(), fscanf()
void test04()
{
	//д�ļ�
	FILE * f_write = fopen("./test04.txt", "w");
	if (f_write == NULL)
	{
		return;
	}

	fprintf(f_write, "hello world %d�� %d�� %d��", 2018, 7, 5);

	//�ر��ļ�
	fclose(f_write);


	//���ļ�
	FILE * f_read = fopen("./test04.txt", "r");
	if (f_read == NULL)
	{
		return;
	}

	char buf[1024] = { 0 };
	while (!feof(f_read))
	{
		fscanf(f_read, "%s", buf);
		printf("%s\n", buf);
	}

	fclose(f_read);
}

//�������λ�ö�д�ļ�
void test05()
{
	FILE * f_write = fopen("./test05.txt", "wb");
	if (f_write == NULL)
	{
		return;
	}

	struct Hero heros[4] =
	{
		{ "��ɪ", 18 },
		{ "����", 28 },
		{ "槼�", 19 },
		{ "�����", 99 },
	};

	for (int i = 0; i < 4; i++)
	{
		//����1 ���ݵ�ַ  ����2  ���С   ����3  �����   ����4  �ļ�ָ��
		fwrite(&heros[i], sizeof(struct Hero), 1, f_write);
	}

	fclose(f_write);


	//��ȡ槼�����
	FILE * f_read = fopen("./test05.txt", "rb");
	if (f_read == NULL)
	{
		//error �� 
		
		//printf("�ļ���ʧ��\n");
		perror("�ļ���ʧ��");
		return;
	}

	//������ʱ�ṹ��
	struct Hero temp;

	//�ı��ļ����λ��
	fseek(f_read, sizeof(struct Hero) *2, SEEK_SET);

	fseek(f_read, -(long)sizeof(struct Hero) * 2, SEEK_END);

	rewind(f_read); //���ļ��������

	fread(&temp, sizeof(struct Hero), 1, f_read);

	printf("������ %s ���䣺 %d\n", temp.name, temp.age);

	fclose(f_read);

}


int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	test05();

	system("pause");
	return EXIT_SUCCESS;
}