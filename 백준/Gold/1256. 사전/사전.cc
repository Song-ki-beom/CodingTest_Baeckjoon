#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <climits>
#define NMMAX 101
#define KMAX 1000000000
using namespace std;
int N, M, K;
int DP[NMMAX][NMMAX]; // [a 개수] [z 개수] 로 이루어진 조합의 개수

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	std::fill(&DP[0][0],&DP[0][0] + NMMAX*NMMAX,0); 



	for (int i = 1; i < NMMAX; i++)
	{
		DP[i][0] = 1;
		DP[0][i] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <=M; j++)
		{
			DP[i][j] = DP[i - 1][j] + DP[i][j-1]; // i-1 개의 a 와 , j 개의 z개 조합에서 맨 앞에 a를 붙일 경우의 개수 + i 개의 a 와 , j-1 개의 z개 조합에서 맨 앞에 a를 붙일 경우의 개수
			if (DP[i][j] > KMAX) DP[i][j] = KMAX; //K의 한도치 고정
		}
	}

	int aCnt = N;
	int zCnt = M;
	if (DP[aCnt][zCnt] < K)
	{
		cout << -1;
		return 0;

	}
	for (int i = 0; i < N+M; i++)
	{
		int as = DP[aCnt - 1][zCnt];

		if (aCnt == 0)
		{
			cout << 'z';
			zCnt--;
		}
		else if (zCnt == 0)
		{
			cout << 'a';
			aCnt--;
		}
		else if (K <= as)
		{
			cout << 'a';
			aCnt--;
		}
		else
		{
			K = K - as;
			cout << 'z';
			zCnt--;
		}

	}

	
	





}


