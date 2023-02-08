#include<bits/stdc++.h>
using namespace std;
double a[40][40];
int main()
{
	for(int i = 1; i <= 29; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= 30; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			a[i][j] += (a[i - 1][j - 1] + a[i - 1][j]) / 2;
		}
	}
	double max = 0, min = 0x3ff; 
	for(int i = 1; i <= 30; i++)
	{
		if(min > a[30][i])
			min = a[30][i];
		if(max < a[30][i])
			max = a[30][i];
	}
	long long ans = max * (2086458231 * 1.0 /min);
	cout << ans;
	return 0;
}
