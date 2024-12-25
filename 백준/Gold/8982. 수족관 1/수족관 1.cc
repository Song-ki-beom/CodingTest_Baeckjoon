#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
using namespace std;
int N,K;
int waterLeft=0;

int Y1, X1 ,Y2 ,X2 ;

struct Depth
{
	int startX = 0;
	int endX = 0;
};

vector<Depth> Depths;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;

	cin >> Y1 >> X1;
	Depths.push_back({0,0});
	for (int i = 0; i < (N-2)/2; i++)
	{
		cin >> Y1 >> X1 >> Y2 >> X2;

		for (int j = 0; j < Y2-Y1; j++)
		{
			Depths.push_back({0,X1});
		}
	}

	cin >> Y1 >> X1;


	cin >> K;

	for (int z = 0; z < K; z++)
	{
		cin >> Y1 >> X1 >> Y2 >> X2;
		
		for (int i = Y1+1 ;i <= Y2; i++)
		{
			Depths[i].startX = Depths[i].endX;
		}
		
		int curDepth = Depths[Y1+1].startX;

		for (int j = Y1; j > 0; j--)
		{
			if (curDepth < Depths[j].startX) continue;
			if (curDepth > Depths[j].endX)
			{
				curDepth = Depths[j].endX;
				Depths[j].startX = Depths[j].endX;
			}
			else if (curDepth <= Depths[j].endX)
			{
				Depths[j].startX = curDepth;
			}
		}


		if (Y1 + 1 >= Depths.size()) continue;
		curDepth = Depths[Y1+1].startX;
		for (int k = Y2+1; k < Depths.size(); k++)
		{
			if (curDepth < Depths[k].startX) continue;
			if (curDepth > Depths[k].endX)
			{
				curDepth = Depths[k].endX;
				Depths[k].startX = Depths[k].endX;
			}
			else if (curDepth <= Depths[k].endX)
			{
				Depths[k].startX = curDepth;
			}
		}
	}


	for  (int i= 1; i < Depths.size() ; i ++)
	{
		waterLeft += Depths[i].endX - Depths[i].startX;
	}

	cout << waterLeft;


}