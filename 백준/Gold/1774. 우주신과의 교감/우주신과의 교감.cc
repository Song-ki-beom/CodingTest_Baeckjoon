#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#define MAX  1001
using namespace std;
int N, M;
int UnionBank[MAX];
vector<pair<long double, long double>> Vertexes;


struct Node
{
	int Start;
	int End;
	long double Dist;

	void findDist()
	{
		long double first = Vertexes[Start].first - Vertexes[End].first;
		long double  second = Vertexes[Start].second - Vertexes[End].second;
		Dist = sqrt(first*first + second*second);
	}
};

bool cmp(Node& a, Node& b)
{
	return a.Dist < b.Dist;
}

vector<Node> NodeBank;


int findParent(int x)
{
	if (UnionBank[x] == x) return x;
	else
	{
		return findParent(UnionBank[x]);
	}
}

void Union(int x, int y)
{
	int parentX = findParent(x);
	int parentY = findParent(y);

	if (parentX != parentY)
	{
		UnionBank[parentX] = parentY;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	std::fill(UnionBank, UnionBank + MAX, 0);
	long double answer = 0;

	cin >> N >> M;

	int y, x;
	for (int i = 0; i < N; i++)
	{
		cin >> y >> x;
		UnionBank[i] = i;
		Vertexes.push_back({ y,x });
	}

	int a, b;
	for (int j = 0; j < M; j++)
	{
		cin >> a >> b;
		Union(a-1, b-1);
	}


	for (int i = 0; i < N-1; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (i == j) continue;
			Node newNode = { i,j,0 };
			newNode.findDist();
			NodeBank.push_back(newNode);
		}
	}
	sort(NodeBank.begin(), NodeBank.end(), cmp);

	for (int i = 0; i< NodeBank.size(); i++)
	{
		Node curNode = NodeBank[i];

		if (findParent(curNode.Start) != findParent(curNode.End))
		{
			answer += curNode.Dist;
			Union(curNode.Start, curNode.End);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << answer;

}


