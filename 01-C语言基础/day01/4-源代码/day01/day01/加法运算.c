#include <stdio.h>


int main(void)
{

	int a = 3;		// ���� ���ͱ��� a�� ����ֵ 3

	int b = 5;		// ���� ���ͱ��� b�� ����ֵ 5
	int c;			// ���� ���ͱ��� c�� �޳�ֵ
	
	c = a + b;		// a + b ,����� ��ֵ �� c

	printf("hello world\n");

	// %d:��ʽƥ�����ƥ����������

	printf("%d\n", c /*ע��*/ );	


	printf("c = %d\n", c);

	printf("%d + %d = %d\n", a, b, c);

	printf("%d + %d = &d\n", a, b, a+b);

	return 0;
}
