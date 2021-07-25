#include <iostream>
using namespace std;

//����������������  
typedef int KeyType;
typedef struct Node
{
	KeyType key;          //�ؼ���  - int
	struct Node * left;   //����ָ��  
	struct Node * right;  //�Һ���ָ��
	//struct Node * parent;
}Node, *PNode;

//������������в�����  
//����Ļ�������Ҫ�ı�����ĵ�ַ�����Դ����Ƕ���ָ��  
void insertBST(PNode *root, KeyType key)
{
	//��ʼ��������  
	PNode p = new Node;
	p->key = key;
	p->left = p->right = NULL;
	//����ʱ��ֱ����Ϊ�����  
	if ((*root) == NULL)
	{
		*root = p;
		return;
	}
	//���뵽��ǰ��㣨*root��������  
	if ((*root)->left == NULL && (*root)->key > key)
	{
		(*root)->left = p;
		return;
	}
	//���뵽��ǰ��㣨*root�����Һ���  
	if ((*root)->right == NULL && (*root)->key < key)
	{
		(*root)->right = p;
		return;
	}
	//����ѭ��û�в���ڵ�, ɾ�������Ľڵ�
	delete p;
	//����������
	if ((*root)->key > key)
	{
		insertBST(&(*root)->left, key);
	}
	//����������
	else if ((*root)->key < key)
	{
		insertBST(&(*root)->right, key);
	}
}

//���ݹؼ���ɾ��ĳ�����,ɾ���ɹ�����1,���򷵻�0  
//����Ѹ����ɾ������ôҪ�ı�����ĵ�ַ�����Դ�����ָ��  
bool deleteBST(PNode* root, KeyType key)
{
	//����ֱ�ӷ���
	if (*root == NULL)
	{
		return false;
	}
	//����ҵ�ֵΪkey�Ľڵ�
	if (key == (*root)->key)
	{
		PNode q, s;	// �ڵ����͵�ָ��
		//����������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧)
		if ((*root)->right == NULL)
		{
			//����Ҫɾ���Ľڵ�ĵ�ַ
			q = *root;
			//�����������ƶ�
			// ָ������ָ�������������ĵ�ַ
			*root = (*root)->left;
			//ɾ���ڵ�,�ͷ��ڴ�
			delete q;
		}
		//������Ϊ��,ֻ���ؽ�����������
		else if ((*root)->left == NULL)
		{
			//����Ҫɾ���Ľڵ�ĵ�ַ
			q = *root;
			//�����������ƶ�
			*root = (*root)->right;
			//ɾ���ڵ�, �ͷ��ڴ�
			free(q);
		}
		//��������������
		else
		{
			//����Ҫɾ���Ľڵ�ĵ�ַ
			q = *root;
			//�����ɾ���ڵ����ӵ�ַ
			s = (*root)->left;
			//���ҵ���ͷ���Ҵ�ɾ����ǰ��,������������ҵ��Ľڵ��Ǵ�ɾ���ڵ��ǰ����
			while (s->right)
			{
				// qΪs�ĸ��ڵ�
				q = s;
				s = s->right;
			}
			//sָ��ɾ����ֱ��ǰ��������ɾ���ǰ����ֵȡ����ɾ����ֵ��
			(*root)->key = s->key;
			//�ڵ㷢��������,��root������������Ҷ�ӽڵ�
			if (q != *root)
			{
				//�ؽ�q��������
				q->right = s->left;
			}
			else
			{
				//qû���ƶ�����ָ��root
				//�ؽ�q��������
				q->left = s->left;
			}
			free(s);
		}
		return true;
	}
	//����������
	else if (key < (*root)->key)
	{
		return deleteBST(&(*root)->left, key);
	}
	//����������
	else if (key >(*root)->key)
	{
		return deleteBST(&(*root)->right, key);
	}
	return false;
}

//����Ԫ��,�ҵ����عؼ��ֵĽ��ָ�룬û�ҵ�����NULL  
PNode searchBST(PNode root, KeyType key)
{
	//û�ҵ��Ļ�rootΪNULL
	if (root == NULL)
	{
		return NULL;
	}
	//����������  
	if (key > root->key)
	{
		return searchBST(root->right, key);
	}
	//���������� 
	else if (key < root->key)
	{
		return searchBST(root->left, key);
	}
	else
	{
		return root;
	}
}

