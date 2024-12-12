#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#define MAX 101
using namespace std;
int N, M;
struct line
{
	int start;
	int num;
};

bool compLine(line a, line b)
{
	if (a.num > b.num)
		return true;
	else if (a.num == b.num)
		return a.start < b.start;
	else
		return false;
}
vector<queue<int>> A;
vector<queue<int>> B;
vector<line> sortedLine;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int temp;
	A.assign(MAX, queue<int>());
	B.assign(MAX, queue<int>());

	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		A[temp].push(i);
	}
	cin >> M;
	for (int j = 1; j <= M; j++)
	{
		cin >> temp;
		B[temp].push(j);
	}

	int limitStart = -1;
	int limitEnd = -1;
	vector<int> answer;
	for (int i = MAX-1 ; i>=0; i--)
	{
		while (!A[i].empty())
		{
			if(A[i].front() > limitStart)
			while (!B[i].empty())
			{
				if (B[i].front() > limitEnd)
				{
					answer.push_back(i);
					limitStart = A[i].front();
					limitEnd = B[i].front();
					B[i].pop();
					break;
				}
				else
				{
					B[i].pop();
				}

			}
			A[i].pop();
		}
	}
	
	if (answer.empty())
	{
		cout << 0;
		return 0;
	}
	else
	{
		cout << answer.size() << "\n";
		for (int ansNum : answer)
		{
			cout << ansNum << " ";
		}
	}

	
	
}