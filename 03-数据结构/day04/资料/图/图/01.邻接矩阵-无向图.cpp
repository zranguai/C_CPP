#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//���Ķ�����
#define MaxVertex 50 
//��Ŷ������Ƶ�����
typedef char VertexInfo[9];


// ����ͼ�Ľṹ
struct Graph
{
	// �������� - �洢���������  �ȼ���  vertex[MaxVertex][9]  �����MaxVertex������
	VertexInfo vertex[MaxVertex];
	// �ߵ�����  ��ά����
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
		cin >> g.vertex[i]; //��ʼ��ÿ������
	}

	// ��ʼ�����б߶�������
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			g.edge[i][j] = 0;
		}
	}
	cout << "������" << g.edgeNum << "����, ����1 ����2" << endl;
	VertexInfo v1, v2;
	for (int i = 0; i < g.edgeNum; ++i)
	{
		cin >> v1 >> v2;
		// ���û�����Ķ����ڶ��������е�λ��
		int m = LocalVertex(g, v1); //��ȡv1�ڶ�ά�����е�λ��
		int n = LocalVertex(g, v2); //��ȡv2�ڶ�ά�����е�λ��

		// �߶�Ӧ�Ķ�ά���鸳ֵ
		g.edge[m][n] = 1;
		g.edge[n][m] = 1;	// ����ͼ �Գƹ�ϵ
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
			cout << g.edge[i][j] << "\t";
		}
	}
	cout << endl;
}


// �����������
void DFS(Graph& g)
{
	bool* visited = new bool[g.vertexNum];
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}

	// �Ӷ��������еĵ�һ����ʼ����
	stack<int> st;	// int - ����������±�
	visited[0] = true;
	cout << g.vertex[0] << " ";
	st.push(0);

	while (!st.empty())
	{
		// �������еĶ���, ���ڽӵ� - ջ��Ԫ�ض�Ӧ���ڽӵ�
		for (int i = 0; i < g.vertexNum; ++i)
		{
			// ջ��Ԫ���ڶ��������е�λ��
			int top = st.top();
			if (!visited[i] && g.edge[top][i] > 0)
			{
				// �����ö���
				visited[i] = true;
				cout << g.vertex[i] << " ";
				// �ڽӵ�ѹջ
				st.push(i);
			}
		}
		// ջ���Ķ���������Ķ�����ɵı�ȫ���ж���һ��
		st.pop();
	}
	delete[] visited;
}

// �����������
void BFS(Graph& g)
{
	// ��֤���㲻���ظ�����
	bool* visited = new bool[g.vertexNum];
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}

	// ��һ������, ��ʼ���� - 0
	queue<int> q;	// �洢������±�
	visited[0] = true;
	cout << g.vertex[0] << " ";
	q.push(0);

	// �������Ϊ��, �������
	while (!q.empty())
	{
		// ��ͷ������±�ֵ�ó���
		int front = q.front();
		// �������еĶ���, ���ڽӵ�
		for (int i = 0; i < g.vertexNum; ++i)
		{
			// ���û������, ���������㻥Ϊ�ڽӵ�
			if (!visited[i] && g.edge[front][i] > 0)
			{
				// ����,���������
				visited[i] = true;
				cout << g.vertex[i] << " ";
				q.push(i);
			}
		}
		// ���е��ڽӵ㶼�������,������
		q.pop();
	}
	delete[] visited;
}


//����ͼ
void test01()
{
	Graph graph;
	CreateGraph(graph);
	PrintGraph(graph);
}

//�����������
void test02()
{
	Graph graph;
	CreateGraph(graph);
	PrintGraph(graph);

	DFS(graph);
}



int main(){

	test01();


	system("pause");
	return EXIT_SUCCESS;
}