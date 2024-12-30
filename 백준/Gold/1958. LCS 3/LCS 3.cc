#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <climits>
#define MAX 101
using namespace std;
string str[3];
int DP[MAX][MAX][MAX];
int main()
{
	std::fill(str, str+3, " ");
	std::fill(&DP[0][0][0], &DP[0][0][0] + MAX * MAX * MAX, 0);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 0; i <= 2; i++)
	{
		string Input;
		cin >> Input;
		str[i] += Input;
	}

	for (int i = 1; i <= str[0].size()-1; i++)
	{
		for (int j = 1; j <= str[1].size()-1; j++)
		{
			for (int z = 1; z <=str[2].size()-1; z++)
			{
				if ((str[0][i] == str[1][j]) && (str[1][j] == str[2][z]))
				{
					DP[i][j][z] = DP[i - 1][j - 1][z - 1] + 1;
				}
				else
				{
					DP[i][j][z] = max({ DP[i - 1][j][z], DP[i][j - 1][z], DP[i][j][z - 1] });
				}
			}
		}
	}
	cout << DP[str[0].size()-1][str[1].size()-1][str[2].size()-1];

}


