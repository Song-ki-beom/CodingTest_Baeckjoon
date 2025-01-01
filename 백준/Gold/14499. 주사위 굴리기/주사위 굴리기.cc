#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <climits>
#define MAX 20
using namespace std;
int xDir[4] = {1,-1,0,0};
int yDir[4] = { 0,0,-1,1 };
int N, M, K;
int Arr[MAX][MAX];
int EASize = 4, NSSize = 4 , EATop=1 , NSTop =1;
int DiceEA[4];
int DiceNS[4];
pair<int, int> DicePos;


void ChangeArr(int EABottom, int NSBottom , pair<int,int> pos)
{
	int newNum = Arr[pos.first][pos.second];

	if (newNum)
	{
		Arr[pos.first][pos.second] = 0;
		DiceEA[EABottom] = newNum;
		DiceNS[NSBottom] = newNum;
	}
	else
	{
		Arr[pos.first][pos.second] = DiceEA[EABottom];
	}
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int x, y;
	cin >> N >> M >> y >> x>>K;
	DicePos = { y,x };
	std::fill(DiceEA , DiceEA +4 ,0);
	std::fill(DiceNS, DiceNS + 4, 0);
	


	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Arr[i][j];
		}
	}


	int instruction = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> instruction;
		int newY = DicePos.first + yDir[instruction - 1];
		int newX = DicePos.second + xDir[instruction - 1];

		if (newY < 0 || newY >= N || newX < 0 || newX >= M)
		{
			continue;
		}
		DicePos = {newY, newX};
		int NewEATop =EATop, NewNSTop = NSTop;

		switch (instruction)
		{
		case 1: // 동
			NewEATop = (EATop + 3) % EASize; //윗면 이동
			DiceNS[NSTop] = DiceEA[NewEATop]; // 윗면 갱신
			DiceNS[(NSTop + 2)%NSSize] = DiceEA[(NewEATop + 2) % EASize]; // 아랫면 갱신
			EATop = NewEATop;

			break;
		case 2: // 서
			NewEATop = (EATop +	1) % EASize;
			DiceNS[NSTop] = DiceEA[NewEATop];
			DiceNS[(NSTop + 2) % NSSize] = DiceEA[(NewEATop + 2) % EASize];
			EATop = NewEATop;
			break;
		case 3: // 북
			NewNSTop = (NSTop + 1) % NSSize;
			DiceEA[EATop] = DiceNS[NewNSTop];
			DiceEA[(EATop + 2)%EASize] = DiceNS[(NewNSTop + 2) % NSSize];
			NSTop = NewNSTop;
			break;
		case 4: // 남 
			NewNSTop = (NSTop + 3) % NSSize;
			DiceEA[EATop] = DiceNS[NewNSTop];
			DiceEA[(EATop + 2) % EASize] = DiceNS[(NewNSTop + 2) % NSSize];
			NSTop = NewNSTop;
			break;
		}
		ChangeArr((EATop+2)%EASize , (NSTop + 2) % NSSize ,DicePos);
		cout << DiceEA[EATop] << "\n";

	}

}


