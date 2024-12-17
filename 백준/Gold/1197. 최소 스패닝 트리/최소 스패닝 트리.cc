#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#define MAX 10001
#define INF 2147483649

using namespace std;
int V, E;
bool Visited[MAX];
vector<vector<pair<int, int>>> EdgeBank;

struct Edge
{
	long long int cost;
	int start;
	int end;
};

struct cmp
{
	bool operator() (Edge a, Edge b)
	{
		return a.cost > b.cost;
	}
};
priority_queue<Edge, vector<Edge> , cmp> pq;


long long int Kruskal()
{
	long long int totalCost = 0;

	while (!pq.empty())
	{

		Edge curEdge = pq.top();
		pq.pop();
		if (Visited[curEdge.start] && Visited[curEdge.end]) continue;
		

		if (!Visited[curEdge.start])
		{
			Visited[curEdge.start] = true;
			for (pair<int,int> NearEdge :EdgeBank[curEdge.start])
			{
				if (Visited[NearEdge.first] && Visited[curEdge.start]) continue;
				pq.push({NearEdge.second,curEdge.start , NearEdge.first});
			}

		}
	    if (!Visited[curEdge.end])
		{
			Visited[curEdge.end] = true;
			for (pair<int, int> NearEdge : EdgeBank[curEdge.end])
			{
				if (Visited[NearEdge.first] && Visited[curEdge.end]) continue;
				pq.push({ NearEdge.second,curEdge.end , NearEdge.first });
			}

		}
		totalCost += curEdge.cost;

	}

	return totalCost;

}





int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> V >> E;
	int a, b, c;
	
	std::fill(Visited, Visited + V + 1, false);
	Edge shortestEdge = {INF,-1,-1};
	EdgeBank.assign(V + 1, vector<pair<int,int>>());
	for (int i = 0; i < E ; i++)
	{
		cin >> a >> b >> c;
		EdgeBank[a].push_back({ b,c });
		EdgeBank[b].push_back({ a,c });

		if (c < shortestEdge.cost)
		{
			shortestEdge.cost = c;
			shortestEdge.start = a;
			shortestEdge.end = b;
		}

	}
	pq.push(shortestEdge);

	cout << Kruskal();
	
}

