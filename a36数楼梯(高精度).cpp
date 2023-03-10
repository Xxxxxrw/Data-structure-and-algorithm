#include <bits/stdc++.h>
using namespace std;
int n, len, dp[5005][5005];

int main()
{
    cin >> n;
    dp[1][1] = 1;
    dp[2][1] = 2;
    len = 1;
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j <= len; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i-2][j];
        }
        for(int j = 1; j <= len; j++)
        {
            if(dp[i][j] >= 10)
            {
                dp[i][j+1] += dp[i][j]/10;
                dp[i][j] %= 10;
            }
        }
        if(dp[i][len+1])
            len++;
    }
    for(int i = len; i >= 1; i--)
    {
        printf("%d",dp[n][i]);
    }
    return 0;
}
