#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define MAXVERTEX 20001
#define MAXEDGE 200001
using namespace std;
int K, V, E;
bool bIsDivided = true;

enum RB
{
    None,
    Red,
    Blue
};

vector<int> Vertex;
vector<vector<int>> Edge;


void DFS(int start , RB Color)
{
    if (bIsDivided == false) return;
    if (Vertex[start] != None) return;
        

    Vertex[start] = Color;


    for (int next : Edge[start])
    {
        if (Vertex[next] == None)
        {
            if (Color == Red)
                DFS(next, Blue);
            else if (Color == Blue)
                DFS(next, Red);
        }
        else if (Vertex[next] == Color)
        {
            bIsDivided = false;
            return;
        }

    }



}




int main() 
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> K;

    int start, to;
    while (K--)
    {
        Vertex.assign(MAXVERTEX, None);
        Edge.assign(MAXEDGE, vector<int>());
        bIsDivided = true;

        cin >> V >> E;
        
        for (int i = 0; i < E; i++)
        {
            cin >> start >> to;
            Edge[start].push_back(to);
            Edge[to].push_back(start);
        }
    
        for (int i = 1; i <= V; i++)
        {
            if(Vertex[i] == None)
                DFS(i, Red);

        }

        if (bIsDivided == true)
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }


    }
   


    



}