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
	//삼중벡터 DP[A][B][C] 는 A는 행, B는 열을 의미
	//C는 3가지 경우에 따라 다음과 같이 분류
	//0 : 현재 A행, B열에서의 최종 최댓값  
	//1 : 왼쪽에서 순회하는 경우의 최댓값 
	//2 : 오른쪽에서 순회하는 경우의 최댓값

	/*
	현재 위치(n,m) 기준으로 
	1.윗행(n-1,m)의 최댓값이 모두 정해져 있는 상태에서 내리받아 먼저 최댓값 갱신
	 ex)DP[n][m][0] 에는 DP[n-1][m][0] + Arr[n][m] 으로 모두 갱신
	2.위에서 내리받은 값과 왼쪽->오른쪽 순회일 경우, 또는 오른쪽 -> 왼쪽 순회일 경우를 비교하여 최댓값인 DP[n-1][m][1] , DP[n-1][m][2]에 각각 저장
	3.두 순회한 결과중에 최댓값인 경우를 DP[n-1][m] 에 저장하여 최댓값을 확정지음 
	4.마지막 행의 경우에는 왼쪽->오른쪽 순회만 가능하므로 별도로 계산
	
	*/

	

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Arr[i][j]; //배열 입력
		}
		
	}

	DP[1][1][1] = Arr[1][1]; //시작 포인트는 배열값으로 설정
	for (int i = 2; i <= M; i++)
	{
		DP[1][i][1] = DP[1][i - 1][1] + Arr[1][i]; //첫번째 행은 무조건 전 열의 값에다 배열값을 더해서 DP 갱신, 왼쪽->오른쪽 경우밖에 없으므로 오른->왼쪽의 경우는 제외한다.
	}



	for (int i = 2; i <= N; i++) //행을 기준으로 for 문 돌며 DP 갱신
	{
		for (int k = 1; k <= M; k++)
		{
			DP[i-1][k][0] = max(DP[i-1][k][1], DP[i-1][k][2]); //전 행에서 순회한 결과를 토대로 두개의 DP 배열에서 비교하여 최종 최댓값 갱신
			DP[i][k][0] = DP[i-1][k][0] + Arr[i][k]; //현재 행에서는 일단 전 행에서의 최댓값+현재 배열값을 내리받음 
		}

		DP[i][1][1] = DP[i][1][0]; // 왼쪽 시작 포인트는 무조건 위에서 내리받은 상태
		DP[i][M][2] = DP[i][M][0]; // 오른쪽 시작 포인트도 동일

		if (M > 1) // M값이 2개 이상일때만 탐색
		{
			for (int j = 2; j <= M; j++) 
			{
				DP[i][j][1] = max(DP[i][j][0], DP[i][j - 1][1] + Arr[i][j]); //위에서 내리받은 값과 왼쪽에서 탐색해오는 값을 비교하여 현재 상태의 최댓값 갱신
			}

			if (i == N) break; //N행의 경우는 오른쪽-> 왼쪽의 탐색은 불가하므로 break

			for (int z = M - 1; z > 0; z--)
			{
				DP[i][z][2] = max(DP[i][z][0], DP[i][z+1][2] + Arr[i][z]); //오른쪽->왼쪽의 경우
			}
		}
	
	}

		DP[N][M][0] = max(DP[N][M][1], DP[N][M][2]); //(N,M) 에서의 최댓값만 중요하므로 마지막 행은 개별 처리
		cout << DP[N][M][0];
}