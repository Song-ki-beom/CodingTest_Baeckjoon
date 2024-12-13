#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#define MAX 101
using namespace std;
string inputStr , refinedStr,answerStr;
map<char, int> priorityMap;
stack<int> st;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	priorityMap['+'] = 1;
	priorityMap['-'] = 1;
	priorityMap['*'] = 2;
	priorityMap['/'] = 2;
	priorityMap['('] = 3;
	priorityMap[')'] = 4;
	inputStr = "";
	answerStr = "";
	refinedStr = "";

	cin >> inputStr;

	
	for (char ch : inputStr)
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			answerStr += ch;
		}
		else
		switch (priorityMap[ch])
		{
			case 1:
			case 2:
				while (!st.empty()&& priorityMap[st.top()] <=2&& priorityMap[st.top()] >= priorityMap[ch])
				{
					answerStr += st.top();
					st.pop();
				}
				st.push(ch);
				break;
			case 3:
				st.push(ch);
				break;
			case 4:
				while (!st.empty() && st.top() != '(')
				{
					answerStr += st.top();
					st.pop();
				}
				if(!st.empty() && (st.top() == '('))
					st.pop();
				break;
				
		}
	}
	while (!st.empty())
	{
		answerStr += st.top();
		st.pop();
	}

	cout << answerStr << "\n";

}

//