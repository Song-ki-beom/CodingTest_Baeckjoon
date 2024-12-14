#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 100000
#define INF 100000001
using namespace std;
int Bank[MAX];
vector<int> Sums(MAX, 0);
vector<int> SumsWithSub(MAX, 0);

int N;
int answer = -INF;


void DP()
{
		Sums[0] = Bank[0];
	for (int i = 1; i < N; i++)
	{
		Sums[i] = max(Sums[i-1] + Bank[i], Bank[i]);
	}
	answer = *max_element(Sums.begin(), Sums.begin()+N);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	std::fill(Bank, Bank+N,0);
	for (int i = 0; i < N; i++)
	{
		cin >> Bank[i];
		
	}

	DP();
	SumsWithSub[0] = 0;
	for (int i = 1; i < N; i++)
	{
		SumsWithSub[i] = max(SumsWithSub[i - 1] + Bank[i], Sums[i-1]);
		answer = max(answer, SumsWithSub[i]);
	}

	cout << answer << "\n";
}