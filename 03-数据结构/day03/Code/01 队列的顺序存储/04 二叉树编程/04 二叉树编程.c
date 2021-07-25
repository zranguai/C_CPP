#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BinaryNode
{
	//������
	char ch;
	//ָ����
	struct BinaryNode * lChild;
	struct BinaryNode * rChild;
};


void calculateLeafNum(struct BinaryNode * root, int * p)
{
	if (root == NULL)
	{
		return;
	}

	//����ڵ� ������ �������� ͬʱΪ��  ��ΪҶ��
	if (root->lChild == NULL && root->rChild == NULL)
	{
		(*p)++;
	}

	calculateLeafNum(root->lChild, p);

	calculateLeafNum(root->rChild, p);

}

//��ȡ���߶�
int getTreeHeight(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return 0;
	}

	//��ȡ�������߶� 
	int  lHeight = getTreeHeight(root->lChild);
	//��ȡ�������߶�
	int  rHeight = getTreeHeight(root->rChild);
	//������������������ȡ���ֵ+1
	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;

	return height;
}

//����������
struct BinaryNode * copyTree(struct BinaryNode * root)
{
	if (root ==NULL)
	{
		return NULL;
	}

	//�ȿ���������
	struct BinaryNode * lChild = copyTree(root->lChild);
	//�ٿ���������
	struct BinaryNode * rChild = copyTree(root->rChild);

	struct BinaryNode * newNode = malloc(sizeof(struct BinaryNode));
	newNode->ch = root->ch;

	newNode->lChild = lChild;

	newNode->rChild = rChild;

	return newNode;
}

void recursion(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return;
	}

	printf("%c ", root->ch);

	recursion(root->lChild);

	recursion(root->rChild);

}


void freeTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return;
	}

	//���ͷ�������
	freeTree(root->lChild);
	//���ͷ�������
	freeTree(root->rChild);
	//�ͷŸ�
	printf("%c���ͷ���\n", root->ch);
	free(root);
}

void test01()
{
	struct BinaryNode nodeA = { 'A', NULL, NULL };
	struct BinaryNode nodeB = { 'B', NULL, NULL };
	struct BinaryNode nodeC = { 'C', NULL, NULL };
	struct BinaryNode nodeD = { 'D', NULL, NULL };
	struct BinaryNode nodeE = { 'E', NULL, NULL };
	struct BinaryNode nodeF = { 'F', NULL, NULL };
	struct BinaryNode nodeG = { 'G', NULL, NULL };
	struct BinaryNode nodeH = { 'H', NULL, NULL };

	//������ϵ
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//1��������� Ҷ������
	int num = 0;
	calculateLeafNum(&nodeA, &num);

	printf("����Ҷ������Ϊ��%d\n", num);


	//2�� �����ĸ߶�/���
	int height = getTreeHeight( &nodeA);

	printf("���ĸ߶�Ϊ��%d\n", height);


	//3�� ����������
	struct BinaryNode * newTree = copyTree(&nodeA);

	//�ݹ����
	recursion(newTree);

	printf("\n");
	//4�� �ͷŶ�����
	freeTree(newTree);


}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}