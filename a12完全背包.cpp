#include <bits/stdc++.h>
using namespace std;
int N, V, k;
int ci[100], vi[100], dp[100][100];
int  dp1[100];
int main()
{
	cin >> N >> V;
	for(int i = 1; i <= N; i++)
	{
		cin >> vi[i] >> ci[i];
	}
//	for(int i = 1; i <= N; i++)
//	{
//		for(int j = V; j > 0; j--)
//		{
//			k = 0;
//			while(j >= ci[i] * k)
//			{
//				dp[i][j] = max(dp[i][j],dp[i - 1][j - ci[i] * k] + k * vi[i]);
//				k++;
//			}
//		}
//	}
//	cout << dp[N][V];
	//时间 + 空间 优化后
	for(int i = 1; i <= N; i++)
	{
		for(int j = 0; j <= V; j++)
		{
			for(int k = 0; k * ci[i] <= j; k++)
			{
				dp1[j] = max(dp1[j], dp1[j - k * ci[i]] + k * vi[i]); 
			}
		}
	} 
	cout << dp1[V];
	return 0;
}
