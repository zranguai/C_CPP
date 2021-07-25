#include <iostream>
#include <stack>
#include <queue>
using namespace std;


//���嶥������ֵ
#define MaxVertex 50
//���嶥������
typedef char VertexInfo[4];
//����һ��ͼ�Ľṹ��
struct Graph
{
	//һά���� -- ������Ϣ
	VertexInfo vertex[MaxVertex];
	//��ά���� -- �߻��߻� ��Ӧ��ϵ ���� Ȩ
	int edge[MaxVertex][MaxVertex];
	//����ĸ���
	int vertexNum;
	//�ߵ�����
	int edgeNum;
};

//Ѱ�Ҷ�����һά�����е�λ��
int localVertex(Graph &g, VertexInfo v)
{
	//������������
	for (int i = 0; i < g.vertexNum; ++i)
	{
		//Ѱ��ֵ��v��ȵĶ���
		if (strcmp(v, g.vertex[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}

//���ڽӾ��󴴽�ͼ -- �������ͼ
void createGraph(Graph &g)
{
	cout << "����ͼ�Ķ������ͱ���(�ÿո���)" << endl;
	cin >> g.vertexNum >> g.edgeNum;

	cout << "������ͼ��" << g.vertexNum << "������: " << endl;
	//ѭ������
	for (int i = 0; i < g.vertexNum; ++i)
	{
		//���ն����ֵ
		cin >> g.vertex[i];
	}

	//��ʼ������֮��Ķ�Ӧ��ϵ
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			//��ʼ��Ϊ���ֵ
			g.edge[i][j] = INT_MAX;
		}
	}

	//�������
	int w;	//Ȩ��
	VertexInfo v1, v2;	//����
	//����ߺ�Ȩ��
	cout << "��������" << g.edgeNum << "���ߵ� ��β ��ͷ  Ȩ��" << endl;
	//ѭ������
	for (int i = 0; i < g.edgeNum; i++)
	{
		cin >> v1 >> v2 >> w;

		//�ҵ�v1��һά�����е�λ��
		int m = localVertex(g, v1);
		//�ҵ�v2��һά�����е�λ��
		int n = localVertex(g, v2);
		//��ֵ
		g.edge[m][n] = w;
		//���������ͼ
		g.edge[n][m] = w;
	}
}

//��ӡͼ
void printGraph(Graph &g)
{
	cout << "��ӡͼ -- �ڽӾ���:" << endl;
	cout << "\t";
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << g.vertex[i] << "\t";
	}
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << endl;
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

//�����������
void DFS(Graph &g)
{
	//����һ������,��ǽڵ��Ƿ��Ѿ�������
	bool *visited = new bool[g.vertexNum];
	//�����ʼ��
	for (int i = 0; i < g.vertexNum; ++i)
	{
		//ȫ�����Ϊδ����
		visited[i] = false;
	}

	//����ջ����
	stack<int> st;
	//������ĵ�һ�����㿪ʼ
	//���ʵ�һ������
	visited[0] = true;
	//��ӡ��һ������
	cout << g.vertex[0] << " ";
	//�±�ѹջ
	st.push(0);

	while (!st.empty())
	{
		int i;
		for (i = 0; i < g.vertexNum; ++i)
		{
			//ȡ������
			int top = st.top();
			//������ڽӵ� -- û�б����ʹ�
			if (!visited[i] && g.edge[top][i] < INT_MAX)
			{
				//����
				visited[i] = true;
				//��ӡ
				cout << g.vertex[i] << " ";
				//�±�ѹջ
				st.push(i);
			}
		}
		//������һ��,ջ��Ԫ�س�ջ
		if (i >= g.vertexNum)
		{
			st.pop();
		}
	}

	delete[] visited;
}

//�����������
void BFS(Graph &g)
{
	//����һ������,��Ƕ����Ƿ񱻷���
	bool *visited = new bool[g.vertexNum];
	//��ʼ��
	for (int i = 0; i < g.vertexNum; ++i)
	{
		//false -- δ����
		visited[i] = false;
	}

	//����һ�����ж���
	queue<int> q;
	//��һ��������Ϊ�ѷ���
	visited[0] = true;
	//��ӡ��һ������
	cout << g.vertex[0] << " ";
	//�����������е��±�,�����
	q.push(0);

	while (!q.empty())
	{
		int front = q.front();
		for (int i = 0; i < g.vertexNum; ++i)
		{
			//Ѱ�Ҷ����ж�ͷ�Ķ�����ڽӵ�
			if (!visited[i] && g.edge[front][i] < INT_MAX)
			{
				//���Ϊ�ѷ���
				visited[i] = true;
				//��ӡ
				cout << g.vertex[i] << " ";
				//�±������
				q.push(i);
			}
		}
		//Ѱ�������е��ڽӵ�֮��,�±������
		q.pop();
	}
	delete[] visited;
}

// ���·��
// �Ͻ�˹����(Dijkstra)�㷨
// path��һ���㵽��ǰ��ľ������
void dijkstraPath(Graph &g, int *path, int *dist, int v0)
{
	int min = 0;
	int pos = v0;	// ���ʵ���ʼ����
	//����һ������, ��Ƕ����Ƿ��Ѿ�������
	bool *visited = new bool[g.vertexNum];
	//��ʼ��
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;	//����δ����
		if (i != v0) //�ų����㵽������ļ���
		{
			//��ʼ�����е������ڽӵ㶼��V0��
			path[i] = v0;
			// v0�����������Ȩ��
			dist[i] = g.edge[v0][i];
			cout << g.vertex[v0] << " �� " << g.vertex[i]
				<< " ����: dist[" << i << "]=" << dist[i] << endl;
		}
		else
		{
			// path[]���� - ����ǰ���������ڽӵ�
			// dist[] ���� - �ӳ����㵽���������̾���
			// i == v0û���κ�����, ������·��
			path[i] = -1;
			dist[i] = INT_MAX;
		}
	}
	//��v0���Ϊ�ѷ���
	visited[v0] = true;

	for (int i = 0; i < g.vertexNum; ++i)
	{
		min = INT_MAX;
		for (int j = 0; j < g.vertexNum; ++j)
		{
			// û�б�����, �����ҵ���ӵ�и�СȨֵ�ı�
			// path[]���� - ����ǰ���������ڽӵ�
			// dist[] ���� - �ӳ����㵽���������̾���
			if (!visited[j] && min>dist[j])
			{
				//������Сֵ
				min = dist[j];
				//����λ��
				pos = j;
				cout << "+++ �������: pos =" << pos
					<< "����Ϊ: " << g.vertex[pos] << endl;
			}
		}
		//posλ�õĶ�����Ϊ�ѷ���
		visited[pos] = true;

		// dist V0�㵽������ľ���
		for (int j = 0; j < g.vertexNum; ++j)
		{
			// g.edge[pos][j] < INT_MAX - �ж�pos->j�������Ǵ��ڵ�
			if (!visited[j] && dist[pos] + g.edge[pos][j] < dist[j] && g.edge[pos][j] < INT_MAX)
			{
				// ������̾���
				//���� ��j����E  pos����B�����A��E���·��
				dist[j] = dist[pos] + g.edge[pos][j];
				//����·��, ������j����Ķ�����pos
				path[j] = pos;
				cout << "=== ������̾���: dist[" << j
					<< "] = " << dist[j] << endl;
			}
		}
	}
}

// v0 - ��ʼ��
// v  - �����
void showPath(Graph &g, int *path, int v0, int v)
{
	//����һ��ջ����
	stack<int> st;
	int temp = v;
	while (temp != v0)
	{
		st.push(temp);
		//Ѱ����һ������
		temp = path[temp];
	}
	st.push(v0);

	//��ӡ·��
	while (!st.empty())
	{
		cout << g.vertex[st.top()] << " ";
		st.pop();
	}
}

int main()
{
	//����һ��ͼ�Ķ���
	Graph g;
	//���ڽӾ��󴴽�ͼ
	createGraph(g);
	//��ӡ
	printGraph(g);

	//�����������
	cout << "�����������" << endl;
	DFS(g);
	cout << endl;

	//�����������
	cout << "�����������" << endl;
	BFS(g);
	cout << endl;

	/*==================================================
	==================================================*/
	cout << "�Ͻ�˹����(Dijkstra)�㷨" << endl;
	// path���� - ����ǰ���������ڽӵ�
	int path[50];
	// dist[] ���� - �ӳ����㵽���������̾���
	int dist[50];
	// ������
	int v0 = 0;
	dijkstraPath(g, path, dist, v0);
	// A->D��ô��?��ô��?
	// dist[3] = A->D����̾���
	// path[3]
	for (int i = 1; i < g.vertexNum; ++i)
	{
		cout << "·��: ";
		showPath(g, path, v0, i);
		cout << "·������: " << dist[i] << endl;
	}

	cout << "Keyboard not found, press F1 to continue..." << endl;
	system("pause");
	return 0;
}
