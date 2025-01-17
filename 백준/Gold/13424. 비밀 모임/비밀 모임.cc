#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101
#define INF 1e9
using namespace std;
int T, N, M, K;
vector<int> DP;
vector<int> answer;
vector<vector<pair<int,int>>> EdgeBank;

void Daikstra(int start)
{
   
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    DP.assign(N + 1, INF);

    pq.push({ 0,start });
    DP[start] = 0;
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (DP[cur.second] < cur.first) continue;

        for (pair<int, int> next : EdgeBank[cur.second])
        {

            if(DP[next.second] > DP[cur.second] + next.first)
            {
                DP[next.second] = DP[cur.second] + next.first;
                pq.push({ DP[next.second] , next.second });
            }
        }

    }

    for (int i = 1; i <= N; i++)
    {
            answer[i] += DP[i];
    }
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;

    while (T--)
    {
        cin >> N >> M;
        EdgeBank.assign(N+1, vector<pair<int, int>>());
        answer.assign(N + 1, 0);

        int start, end, cost;
        for (int i = 0; i < M; i++)
        {
            cin >> start >> end >> cost;
            EdgeBank[start].push_back({ cost,end });
            EdgeBank[end].push_back({ cost ,start});
        }
        cin >> K;
        int num;
        for (int i = 0; i < K; i++)
        {
            cin >> num;
            Daikstra(num);
        }

        int trueAnswer = INF;
        int trueIdx = -1;
        for (int i = 1; i <= N; i++)
        {
            if (trueAnswer > answer[i]) {
                trueAnswer = answer[i];
                trueIdx = i;
            }
        }
        cout << trueIdx<<"\n";
    }

}