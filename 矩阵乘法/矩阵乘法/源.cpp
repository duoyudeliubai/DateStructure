#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 50;
int G[MAX][MAX];
int bestx[MAX];
int w[MAX];     //�����Ȩ
int n, e; //��·���������ӿ���

class Node
{
public:
	int dep;  //��ǰ��
	int val;  //��������Ȩֵ֮��
	int *x;   //������
	int *c;   //���ϵ���һ������

	Node()
	{
		x = new int[n + 1];
		c = new int[n + 1];
	}

	//��ǰ���г���С���ȳ�����
	bool operator < (const Node &node) const
	{
		return val >= node.val;
	}
};

priority_queue<Node> q;

//�ж�ͼ�Ƿ�����ȫ����
bool cover(Node E)
{
	for (int i = 1; i <= n; i++)
		if (E.x[i] == 0 && E.c[i] == 0)
			return false;
	return true;
}

//��ӽ��
void addNode(Node enode, int i, int v, bool isLeft)
{
	Node now;
	now.dep = i;
	copy(enode.x, enode.x + n + 1, now.x);
	copy(enode.c, enode.c + n + 1, now.c);
	if (isLeft)
	{
		now.val = v + w[i];
		now.x[i] = 1;
		for (int j = 1; j <= n; j++)
			if (G[j][i])
				now.c[j]++;
	}
	else
	{
		now.val = v;
		now.x[i] = 0;
	}
	q.push(now);
}

int search()
{
	Node enode;
	for (int j = 1; j <= n; j++)
	{
		enode.x[j] = 0;
		enode.c[j] = 0;
	}
	int best;
	int i = 1;
	int val = 0;
	while (true)
	{
		if (i>n)
		{
			if (cover(enode))
			{
				best = val;
				copy(enode.x, enode.x + n + 1, bestx);
				break;
			}
		}
		else
		{
			if (!cover(enode))
				addNode(enode, i, val, true);
			addNode(enode, i, val, false);
		}
		if (q.empty())
			break;
		else
		{
			enode = q.top();
			q.pop();
			i = enode.dep + 1;
			val = enode.val;
		}
	}
	return best;
}

int main()
{
	ifstream fin("���㸲��.txt");
	cout << "����ͼ�Ķ�������";
	fin >> n; cout << n;
	cout << "\n����ͼ�ı�����";
	fin >> e; cout << e;
	cout << "\n���붥���Ȩ��\n";
	int i;
	for (i = 1; i <= n; i++)
	{
		fin >> w[i];
		cout << w[i] << " ";
	}
	cout << "\n����ÿ���ߣ�\n";
	int a, b;
	memset(G, 0, sizeof(G));
	for (i = 1; i <= e; i++)
	{
		fin >> a >> b;
		G[a][b] = G[b][a] = 1;
		cout << a << " " << b << endl;
	}

	cout << "\n��С���㸲��Ȩ֮��Ϊ��" << search();
	cout << "\n���Ž�Ϊ��\n";
	for (i = 1; i <= n; i++)
		cout << bestx[i] << " ";

	cout << endl;
	cout << endl;
	fin.close();
	return 0;
}