#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define MAX 101
using namespace std;
int Arr[MAX][MAX];
int N;

int dy[] = { 0,-1 ,0 ,1 };
int dx[] = { 1,0 ,-1,0};


void DragonCurve(int y, int x, int d, int g)
{
    vector<int> curveDir;
    pair<int, int> cur = { y,x };
    Arr[cur.first][cur.second] = 1;
    cur.first += dy[d];
    cur.second += dx[d];
    Arr[cur.first][cur.second] = 1;
    curveDir.push_back(d);

    for (int j = 0; j < g; j++)
    {
        
          
            for (int i = curveDir.size() - 1; i >= 0; i--)
            {
                int newDir = (curveDir[i] + 1) % 4;

                cur.first += dy[newDir];
                cur.second += dx[newDir];

                curveDir.push_back(newDir);
                Arr[cur.first][cur.second] = 1;
            }

    }

}



int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    std::fill(&Arr[0][0] , &Arr[0][0]+ MAX*MAX , 0);
    cin >> N;

    int  x, y, d, g;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y >> d >> g;
        DragonCurve(y, x, d, g);
    }

    int answer = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (Arr[i][j]==1 && Arr[i + 1][j]==1 && Arr[i][j + 1]==1 && Arr[i + 1][j + 1]==1) answer++;
        }
    }

    cout << answer;

}