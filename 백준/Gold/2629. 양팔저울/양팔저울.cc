#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#define MAX  15001

using namespace std;
int WeightCnt, BallCnt;
int Weights[31];
bool DP[31][MAX]; 


void Calculate(int curResult , int curIdx)
{
	
	if (curIdx > WeightCnt) return;
	if(DP[curIdx][curResult] != false) return;
	DP[curIdx][curResult] = true; // curIdx  번째 선택에서 curResult에 도달했는지 확인하는 메모라이제이션 
	Calculate(curResult+Weights[curIdx], curIdx+1);
	Calculate(curResult, curIdx + 1);
	Calculate(curResult- Weights[curIdx], curIdx + 1);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> WeightCnt;
	std::fill(&DP[0][0], &DP[0][0]+MAX*31 , false);
	std::fill(Weights, Weights + 31, 0);
	int tempNum;

	for (int i = 0; i < WeightCnt; i++)
	{
		cin >> tempNum;	
		Weights[i]= tempNum;
	}

	cin >> BallCnt;


	Calculate(0, 0);


	for (int j = 0; j < BallCnt; j++)
	{
		cin >> tempNum;
		if (tempNum > 15000 || DP[WeightCnt][tempNum] == 0)
			cout << "N" << " ";
		else 
			cout << "Y" << " ";
	}



}


