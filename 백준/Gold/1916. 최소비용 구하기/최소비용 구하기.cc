#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1000000001
using namespace std;

int N, M;
vector<vector<pair<int,int>>> Bank;
vector<int> Shortest;

void DaikStra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start }); 
    Shortest[start] = 0;

    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curDist > Shortest[curNode]) continue;

        for (pair<int,int> nearEdge : Bank[curNode])
        {
            int nextDist = nearEdge.first;
            int nextNode = nearEdge.second;
            if (Shortest[nextNode] > curDist + nextDist)
            {
                Shortest[nextNode] = curDist + nextDist;
                pq.push({ Shortest[nextNode], nextNode });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    int a, b, dist;
    Shortest.assign(N + 1, MAX);
    Bank.assign(N + 1, vector<pair<int,int>>());

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> dist;
        Bank[a].push_back({ dist,b });
    }

    int A, B;
    cin >> A >> B;

    DaikStra(A);
	cout << Shortest[B];
}

