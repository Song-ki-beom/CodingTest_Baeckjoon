#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;
int N,M;
int Arr[MAX][MAX];
int visit[MAX][MAX];
int mDir[4] = { 1,-1 ,0,0};
int nDir[4] = { 0,0,1,-1};
int CheeseCnt = 0;
queue<pair<int, int>> qu;


void fillAir()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visit[i][j] = 0;
        }
    }

    qu = queue<pair<int, int>>();
    qu.push({0,0});
    visit[0][0] = 1;



    while (!qu.empty())
    {
        pair<int, int> cur = qu.front();
        qu.pop();
        for (int idx = 0; idx < 4; idx++)
        {
            int newN = cur.first + nDir[idx];
            int newM = cur.second + mDir[idx];

            if (newM < 0 || newM >= M || newN < 0 || newN >= N) continue;
            if (visit[newN][newM] == 1 || Arr[newN][newM] == 1) continue;

            visit[newN][newM] = 1;
            qu.push({ newN, newM });

        }
    }

  
}




void MarkRotten()
{

        
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visit[i][j] == 1)
            {

                for (int idx = 0; idx < 4; idx++)
                {
                    int newN = i + nDir[idx];
                    int newM = j + mDir[idx];
                    if (newM < 0 || newM >= M || newN < 0 || newN >= N) continue;

                    if (Arr[newN][newM] >= 1) Arr[newN][newM]++;
                }

            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (Arr[i][j] >= 3)
            {
                CheeseCnt--;
                Arr[i][j] = 0;
            }
            else if (Arr[i][j] == 2)
            {
                Arr[i][j] = 1;
            }
        }
    }


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    std::fill(&Arr[0][0], &Arr[0][0]+MAX*MAX, 0);
    
    cin >> N >> M;
    int n;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Arr[i][j];
            if (Arr[i][j] == 1) CheeseCnt++;
        }
    }
    int day = 0;
    while (CheeseCnt)
    {
        day++;
        fillAir();
        MarkRotten();
    }
    cout << day;

}