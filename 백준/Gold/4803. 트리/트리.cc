#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 501
using namespace std;

int parent[MAX] , depth[MAX];
bool isCycle[MAX];

int FindParent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = FindParent(parent[a]);
}

bool Union(int a, int b) {
    a = FindParent(a);
    b = FindParent(b);
    if (a == b) return true; // 사이클 발생
    if (depth[a] < depth[b]) parent[a] = b;
    else parent[b] = a;
    if (depth[a] == depth[b]) depth[a]++;

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, caseNum = 1;

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            depth[i] = 0;
            isCycle[i] = false;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if (Union(u, v)) {
                isCycle[FindParent(u)] = true;
            }
        }

        int numOfTrees = 0;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i && !isCycle[i]) {
                numOfTrees++;
            }
        }

        cout << "Case " << caseNum << ": ";
        if (numOfTrees == 0) {
            cout << "No trees.\n";
        }
        else if (numOfTrees == 1) {
            cout << "There is one tree.\n";
        }
        else {
            cout << "A forest of " << numOfTrees << " trees.\n";
        }
        caseNum++;
    }

    return 0;
}