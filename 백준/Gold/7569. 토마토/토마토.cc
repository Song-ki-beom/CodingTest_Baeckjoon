#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 501
using namespace std;
int prematureCnt=0, M, N ,H;
int HDir[6] = { 1,-1,0,0,0,0 };
int NDir[6] = { 0,0,1,-1,0,0 };
int MDir[6] = { 0,0,0,0,1,-1};
int FinalDay = 0;
struct Tomato 
{
    int m=0;
    int n = 0;
    int h = 0;
    int day = 0;

};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N >> H;
    vector<vector<vector<int>>> Box(H,vector<vector<int>>(N,vector<int>(M,0)));
    queue<Tomato> qu;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k  = 0; k < M; k++)
            {
                cin >> Box[i][j][k];
                if (Box[i][j][k] == 0) prematureCnt++;
                else if (Box[i][j][k] == 1) qu.push({ k,j,i,1 });

            }
        }
    }

    if (prematureCnt == 0)
    {
        if (Box[0][0][0] == 1) cout << 0;
        else if (Box[0][0][0] == -1) cout << -1;
    }


    while (!qu.empty())
    {
        Tomato  curTomato = qu.front();
        qu.pop();
        for (int i = 0; i < 6; i++)
        {
            int newH = curTomato.h + HDir[i];
            int newM = curTomato.m + MDir[i];
            int newN = curTomato.n+ NDir[i];

            if (newH<0 || newH >=H || newM <0 || newM >= M || newN <0 || newN >= N) continue;

            switch (Box[newH][newN][newM])
            {
            case -1:
            case 1:
                continue;
                break;
            case 0:
                Box[newH][newN][newM] = 1;
                prematureCnt--;
                qu.push({ newM,newN,newH,curTomato.day + 1 });
                break;
            }
            if (prematureCnt == 0)
            {
                FinalDay = curTomato.day;
                cout << curTomato.day;
                return 0;
            }
        }
    }
    if(prematureCnt >0)
        cout << -1;
}