#include <bits/stdc++.h>
using namespace std;
int m, n;
long long dp[1005][5000];
int main()
{
    cin >> m >> n;
    dp[1][1] = dp[2][1] = 1;
    int len = 2;
    for(int i = 3; i <= n - m + 1; i++)//¸ß¾«¶È 
    {
        for(int j = 1; j < len; j++)
        {
        	dp[i][j] = dp[i-1][j] + dp[i-2][j];
		}
		for(int j = 1; j < len; j++)
		{
			dp[i][j+1] += dp[i][j] / 10;
			dp[i][j] = dp[i][j] % 10;
		}
		if(dp[i][len])
		{
			len++;
		}
    }
    for(int i = len-1; i >= 1; i--)
    {
    	cout << dp[n-m+1][i] << endl;
	}
    return 0;
}
