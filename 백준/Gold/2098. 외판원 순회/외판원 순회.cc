#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 16
#define INF 999999999;
using namespace std;
int N;
int num;
int Bank[MAX][MAX] = { 0, };
int VisitedDP[MAX][1<<16];

int dfs(int cur , int visit) //int visit 은  탐색 비트마스크 
{
    if (visit == (1<<N)-1) // 모든 도시 (N개) 의 탐색을 마쳤는지 
    {
        if (Bank[cur][0] == 0) // 원점으로 회귀 못하면 오류값 반환
            return INF;
        return Bank[cur][0];
    }

    if (VisitedDP[cur][visit] != -1) // 한번 거쳐간 도시면
        return VisitedDP[cur][visit];

    VisitedDP[cur][visit] = INF;

    for (int i = 0; i < N; i++) 
    {
        if (Bank[cur][i] == 0)
            continue;
        if ((visit & (1 << i)) == (1 << i)) // i 번째 도시를 방문했는지
            continue;
        VisitedDP[cur][visit] = min(VisitedDP[cur][visit], Bank[cur][i] + dfs(i,visit | 1 <<i));
    }
    return VisitedDP[cur][visit];

}


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Bank[i][j];
        }
    }
    std::fill(&VisitedDP[0][0], &VisitedDP[0][0] + 16*(1<<16) , -1);
    cout << dfs(0, 1);

}

