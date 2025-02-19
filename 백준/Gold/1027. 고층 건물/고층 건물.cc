#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define MAXRATIO 1000000001
using namespace std;
vector<long int> Bank;
vector<int> lowerCnt;
int N;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;


    int num;
    Bank.assign(N + 1, 0);
    lowerCnt.assign(N + 1, 0);


    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        Bank[i] = num;
    }

    double ratio = -MAXRATIO;
    for (int i = 1; i < N; i++)
    {
        ratio = -MAXRATIO;
        for (int j = i + 1; j <= N; j++)
        {
            double newratio = (((double)Bank[j] - (double)Bank[i])) / ((double)j - (double)i);

            if (newratio > ratio)
            {
                ratio = newratio;
                lowerCnt[j]++;
            }
        }
    }



    for (int i = N; i > 1; i--)
    {
        ratio = -MAXRATIO;
        for (int j = i - 1; j >= 1; j--)
        {
            double newratio = (((double)Bank[i] - (double)Bank[j])) / ((double)j - (double)i);
            if (newratio > ratio)
            {
                ratio = newratio;
                lowerCnt[j]++;
            }
        }
    }

    int maxElement = *max_element(lowerCnt.begin(), lowerCnt.end());

    cout << maxElement;


}