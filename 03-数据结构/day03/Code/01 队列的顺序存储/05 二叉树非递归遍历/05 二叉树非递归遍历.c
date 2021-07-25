#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

struct BinaryNode
{
	//������
	char ch;
	//ָ����
	struct BinaryNode * lChild;
	struct BinaryNode * rChild;
	//��־
	int flag;
};


/*
1�������ڵ� ��ջ 
2��ֻҪջ��Ԫ�ظ������� 0  ִ��ѭ��
	��ȡջ��Ԫ��
	��ջ
	�����־λ��  ֱ�����  ����ִ����һ��ѭ��
	���Ϊ�� ����־��Ϊ��
	��������  ������ �� ��ջ
	ִ����һ��ѭ��
*/

void nonRecursion(struct BinaryNode * root)
{
	//��ʼ��ջ
	SeqStack myStack = init_SeqStack();

	push_SeqStack(myStack, root);

	while (size_SeqStack(myStack) > 0)
	{
		//��ȡջ��Ԫ��
		struct BinaryNode * pTop = top_SeqStack(myStack);

		//��ջ
		pop_SeqStack(myStack);

		//�����־λ��  ֱ�����  ����ִ����һ��ѭ��
		if (pTop->flag == 1)
		{
			printf("%c ", pTop->ch);
			continue;
		}
		//���Ϊ�� ����־��Ϊ��
		pTop->flag = 1;

		//��������  ������ �� ��ջ
		if (pTop->rChild != NULL)
		{
			push_SeqStack(myStack, pTop->rChild);
		}
		if (pTop->lChild != NULL)
		{
			push_SeqStack(myStack, pTop->lChild);
		}
		push_SeqStack(myStack, pTop);

	}

	//����ջ
	destroy_SeqStack(myStack);

}

void test01()
{
	struct BinaryNode nodeA = { 'A', NULL, NULL,0 };
	struct BinaryNode nodeB = { 'B', NULL, NULL,0 };
	struct BinaryNode nodeC = { 'C', NULL, NULL,0 };
	struct BinaryNode nodeD = { 'D', NULL, NULL,0 };
	struct BinaryNode nodeE = { 'E', NULL, NULL,0 };
	struct BinaryNode nodeF = { 'F', NULL, NULL,0 };
	struct BinaryNode nodeG = { 'G', NULL, NULL,0 };
	struct BinaryNode nodeH = { 'H', NULL, NULL,0 };

	//������ϵ
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//�ǵݹ����
	nonRecursion(&nodeA);

	



}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}