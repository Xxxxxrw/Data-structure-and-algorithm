#include <bits/stdc++.h>
using namespace std;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool f1, f2;
int ans1, ans2;
bool run(int x)
{
	return ((x % 4 == 0 && x % 100 == 0 )|| (x % 400 == 0));
}
bool Judge1(int x)
{
	int t = x;
	int day, mon;
	mon = x % 10;
	x /= 10;
	mon = mon * 10 + x % 10;
	x /= 10;
	day = x % 10;
	x /= 10;
	day = day * 10 + x % 10;
	if(mon == 2 && run(t) && day == 29)
	{
		;
	}
	else if(mon < 1 || mon > 12 || day < 1 || day > month[mon])
	{
		return 0;
	}
	ans1 = t * 10000 + mon * 100 + day;
	return 1;
}
bool Judge2(int x)
{
	int t = x;
	int day, mon;
	mon = x % 10;
	int t1 = x % 10;
	x /= 10;
	int t2 = x % 10;
	mon = mon * 10 + x % 10;
	x /= 10;
	int t3 = x % 10;
	day = x % 10;
	x /= 10;
	day = day * 10 + x % 10;
	
	if(t1 != t3 || t2 != x)
	{
		return 0;
	}
	if(mon == 2 && run(t) && day == 29)
	{
		;
	}
	else if(mon < 1 || mon > 12 || day < 1 || day > month[mon])
	{
		return 0;
	}
	ans2 = t * 10000 + mon * 100 + day;
	return 1;
}
int main()
{
	int n;
	cin >> n;
	n /= 10000;
	while(f1 == 0 || f2 == 0)
	{
		n++;
		if(!f1)
		{
			if(Judge1(n))
			{
				f1 = 1;
			}
		}
		if(!f2)
		{
			if(Judge2(n))
			{
				f2 = 1;
			}
		}		
	}
	cout << ans1 << endl << ans2 << endl;	
	return 0;
} 
