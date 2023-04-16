#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
long long poww(long long t, int x)
{
	for(int i = 1; i <= x; i++)
	{
		t *= 2;
	}
	return t;
}
void dfs(int x, int y, long long tot)
{
	if(x == n && y == m - 1 && tot == 1) ans++;
	if(poww(tot, n - x) < m - y) return; 
	if(x > n || y >=m) return;
	
	dfs(x + 1, y, tot * 2);
	if(tot > 0)
	{
		dfs(x, y + 1, tot - 1);
	}
}
int main()
{
	cin >> n >> m;
	dfs(0, 0, 2);	
	cout << ans;
	return 0;
}
