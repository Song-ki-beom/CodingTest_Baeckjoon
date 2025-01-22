#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;
int N, V , best=0 , worst=0;
struct Edge
{
    int start;
    int end;
    int cost;
};

struct cmp1
{
    bool operator()(const Edge& A, const Edge& B)
    {
        return  A.cost > B.cost;
    }

};

struct cmp2
{
    bool operator()(const Edge& A, const Edge& B)
    {
        return  A.cost < B.cost;
    }

};


priority_queue<Edge, vector<Edge>, cmp1> pq1;
priority_queue<Edge, vector<Edge>, cmp2> pq2;

vector<int> Group;
vector<int> Rank;
vector<int> Tier;




int FindParent(int x)
{
    if (Group[x] == x) return x;
    else return FindParent(Group[x]);
}

bool Union(int x, int y)
{
    int parentX = FindParent(x);
    int parentY = FindParent(y);

    if (parentX != parentY)
    {
        if (Rank[parentX] < Rank[parentY]) swap(parentX, parentY);
        Group[parentY] = parentX;
        if (Rank[parentX] == Rank[parentY]) Rank[parentX]++;

        return true;
    }
    return false;
}





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> V;

    Rank.assign(N+1,1);
    Group.assign(N+1,1);
    for (int i = 0; i <=N; i++)
    {
        Group[i] = i;
    }

    int start, end, cost;
    for (int i = 0; i <= V; i++)
    {
        cin >> start >> end >> cost;
        pq1.push({ start,end,cost });
        pq2.push({ start,end,cost });

    }

    //최악의 경로
    while (!pq1.empty())
    {
        Edge curEdge = pq1.top();
        pq1.pop();
        if (Union(curEdge.start, curEdge.end))
        {
            if (curEdge.cost == 0) worst++;
        }
    }
    worst = pow(worst, 2);


    for (int i = 0; i <= N; i++)
    {
        Group[i] = i;
        Rank[i] = 1;
    }

    //최선의 경로
    while (!pq2.empty())
    {
        Edge curEdge = pq2.top();
        pq2.pop();
        if (Union(curEdge.start, curEdge.end))
        {
            if (curEdge.cost == 0) best++;
        }
    }
  
    best = pow(best, 2);



    cout << abs(worst - best);
}