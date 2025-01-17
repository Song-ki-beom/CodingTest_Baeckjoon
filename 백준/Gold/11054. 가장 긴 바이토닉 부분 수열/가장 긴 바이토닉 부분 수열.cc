#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;
int Bank[MAX];
int DP[MAX];
vector<int> FrontWise, BackWise;
int N;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    std::fill(Bank,Bank+MAX,0);
    std::fill(DP, DP + MAX, 0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> Bank[i];
    }


    //Frontwise
    for (int i = 0; i < N; i++)
    {
        if (FrontWise.empty()) FrontWise.push_back(Bank[i]);
        else
        {
            int frontIdx = lower_bound(FrontWise.begin(),FrontWise.end(),Bank[i]) - FrontWise.begin();
            if (frontIdx == FrontWise.size())
                FrontWise.push_back(Bank[i]);
            else
                FrontWise[frontIdx] = Bank[i];
        }
        DP[i] += FrontWise.size();

    }
    //BackWise
    for (int i = N-1; i >= 0; i--)
    {
        if (BackWise.empty()) BackWise.push_back(Bank[i]);
        else
        {
            int backIdx = lower_bound(BackWise.begin(), BackWise.end(), Bank[i]) - BackWise.begin();
            if (backIdx == BackWise.size())
                BackWise.push_back(Bank[i]);
            else
                BackWise[backIdx] = Bank[i];
        }
        DP[i] += BackWise.size();
    }

    int answer = -1;
    for (int curMax : DP)
    {
        if (answer < curMax) answer = curMax;
    }

    if (answer - 1 >= 0)
        cout << answer - 1;
    else
        cout << 0;

}