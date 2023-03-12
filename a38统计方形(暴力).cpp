#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans1, ans2;
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
    	for(int j = 1; j <= m; j++)
    	{
    		int t = (n - i + 1) * (m - j + 1);
    		if(i == j)
    			ans1 += t;
    		else
    			ans2 += t;
		}
	}
    cout << ans1 << " " << ans2;
    return 0;
}
