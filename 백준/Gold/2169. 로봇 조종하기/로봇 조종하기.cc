#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#define MAX 100000001
using namespace std;
int N, M;
vector<vector<int>> Arr;
vector<vector<vector<int>>> DP;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	cin >> N >> M;
	Arr.assign(N + 1, vector<int>(M + 1, 0));
	DP.assign(N + 1, vector<vector<int>>(M + 1, vector<int>(3,-MAX)));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Arr[i][j];
		}
		
	}

	DP[1][1][1] = Arr[1][1];
	for (int i = 2; i <= M; i++)
	{
		DP[1][i][1] = DP[1][i - 1][1] + Arr[1][i];
	}

	for (int i = 2; i <= N; i++)
	{
		for (int k = 1; k <= M; k++)
		{
			DP[i-1][k][0] = max(DP[i-1][k][1], DP[i-1][k][2]);
			DP[i][k][0] = DP[i-1][k][0] + Arr[i][k];
		}

		DP[i][1][1] = DP[i][1][0];
		DP[i][M][2] = DP[i][M][0];

		if (M > 1)
		{
			for (int j = 2; j <= M; j++)
			{
				DP[i][j][1] = max(DP[i][j][0], DP[i][j - 1][1] + Arr[i][j]);
			}

			if (i == N) break;

			for (int z = M - 1; z > 0; z--)
			{
				DP[i][z][2] = max(DP[i][z][0], DP[i][z+1][2] + Arr[i][z]);
			}
		}
	
	}

		DP[N][M][0] = max(DP[N][M][1], DP[N][M][2]);
		cout << DP[N][M][0];

}