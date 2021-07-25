#include <iostream>
using namespace std;
/************************************************************************/
/*                    ƽ�������---AVL                                  */
/************************************************************************/
#define LH +1	//���
#define EH  0	//�ȸ�
#define RH -1	//�Ҹ�
typedef int ElemType;

//ƽ��������ڵ�ṹ
typedef struct BSTNode{
	//����
	ElemType data;
	//�ڵ��ƽ������
	int bf;
	//���Һ���ָ��
	struct BSTNode *lchild, *rchild;
}*PBSTree;

//����*pΪ���Ķ�������������������
void R_Rotate(PBSTree* p)
{
	//lcָ��*p���������ڵ�
	PBSTree lc = (*p)->lchild;
	//*p���������ҽ�lc��������
	(*p)->lchild = lc->rchild;
	lc->rchild = *p;
	*p = lc;
}

//����*pΪ���Ķ�������������������
void L_Rotate(PBSTree* p)
{
	//rcָ��*p���������ĸ��ڵ�
	PBSTree rc = (*p)->rchild;
	//*P���������ҽ�rc��������
	(*p)->rchild = rc->lchild;
	rc->lchild = *p;
	*p = rc;
}

//����ָ��T��ָ�ڵ�Ϊ���Ķ���������ƽ����ת����
void LeftBalance(PBSTree* T)
{
	PBSTree lc, rd;
	//lcָ��T���������ڵ�
	lc = (*T)->lchild;
	//���*T��������ƽ���,������Ӧ����
	switch (lc->bf)
	{
		//�½ڵ������*T�����ӵ���������,Ҫ������������
	case LH:
		(*T)->bf = lc->bf = EH;
		R_Rotate(T);
		break;
		//�½ڵ������*T�����ӵ���������,Ҫ��˫������
	case RH:
		//rdָ��*T���ӵ����������ڵ�
		rd = lc->rchild;
		//�޸�*T�������ӵ�ƽ������
		switch (rd->bf)
		{
		case LH:
			(*T)->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		//��*T��������������ƽ�⴦��
		L_Rotate(&(*T)->lchild);
		//��*T������ƽ�⴦��
		R_Rotate(T);
		break;
	}
}

//����ָ��T��ָ�ڵ�Ϊ���Ķ���������ƽ����ת����
void RightBalance(PBSTree* T)
{
	PBSTree lc, rd;
	//lcָ��*T���������ĸ��ڵ�
	lc = (*T)->rchild;
	//���*T����������ƽ���,������Ӧ��ƽ�⴦��
	switch (lc->bf)
	{
		//�½ڵ������*T���Һ��ӵ���������,Ҫ������������
	case RH:
		(*T)->bf = lc->bf = EH;
		L_Rotate(T);
		break;
		//�½ڵ������*T���Һ��ӵ���������,Ҫ��˫������
	case LH:
		//rdָ��*T���Һ��ӵ����������ڵ�
		rd = lc->lchild;
		//�޸�*T�����Һ��ӵ�ƽ������
		switch (rd->bf)
		{
		case LH:
			(*T)->bf = EH;
			lc->bf = RH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		//��*T��������������ƽ�⴦��
		R_Rotate(&(*T)->rchild);
		//��*T������ƽ�⴦��
		L_Rotate(T);
		break;
	}
}

//��ƽ��������в���ڵ�e
int InsertAVL(PBSTree* T, ElemType e, bool* taller)
{
	//����ǿ���
	if ((*T) == NULL)
	{
		//�����½ڵ�
		(*T) = new BSTNode;
		//ƽ��
		(*T)->bf = EH;
		//��ʼ��
		(*T)->data = e;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		//�����½ڵ�,������,��tallerΪtrue
		*taller = true;
	}
	//��������ظ�ֵ,ֱ�ӷ���
	else if (e == (*T)->data)
	{
		*taller = false;
		return 0;
	}
	//�������ֵ С�� ���ڵ�
	else if (e < (*T)->data)
	{
		//ֵ�ظ�
		if (!InsertAVL(&(*T)->lchild, e, taller))
			return 0;
		//�ڵ���뵽������,����������
		if (*taller)
		{
			//���T��ƽ���
			switch ((*T)->bf)
			{
				//ԭ������������������,��Ҫ��ƽ�⴦��
			case LH:
				LeftBalance(T);
				*taller = false;
				break;
				//ԭ�����������ȸ�,��������������,ʹ������
			case  EH:
				(*T)->bf = LH;
				*taller = true;
				break;
				//ԭ������������������,�������������ȸ�
			case RH:
				(*T)->bf = EH;
				*taller = false;
				break;
			}
		}
	}
	//�������ֵ ���� ���ڵ�
	else
	{
		//ֵ�ظ�
		if (!InsertAVL(&(*T)->rchild, e, taller))
			return 0;
		//�½ڵ��Ѳ��뵽T����������, ����������
		if (*taller)
		{
			//���T��ƽ���
			switch ((*T)->bf)
			{
				//ԭ������������������,�������������ȸ�
			case LH:
				(*T)->bf = EH;
				*taller = false;
				break;
				//ԭ�����������ȸ�,��������������ʹ������
			case EH:
				(*T)->bf = RH;
				*taller = true;
				break;
				//ԭ������������������,��Ҫ����ƽ�⴦��
			case  RH:
				RightBalance(T);
				*taller = false;
				break;
			}
		}
	}
	return 1;
}

//����ָ��ֵ���ҽڵ�
bool FindNode(PBSTree root, ElemType e, PBSTree* pos)
{
	//���帨��ָ�����,ָ����ڵ�
	PBSTree pt = root;
	//ָ���ʼ��
	(*pos) = NULL;
	//�Ӹ��ڵ㿪ʼ���²���
	while (pt)
	{
		if (pt->data == e)
		{
			//�ҵ��ڵ㣬posָ��ýڵ㲢����true
			(*pos) = pt;
			return true;
		}
		else if (pt->data > e)
		{
			//���ָ����ֵ�ȸ��ڵ��,����������
			pt = pt->lchild;
		}
		else
		{
			//���ָ����ֵ�ȸ��ڵ�С,����������
			pt = pt->rchild;
		}
	}
	return false;
}

//�������
void InorderTra(PBSTree root)
{
	//����������
	if (root->lchild != NULL)
	{
		InorderTra(root->lchild);
	}
	//���ʸ��ڵ�
	cout << root->data << " ";
	//����������
	if (root->rchild != NULL)
	{
		InorderTra(root->rchild);
	}
}

#if 0
int main()
{
	int i, nArr[] = { 4, 5, 7, 2, 1, 3, 6 };
	PBSTree root = NULL, pos;
	bool taller;
	for (i = 0; i<sizeof(nArr) / sizeof(int); i++)
	{
		InsertAVL(&root, nArr[i], &taller);
	}
	InorderTra(root);
	cout << endl << "start find 103 ..." << endl;
	if (FindNode(root, 103, &pos))
	{
		cout << "Find this Node " << pos->data << endl;
	}
	else
	{
		cout << "Not find this Node��" << endl;
	}

	cout << endl << "start find 7 ..." << endl;
	if (FindNode(root, 7, &pos))
	{
		cout << "Find this Node " << pos->data << endl;
	}
	else
	{
		cout << "Not find this Node" << endl;;
	}

	system("pause");
	return 0;
}
#endif
