#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define  MYADD(x,y)  ((x) + (y))

//1���꺯����Ҫ��С�������Σ���֤�����������
//2��ͨ���ὫƵ������С�ĺ���  д�ɺ꺯��
//3���꺯�� �����ͨ������һ���̶��� Ч�ʸߣ�ʡȥ��ͨ������ջ����ջʱ���ϵĿ���
// �ŵ㣺 �Կռ� ��ʱ��


void test01()
{
	printf("%d\n", MYADD(10, 20) * 20 ); //  ((10) + (20)) * 20

}

int main(){
	test01();

	 

	system("pause");
	return EXIT_SUCCESS;
}