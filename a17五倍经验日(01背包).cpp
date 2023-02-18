#include <bits/stdc++.h>
using namespace std;
long long sum;
const int maxn = 1e3 + 2;
int l[maxn], w[maxn];
int u[maxn];
long long dp[maxn];
int n, x;
int main()
{
    cin >> n >> x;
    int t1, t2;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> w[i] >> u[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = x; j >= 0; j--)
        {
            if(j >= u[i])
                dp[j] = max(dp[j] + l[i], dp[j - u[i]] + w[i]);
            else
                dp[j] = dp[j] + l[i];
        }
        
    }
    cout << 5 * dp[x];
    return 0;
}
