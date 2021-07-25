#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define MaxVertex 50
typedef char VertexInfo[9];

// ����ͼ�Ľṹ
struct Graph
{
	// �������� - �洢���������
	VertexInfo vertex[MaxVertex];
	// �ߵ�����
	int edge[MaxVertex][MaxVertex];
	// ����ĸ���
	int vertexNum;
	// �ߵ�����
	int edgeNum;
};

// ���û�����Ķ����ڶ��������е�λ��
int LocalVertex(Graph &g, VertexInfo v)
{
	// ������������
	for (int i = 0; i < g.vertexNum; ++i)
	{
		if (strcmp(v, g.vertex[i]) == 0)
		{
			// �ҵ���,����Ԫ�ص��±�
			return i;
		}
	}
	// û�ҵ�
	return -1;
}

// ����һ��ͼ
void CreateGraph(Graph &g)
{
	cout << "������ͼ�Ķ������ͱ���: ���� ��" << endl;
	cin >> g.vertexNum >> g.edgeNum;
	cout << "������" << g.vertexNum << "�������ֵ" << endl;
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cin >> g.vertex[i];
	}

	// ��ʼ�����б߶�������
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			g.edge[i][j] = INT_MAX;
		}
	}
	// <B, A>
	cout << "������" << g.edgeNum << "����, ��β ��ͷ Ȩ��" << endl;
	int w;
	VertexInfo v1, v2;
	for (int i = 0; i < g.edgeNum; ++i)
	{
		cin >> v1 >> v2 >> w;
		// ���û�����Ķ����ڶ��������е�λ��
		int m = LocalVertex(g, v1);
		int n = LocalVertex(g, v2);

		// �߶�Ӧ�Ķ�ά���鸳ֵ
		g.edge[m][n] = w;
	}
}
// ��ӡͼ - 
void PrintGraph(Graph& g)
{
	// ˮƽ��ͷ
	cout << "\t";
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << g.vertex[i] << "\t";
	}
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << endl;
		// ��ֱ��
		cout << g.vertex[i] << "\t";
		for (int j = 0; j < g.vertexNum; ++j)
		{
			if (g.edge[i][j] == INT_MAX)
			{
				cout << "��" << "\t";
			}
			else
			{
				cout << g.edge[i][j] << "\t";
			}
		}
	}
	cout << endl;
}

void test01()
{
	Graph g;
	CreateGraph(g);
	PrintGraph(g);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}