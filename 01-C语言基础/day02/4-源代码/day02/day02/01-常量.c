#include <stdio.h>

#define PI 3.1415			// ����

int main01(void)
{
	// Բ�����  s = PI x �뾶��ƽ��
	// Բ���ܳ�  l = 2 * PI * r	
	//int r = 3;				// ����
	const int r = 3;		// ֻ������

	float s = PI * r * r;
	float l = 2 * PI * r;

	//printf("Բ���ܳ�Ϊ��%f\n", l);  //18.849001
	//printf("Բ�����Ϊ��%f\n", s);  //28.273500

	printf("Բ���ܳ�Ϊ��%.2f\n", l);	// ָ��С�������2λ, �Ե�3λ����4������
	printf("Բ�����Ϊ��%.2f\n", s);	// ָ��С�������2λ

	return 0;
}
