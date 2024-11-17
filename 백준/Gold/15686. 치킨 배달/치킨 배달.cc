#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 4901
using namespace std;

int N, M;

void CalculateDistance();

struct ChickenNode
{
    int n;
    int m;
    bool bOpened;
};

vector<ChickenNode> Chickens;
vector<pair<int, int>> houses;
int answer = MAX;

void dfs(int chickenIdx , int cnt)
{
    

    if (cnt == M)
    {
        CalculateDistance();
        return;
    }

    if (chickenIdx >= Chickens.size()) return;


    Chickens[chickenIdx].bOpened = true;
    dfs(chickenIdx + 1, cnt+1);
    Chickens[chickenIdx].bOpened = false;
    dfs(chickenIdx + 1, cnt);


}

void CalculateDistance()
{
    int total = 0;
    
    for (int j = 0; j < houses.size(); j++)
    {
        int shortest = MAX;
        for (int i = 0; i < Chickens.size(); i++)
        {
            if (Chickens[i].bOpened == false) continue;
            int distance = abs(Chickens[i].n - houses[j].first) + abs(Chickens[i].m - houses[j].second);
            shortest = min(shortest,distance);
        }
        total += shortest;
    }
    answer = min(answer , total);
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;

    int num;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N ; j++)
        {
            cin >> num;
            if (num == 2)
            {
                ChickenNode chicken = { i , j , false };
                Chickens.push_back(chicken);
            }
            else if (num == 1)
            {
                houses.push_back({i,j});
            }
        }
    }
    dfs(0, 0);

    cout<< answer;

}

