#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> DP, Bank;
int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        Bank.push_back(n);
    }

    for (int i = 0; i < N; i++)
    {
        if (DP.empty())
        {
            DP.push_back(Bank[i]);
        }
        else
        {
            int idx = lower_bound(DP.begin(),DP.end(), Bank[i]) - DP.begin();
            if(idx == DP.size())  DP.push_back(Bank[i]);
            else
            {
                DP[idx] = Bank[i];
            }

        }
    }
    cout << N - DP.size();

}