#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 100001
using namespace std;
int N;


 class Trie
{
    bool end;
    bool pass;
    Trie* child[10];

public:
    Trie()
    {
        end = false;
        pass = false;
        std::fill(child, child+10, nullptr);
    }
    ~Trie()
    {
        for (int i = 0; i < 10; i++)
        {
            if (child[i])
                delete child[i];
        }
    }

     bool insert(string str, int idx)
    {
         if (end) return false;

        if (idx == str.size())
        {
            end = true;
            if (pass) return false;
            else return true;
        }

        else
        {
            int next = str[idx]-'0';
            if (child[next] == nullptr)
            {
                child[next] = new Trie();
                pass = true;
            }
            return child[next]->insert(str,idx+1);
        }
    }

};


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int n;
    string num;
    for (int i = 0; i < N; i++)
    {
        Trie* curTree = new Trie();
        int answer = -1;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            if (answer == 0) continue;
            answer = curTree->insert(num,0);
        }
        if(answer==1)
            cout << "YES" << "\n";
        else if (answer ==0)
            cout << "NO" << "\n";

        delete curTree;
    }




}

