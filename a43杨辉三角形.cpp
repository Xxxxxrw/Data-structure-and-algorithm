#include <bits/stdc++.h>
using namespace std;
int N, ma, ans = 1;
int dp[10005];
int main()
{
	cin >> N;
	if(N == 1)
	{
		cout << 1;
		return 0;
	}
    int len = 1;
    dp[1] = 1;
    int f = 0;
    while(!f)
    {
    	for(int i = len + 1; i >= 1; i--)
    	{
    		dp[i] = dp[i] + dp[i-1];
    		ma = max(ma, dp[i]);
		}
		if(ma < N)
			ans += len + 1;
		else{
			for(int j = 1; j <= len+1; j++)
			{
				ans++;
				if(dp[j] == N){
					f = 1;
					break;
				}
			}
		}
		len++;
	}
	cout << ans;
    return 0;
}
