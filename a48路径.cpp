#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f[2050];
ll gcd(int x, int y)
{
	if(y == 0)
		return x;
	return gcd(y, x % y);
}
int main()
{
	for(int i = 1; i <= 2021; i++)
	{
		for(int j = i+1; j <= i+21; j++)
		{
			if(f[j] == 0)
			{
				f[j] = f[i] + i * j / gcd(i, j);
			}
			else
			{
				f[j] = min(f[j], f[i] + i * j / gcd(i, j));
			}
		}
	}
	cout << f[2021];
	return 0;
} 
