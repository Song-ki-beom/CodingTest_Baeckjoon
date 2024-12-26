#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
using namespace std;
int N, M;
vector<vector<int>> DP;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	cin >> N >> M;
	int answer = 0;

	DP.assign(N+1, vector<int>(M+1,0));
	

	for (int i = 1; i <= N; i++)
	{
		DP[i][0] = 1;
		DP[i][1] = i;
	}

	for (int i = 2; i < N; i++)
	{
		for (int j = 2; j<= M; j++)
		{
			DP[i][j] = (DP[i - 1][j] + DP[i - 2][j-1])% 1000000003;
		}
	}
	DP[N][M] = DP[N - 3][M - 1] + DP[N - 1][M];

	cout << DP[N][M]% 1000000003;

}