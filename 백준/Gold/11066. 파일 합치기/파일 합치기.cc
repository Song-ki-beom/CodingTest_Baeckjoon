#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <climits>
#define MAX 501
using namespace std;
int T, K, num;
vector<vector<int>> DP;
vector <int> Arr;
vector <int> PartialSum;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	cin >> T;
	DP.assign(MAX, vector<int>(MAX,0));
	Arr.assign(MAX, 0);
	PartialSum.assign(MAX, 0);

	for (int i = 0; i < T; i++)
	{

		cin >> K;
		for (int k = 1; k <=K ; k++)
		{
			cin >> Arr[k];
			PartialSum[k] = PartialSum[k - 1] + Arr[k];
		}
		

		for (int length = 2; length  <=K; length++)
		{
			for (int i = 1; i <= K - length+1; i++)
			{
				int j = i + length - 1;
				DP[i][j] = INT_MAX;

				for (int k = i; k < j; k++)
				{
					DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + PartialSum[j] - PartialSum[i - 1]);
				}

			}
		}
		cout << DP[1][K] << "\n";

	}

}