//������С�ؼ���,����ʱ����NULL  
PNode searchMinBST(PNode root)
{
	//����
	if (root == NULL)
	{
		return NULL;
	}
	//�ҵ�����ĺ���
	if (root->left == NULL)
	{
		return root;
	}
	//һֱ�������ң�ֱ��û�����ӵĽ��  
	else
	{
		return searchMinBST(root->left);
	}
}

//�������ؼ���,����ʱ����NULL  
PNode searchMaxBST(PNode root)
{
	//����
	if (root == NULL)
	{
		return NULL;
	}
	//�ҵ����ҵĺ���
	if (root->right == NULL)
	{
		return root;
	}
	//һֱ���Һ����ң�ֱ��û���Һ��ӵĽ��  
	else
	{
		return searchMaxBST(root->right);
	}
}

//����һ�ö��������  
void createBST(PNode* root, KeyType *keyArray, int length)
{
	//����������������  
	for (int i = 0; i < length; i++)
	{
		insertBST(root, keyArray[i]);
	}
}

//�����������������
void inorderTraversalBST(PNode root)
{
	if (root != NULL)
	{
		//����������
		inorderTraversalBST(root->left);
		//��ӡ���ڵ�
		cout << root->key << " ";
		//����������
		inorderTraversalBST(root->right);
	}
}

//���������������Լ�����
void test01()
{
	PNode root = NULL;
	KeyType nodeArray[11] = { 15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9 };

	//�������������
	cout << "���ڴ������������..." << endl;
	createBST(&root, nodeArray, 11);
	cout << "����������������!!!" << endl << endl;

	//�������������
	cout << "����������������(��������):" << endl;
	inorderTraversalBST(root);
	cout << endl << endl;

}

//����ָ���Ľڵ㣬�Ͳ����������
void test02()
{
	PNode root = NULL;
	KeyType nodeArray[11] = { 15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9 };

	//�������������
	cout << "���ڴ������������..." << endl;
	createBST(&root, nodeArray, 11);
	cout << "����������������!!!" << endl << endl;

	//�������������
	cout << "����������������(��������):" << endl;
	inorderTraversalBST(root);
	cout << endl << endl;

	cout << "�����������������:" << endl;
	PNode node = searchBST(root, 17);
	if (node != NULL)
	{
		cout << "�ҵ�ָ���ڵ�: " << node->key << endl;
	}
	else
	{
		cout << "û���ҵ�ָ���Ľڵ�!!!" << endl;
	}
	cout << endl;

}

//���Ҽ�ֵ
void test03()
{
	PNode root = NULL;
	KeyType nodeArray[11] = { 15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9 };

	//�������������
	cout << "���ڴ������������..." << endl;
	createBST(&root, nodeArray, 11);
	cout << "����������������!!!" << endl << endl;

	//�������������
	cout << "����������������(��������):" << endl;
	inorderTraversalBST(root);
	cout << endl << endl;


	//������С�ڵ�
	PNode minNode = searchMinBST(root);
	if (minNode != NULL)
	{
		cout << "�ҵ���Сֵ: " << minNode->key << endl;
	}
	else
	{
		cout << "�����Ϊ����!!!" << endl;
	}
	cout << endl;

	//�������ڵ�
	PNode maxNode = searchMaxBST(root);
	if (maxNode != NULL)
	{
		cout << "�ҵ����ֵ: " << maxNode->key << endl;
	}
	else
	{
		cout << "�����Ϊ����!!!" << endl;
	}
	cout << endl;
}

void test04()
{

	PNode root = NULL;
	KeyType nodeArray[11] = { 15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9 };

	//�������������
	cout << "���ڴ������������..." << endl;
	createBST(&root, nodeArray, 11);
	cout << "����������������!!!" << endl << endl;

	//�������������
	cout << "����������������(��������):" << endl;
	inorderTraversalBST(root);
	cout << endl << endl;

	//ɾ��ָ���ڵ�
	bool bl = deleteBST(&root, 18);
	if (bl)
	{
		cout << "ɾ���ڵ�ɹ�!!!" << endl;
	}
	else
	{
		cout << "ɾ���ڵ�ʧ��!!!" << endl;
	}
	//�������������
	cout << "����������������(��������):" << endl;
	inorderTraversalBST(root);
	cout << endl << endl;
}

int main()
{
	//test01();

	//test02();
	
	//test03();

	test04();


	system("pause");
	return 0;
}
