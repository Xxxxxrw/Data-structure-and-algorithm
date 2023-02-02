#include <bits/stdc++.h>
using namespace std;
int dp[255];
int main()
{
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i < 255; i++)
    {
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 100007;
    }
    cout << dp[n];
    return 0;
}
