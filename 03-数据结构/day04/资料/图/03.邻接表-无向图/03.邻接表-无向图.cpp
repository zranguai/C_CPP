#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#if 1
#define MaxVertex 100
// �ڽӵ�Ľṹ��
struct edgeNode
{
	// ��ǰ�����ڶ��������е�λ��
	int position;
	// ָ���̽ڵ��ָ��
	struct edgeNode* next;
	// �ڵ���ص���Ϣ - info
	int weight;
};

// ��������Ľṹ��
struct Vertex
{
	// ���������
	char name[9];
	// ָ���ٽӵ�ṹ��ָ��
	struct edgeNode* first;
};
// �ڽӱ�ͼ�ṹ
struct GraphList
{
	// ��������
	Vertex head[MaxVertex];
	// ����ĸ���
	int vertexNum;
	// �ߵ�����
	int edgeNum;
};

int LocalVertex(GraphList&g, char* name)
{
	for (int i = 0; i < g.vertexNum; ++i)
	{
		if (strcmp(name, g.head[i].name) == 0)
		{
			return i;
		}
	}
	return -1;	// û�ҵ�
}

// ����һ��ͼ
void CreateGraph(GraphList &g)
{
	cout << "������ͼ�Ķ������ͱ���: ���� ��" << endl;
	cin >> g.vertexNum >> g.edgeNum;
	cout << "������" << g.vertexNum << "�������ֵ" << endl;
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cin >> g.head[i].name;
		g.head[i].first = NULL;	// Ŀǰû���ڽӵ�
	}

	cout << "������" << g.edgeNum << "����, ����1 ����2" << endl;
	char v1[9], v2[9];
	for (int i = 0; i < g.edgeNum; ++i)
	{
		cin >> v1 >> v2;
		// ��MΪͷ��������, n��m��;�ڽӵ�
		// ���û�����Ķ����ڶ��������е�λ��
		int m = LocalVertex(g, v1);
		int n = LocalVertex(g, v2);

		// ����������ڽӵ�
		edgeNode* pNew = new edgeNode;
		// init pNew
		pNew->position = n;	// ��ǰ�Ľڵ��ڶ��������е�λ��
		// pNew��ӵ�ͷ��������m��Ԫ�� ��Ӧ��������
		// ͷ�巨  β�巨��Ҫ������β�� ���鷳�������ͷ�巨
		pNew->next = g.head[m].first;
		g.head[m].first = pNew;
#if 1
		// ��NΪͷ��������, m��n��;�ڽӵ�
		edgeNode* pNew1 = new edgeNode;
		// init pNew1
		pNew1->position = m;	// ��ǰ�Ľڵ��ڶ��������е�λ��
		// pNew��ӵ�ͷ��������m��Ԫ�� ��Ӧ��������
		// ͷ�巨
		pNew1->next = g.head[n].first;
		g.head[n].first = pNew1;
#endif
	}
}
// ��ӡͼ
void PrintGraphList(GraphList& g)
{
	for (int i = 0; i < g.vertexNum; ++i)
	{
		edgeNode* pNode = g.head[i].first;
		cout << g.head[i].name << ": ";
		while (pNode != NULL)
		{
			int index = pNode->position;
			cout << g.head[index].name << " ,";
			pNode = pNode->next;
		}
		cout << endl;
	}
	cout << endl;
}

// �����������
void DFS(GraphList& g)
{
	// ��֤���㲻���ظ�����
	bool* visited = new bool[g.vertexNum];
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}
	// �Ӷ�����������һ������, ��ʼ���� - 0
	stack<int> st;	// int - �����ڶ��������е��±�
	st.push(0);
	// ����
	visited[0] = true;
	cout << g.head[0].name << " ";

	// ��ջΪ��, �������
	while (!st.empty())
	{
		// �����ڶ��������е��±�ȡ����
		int top = st.top();
		// ���±��Ӧ�Ķ�����ڽӵ�
		edgeNode* pNode = g.head[top].first;
		while (pNode)
		{
			// ����ڵ㱻��������
			while (pNode && visited[pNode->position])
			{
				// ָ�����
				pNode = pNode->next;
			}
			// �ҵ���û�б����ʵ�
			if (pNode)
			{
				// ����
				visited[pNode->position] = true;
				cout << g.head[pNode->position].name << " ";
				// ���µĶ���pNode->position���ڽӵ�
				// ���������ֱ������ת
				pNode = g.head[pNode->position].first;
				st.push(pNode->position);
			}
		}
		st.pop();
	}
	delete[] visited;
}

void BFS(GraphList& g)
{
	// ��֤���㲻���ظ�����
	bool* visited = new bool[g.vertexNum];
	// init
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}
	// �Ӷ�����������һ������, ��ʼ���� - 0
	queue<int> q;	// int - �����ڶ��������е��±�
	q.push(0);
	// ����
	visited[0] = true;
	cout << g.head[0].name << " ";

	// ����Ϊ��,�������
	while (!q.empty())
	{
		// ȡ����ͷԪ��ֵ, �����ڶ��������е��±�
		int front = q.front();
		// �Ҷ�ͷԪ�ض�Ӧ�Ķ�������е��ڽӵ�
		edgeNode* pNode = g.head[front].first;
		while (pNode)
		{
			// ���û�б�����
			if (!visited[pNode->position])
			{
				visited[pNode->position] = true;
				cout << g.head[pNode->position].name << " ";
				// �ڽӵ������
				q.push(pNode->position);
			}
			pNode = pNode->next;
		}
		// ���е��ٽ�㷢ȫ��������
		q.pop();
	}
	delete[] visited;
}

int main()
{
	GraphList g;
	CreateGraph(g);
	PrintGraphList(g);

	system("pause");
	return 0;
}

#endif