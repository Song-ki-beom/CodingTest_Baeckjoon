#include <iostream>
#include <algorithm>
#include <vector>
#define ARRAYSIZE(A) sizeof(A)/sizeof((A)[0])
using namespace std;
int dp[102];
vector<pair<int,int>> B;
int n,a,b, result;
int main() {
	cin >> n;
	B.emplace_back(0, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		B.emplace_back(a, b);
	}
	sort(B.begin(), B.end());
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (B[i].second > B[j].second)
				if (dp[j] >= dp[i]) dp[i] = dp[j] + 1;
		}
	}
	
	result = *max_element(dp,dp+ ARRAYSIZE(dp));
	cout << n-result;

}