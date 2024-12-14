#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <time.h>
using namespace std;
char a[1001];
char b[1001];
int result;

vector<vector<int>> dp;
int main() {
	scanf("%s", a);
	getchar();
	scanf("%s", b);

	dp.assign(strlen(a)+1, vector<int>(strlen(b)+1, 0));
	
	for (int i = 1; i <= strlen(a); i++)
	{
		for (int j = 1; j <= strlen(b); j++)
		{
			dp[i][j] = max({ dp[i - 1][j],dp[i][j - 1],dp[i - 1][j - 1] + (a[i-1] == b[j-1]) });
		}
	}
	
	result = dp[strlen(a)][strlen(b)];
	
	
	
		//cout << "time ="<<(double)end-start << "\n";
	cout << result;
	

}