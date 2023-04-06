#include <bits/stdc++.h>
using namespace std;
int N;
int Ma[10005];
int main()
{
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		Ma[i] = max(i - 1, N - i) * 2;
	}
	for(int i = 1; i <= N; i++)
	{
		cout << Ma[i] << endl;
	}
	return 0;
} 
