#include <bits/stdc++.h>
using namespace std;
const long long maxn = 205;
int n, m, a[105];
long long dp[maxn][maxn];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i <= a[1]; i++)
    {
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int k = 0; k <= a[i] && (j - k) >= 0; k++)
            {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
