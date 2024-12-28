#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <climits>
#define MAX 31
#define ll unsigned long long
using namespace std;
int N, C;
int Arr[MAX];
int answer = 0;


void makePartSum(vector<int>& partSum, int idx, int sum, int end)
{
	if (sum > C) return;
	if (idx == end)
	{
		partSum.push_back(sum);
		return;
	}
	makePartSum(partSum,idx+1 , sum + Arr[idx], end);
	makePartSum(partSum , idx+1 , sum, end);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(Arr, Arr + MAX, 0);
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
	}
	vector<int> partSum1;
	vector<int> partSum2;
	makePartSum(partSum1, 0, 0,N / 2);
	makePartSum(partSum2, N/2, 0, N);

	sort(partSum2.begin(), partSum2.end());

	int partCnt = 0;
	for (int i = 0; i < partSum1.size(); i++)
	{
		partCnt = upper_bound(partSum2.begin(), partSum2.end(), C - partSum1[i]) - partSum2.begin();
		
		answer += partCnt;

	}

	cout << answer;
	

}


