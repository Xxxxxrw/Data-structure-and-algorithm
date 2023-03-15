#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
int gcd(int x, int y)
{
	if(y ==  0)
		return x;
	return gcd(y, x % y);
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n-1; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(gcd(j, i) == 1)
			{
				ans += 2;
			}
		}
	}
	cout << ans;
	return 0;	
} 
