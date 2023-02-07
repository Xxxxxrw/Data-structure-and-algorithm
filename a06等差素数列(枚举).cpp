#include <bits/stdc++.h>
using namespace std;
bool a[10000000];
int main()
{
	for(int i = 2; i <= 10000; i++)
	{
		if(!a[i])
		{
			for(int j = 2; j * i <= 10000000; j++)
			{
				a[j * i] = 1;
			}
		}
	}
	int f = 1, ans = 0, x;
	for(int it = 2; it < 100000; it++)
	{
		for(int i = 2; i < 300; i++)
		{
			for(int j = 1; j < 10; j++)
			{
				int t = it + i * j;
				if(a[t])
				{
					f = 0;
					break;
				}
				f = 1;	
			} 
			if(f)
			{
				ans = i;
				x = it;
				break;
			}
		}
		if(f)
		{
			break;
		} 
	}
	cout << ans << " " << x << endl;
	return 0;
}
 
