#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 16
#define INF 999999999
using namespace std;
int N,R,Q;
vector<vector<int>> Bank;
vector<vector<int>> ChildBank;
vector<int> Size;

void MakeTree(int currentNode , int parent)
{
	for (int Node : Bank[currentNode])
	{
		if (Node != parent)
		{
			ChildBank[currentNode].push_back(Node);
			MakeTree(Node, currentNode);
		}

	}
}

int countSubTreeNodes(int currentNode)
{
	if (Size[currentNode] != 1)
		return Size[currentNode];

	for ( int childNode : ChildBank[currentNode])
	{
		Size[currentNode] += countSubTreeNodes(childNode);
	}
	return	Size[currentNode];

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> R >> Q;

	Bank.assign(N+1,vector<int>());
	ChildBank.assign(N+1, vector<int>());
	Size.assign(N+1, 1);

	int U, V; 
	for (int i = 0; i < N-1; i++)
	{
		cin >> U >> V;
		
		Bank[U].push_back(V);
		Bank[V].push_back(U);
	}

	
	MakeTree(R, -1);
	int q;
	for (int i = 0; i < Q; i++)
	{
		cin >> q;
		cout << countSubTreeNodes(q)<<"\n";

	}


}