#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <climits>
#define MAX 1001
#define DISTMAX 100000001
using namespace std;

int N, M;
 int DP[MAX];
vector<vector<pair<int,int>>> Arr;



int DaikStra(int start , int end)
{
	

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	DP[start] = 0;
	pq.push({ start,0 });
	while (!pq.empty())
	{
		int curNode = pq.top().first;
		int curCost = pq.top().second;
		pq.pop();

		if (curCost > DP[curNode]) continue;

		for (pair<int,int> Edge : Arr[curNode])
		{
			if (DP[Edge.first] > DP[curNode] + Edge.second)
			{
				DP[Edge.first] = DP[curNode] + Edge.second;
				pq.push({Edge.first,DP[Edge.first]});
			}
		}

	}

	return DP[end];
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	std::fill(DP, DP+MAX, DISTMAX);
	Arr.assign(N+1, vector<pair<int,int>>());
	
	int from, to;
	int cost;

	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> cost;
		Arr[from].push_back({to,cost});
	}

	int start, end;
	cin >> start >> end;
	cout << DaikStra(start, end);


}


