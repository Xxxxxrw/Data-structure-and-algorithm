#include <bits/stdc++.h>
using namespace std;
int d[22], n;
int l[22], top;
int link[22][22];
long long dp[22];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            cin >> link[i][j];
        }
    }
    dp[n] = d[n];
    for(int i = n-1; i > 0; i--)
    {
        dp[i] = d[i];
        for(int j = i + 1; j <= n; j++)
        {
            if(link[i][j])
            {
            	if(d[i] + dp[j] > dp[i])
            	{
            		dp[i] = d[i] + dp[j];
            		l[i] = j;
				}
            	//dp[i] = max(dp[i], d[i] + dp[j]);
			}    
        }
    }
    int tt = 1;
    int ma = dp[1];
    for(int i = 2; i <= n; i++)
    {
    	if(ma < dp[i])
    	{
    		ma = dp[i];
    		tt = i;
		}
	}
	
    int t = tt;
    while(l[t])
    {
    	cout << t << " ";
    	t = l[t];
	}
	cout << t;
    cout << endl << dp[tt];
    return 0;
}
