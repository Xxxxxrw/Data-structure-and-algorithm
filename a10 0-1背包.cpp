//n����Ʒ������������Ϊ V,ÿ����Ʒ���Ϊ ci, ��ֵvi ,������ֵ
#include <bits/stdc++.h>
using namespace std;
int n, V;
int ci[100], vi[100];
int dp[100][100];
int dp1[100];
int main()
{
	cin >> n >> V;
	for(int i = 1; i <= n; i++)
	{
		cin >> vi[i] >> ci[i];
	}
//	for(int i = 1; i <= n; i++)
//		for(int j = 0; j <= V; j++)
//		{
//			if(j >= ci[i])
//			{
//				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ci[i]] + vi[i]);
//			}
//			else{
//				dp[i][j] = dp[i - 1][j];
//			}
//		}
	//�Ż�Ϊһά
	for(int i = 1; i <= n; i++)
		for(int j = V; j >= ci[i]; j--)
			dp1[j] = max(dp1[j], dp1[j - ci[i]] + vi[i]);
	//cout << dp[n][V];
	cout << dp1[V];
	return 0;	
} 
