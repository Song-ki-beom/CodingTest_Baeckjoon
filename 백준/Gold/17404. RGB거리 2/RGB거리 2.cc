#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define  MAX 1001
using namespace std;
int K;
vector<int> answer;
int DP[MAX][3]; // n번째 집의 순서에 -> m 번째 색을 칠했을 경우 최솟값
int Bank[MAX][3]; // 각 집마다 색 칠하는 비용 Container 

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    std::fill(&DP[0][0], &DP[0][0] + MAX * 3, 0);
    std::fill(&Bank[0][0], &Bank[0][0] + MAX * 3, 0);


    cin >> K;

    for (int i = 0; i < K ; i++)
    {
        cin >> Bank[i][0] >> Bank[i][1] >> Bank[i][2];
    }

    for (int first = 0; first < 3; first++)
    {
        DP[1][first] = MAX*MAX+1;
        DP[1][(first + 1) % 3] = Bank[0][first] + Bank[1][(first + 1) % 3];
        DP[1][(first + 2) % 3] = Bank[0][first] + Bank[1][(first + 2) % 3];


        for (int i = 2; i < K; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                DP[i][j] = min( DP[i - 1][(j + 1) % 3] , DP[i - 1][(j + 2) % 3]);
                DP[i][j] += Bank[i][j];
            }
        }

        answer.push_back(min(DP[K - 1][(first + 1) % 3], DP[K - 1][(first + 2) % 3]));

    }

    int realAnswer = *min_element(answer.begin(), answer.end());
   
    cout << realAnswer;



}