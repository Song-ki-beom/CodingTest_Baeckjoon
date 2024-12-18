#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#define MAX 501
int N, M;

int mDir[4] = { 1, -1 ,0, 0 };
int nDir[4] = { 0, 0 ,-1, 1};
int DP[MAX][MAX];
int Bank[MAX][MAX];

using namespace std;

int dfs(int m, int n)
{
	if (m == M - 1 && n == N - 1) return 1; //종착점
	if (DP[m][n] != -1) return DP[m][n]; //이미 한번 연산한 경로면 기존 탐색값 반환

	DP[m][n] = 0;
	for (int i = 0; i < 4; i++)
	{
		int newM = m + mDir[i];
		int newN = n + nDir[i];

		if (newM >= M || newM < 0 || newN >= N || newN < 0) continue;
		if (Bank[newM][newN] < Bank[m][n])
		{
			DP[m][n] += dfs( newM, newN);
		}

	}
	return DP[m][n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	std::fill(&Bank[0][0], &Bank[0][0]+MAX*MAX,0);
	std::fill(&DP[0][0], &DP[0][0] + MAX * MAX, -1);
	

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Bank[i][j];
		}
	}
	cout << dfs(0,0);

}


