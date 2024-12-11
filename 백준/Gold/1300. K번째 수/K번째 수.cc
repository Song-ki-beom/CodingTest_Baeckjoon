#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#define MAX 10001
#define INF 100000001
using namespace std;
int N , K;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;

	int start = 1;
	int end = K;
	int mid=0;  
	int cnt=0;

	while (start < end)
	{
		cnt = 0;
		mid = (start + end) / 2 ;
		for (int i = 1; i <= N; i++)
		{
			cnt += min(N, mid / i);
		}
		if (cnt < K) start = mid + 1;
		else  end = mid;
	}


	cout << end <<"\n";
	
}