#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//ע������1
void test01()
{
	FILE * f_read = fopen("./test.txt", "r");
	if (f_read == NULL)
	{
		return;
	}

	char ch;

#if 0
	//aaaaaaaaaEOF
	//         |
	while ( !feof(f_read))
	{
		ch = fgetc(f_read);

		if (feof(f_read))
		{
			break;
		}

		printf("%c", ch);
	}
#endif 

	while ( ( ch = fgetc(f_read)) != EOF)
	{
		printf("%c", ch);
	}

	fclose(f_read);

}

//ע������2 
struct Hero
{
	char * name; //������Կ��ٵ���������Ҫ��ָ�뵽�ļ��У�Ҫ��ָ��ָ������ݴ�ŵ��ļ���
	int age;
};


int main(){
	test01();
	//printf(" aaaaa\n");
	//printf("%caaaaa\n",EOF);
	system("pause");
	return EXIT_SUCCESS;
}