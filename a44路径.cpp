#include <bits/stdc++.h>
using namespace std;
long long ans = 2333333333333;
int n;
int gcd(int x, int y)
{
	if(y == 0)
		return x;
	return gcd(y, x % y);
}
void dfs(int x, long long cnt)
{
	if(cnt > ans)
		return;
	if(x == n)
	{
		if(cnt < ans)
			ans = cnt;
		return;
	}
	for(int i = 21; i >= 1; i--)
	{
		dfs(x + i, cnt + gcd(x, x + i));
	}
}
int main()
{
    cin >> n;
    dfs(1, 0);
    cout << ans;
    return 0;
}
