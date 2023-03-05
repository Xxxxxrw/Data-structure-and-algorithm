#include <bits/stdc++.h>
using namespace std;
int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int x = 5, f = 0;
	long long ans = 0;
	for(int i = 2000; i <= 2020; i++)
	{
		if(i % 4 == 0)
		{
			mon[2]++;
		}else{
			mon[2] = 28;
		}
		for(int j = 1; j <= 12; j++)
		{
			for(int z = 1; z <= mon[j]; z++)
			{
				if(x != 7){
					x++;
				}else{
					x = 1;
				}
				if(x == 1 || z == 1)
				{
					ans += 2;
				}else{
					ans += 1;
				}
				if(i == 2020 && j == 10 && z == 1)
				{
					f = 1;
				}
			}
			if(f){
				break;
			}
		}
		if(f){
			break;
		}
	}
	cout << ans;
	return 0;	
} 
