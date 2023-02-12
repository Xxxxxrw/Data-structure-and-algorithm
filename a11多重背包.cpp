#include <bits/stdc++.h>
using namespace std;
int N, V;
int ci[100], vi[100], ki[100], dp[100];
int main()
{
	cin >> N >> V;
	for(int i = 1; i <= N; i++)
	{
		cin >> vi[i] >> ci[i] >> ki[i];
	}
	for(int i = 1; i <= N; i++)
		for(int j = V; j > 0; j--)
			for(int k = 0; k <= ki[i]; k++)
			{
				if(j >= ci[i] * k)
				dp[j] = max(dp[j], dp[j - k * ci[i]] + k * vi[i]);
			}
	
	cout << dp[V];
	return 0;
}
