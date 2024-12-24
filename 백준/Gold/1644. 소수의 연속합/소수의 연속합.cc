#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#define MAX 4000001
using namespace std;
int N;
vector<int> Bank;


int FindNextSosu(int cur) 
{
	if(cur+1 <= N)
	for (int i = cur+1; i <= N; i++)
	{
		if (Bank[i] == 2)
		{
			return i;
		}
	}
	return -1;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;

	Bank.assign(MAX, 1);

	for (int i = 2; i <= N; i++)
	{
		int mulResult = 1;
		int multiplier = 1;
		while (i * multiplier <= N)
		{
			mulResult = i*multiplier;
			Bank[mulResult]++;
			multiplier++;
		}
	}

	int start=2 , end = 2;
	int curResult = 2;
	int answer = 0;

	while (true)
	{
		if (curResult == N)
			answer++;
			
			int nextEnd = FindNextSosu(end);

			if (nextEnd != -1 &&  nextEnd + curResult <= N)
			{
				end = nextEnd;
				curResult += nextEnd;
				continue;
			}
			int nextStart = FindNextSosu(start);
			if (nextStart != -1)
			{
				curResult -= start;
				start = nextStart;
				continue;
			}

			break;
	}
	cout << answer;
}


