#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#define MAX 101
using namespace std;
string str, bomb;
stack<char> stAnswer;
stack<char> stTemp;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    cin >> str >> bomb;
    for ( char ch : str)
    {
        stAnswer.push(ch);
            bool bIsBomb = true;
            for (int i = bomb.size()-1; i >=0 ; i--)
            {
                if (!stAnswer.empty()&&stAnswer.top() == bomb[i])
                {
                    stTemp.push(stAnswer.top());
                    stAnswer.pop();

                }
                else
                {
                    bIsBomb = false;
                    break;
                }
            }
            if (!bIsBomb)
            {
                while (!stTemp.empty())
                {
                    stAnswer.push(stTemp.top());
                    stTemp.pop();
                }
            }
            else
            {
                stTemp = stack<char>();
            }
    }

    vector<char> answer;
    while (!stAnswer.empty())
    {
        answer.push_back(stAnswer.top());
        stAnswer.pop();
    }

    if (answer.size() == 0)
    {
        cout << "FRULA";

    }

    for (int i = answer.size()-1; i >=0; i--)
    {
        cout << answer[i];
    }
    

}