#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], jin[100005];
int N, Ma, Mb;
long long jz, ans;
int main()
{
	cin >> N >> Ma;
	for(int i = 1; i <= Ma; i++) cin >> a[i];
	
	cin >> Mb;
	if(Ma > Mb)
	{
		for(int i = 1; i <= Ma - Mb; i++)
			b[i] = 0;
		for(int i = Ma - Mb + 1; i <= Ma; i++)
			cin >> b[i];
	}
	else
		for(int i = 1; i <= Mb; i++) 
			cin >> b[i];
	
	for(int i = 1; i <= Ma; i++)
	{
		jin[i] = max(2, max(a[i], b[i]) + 1);
	}
	
	jz = 1;
	for(int i = Ma; i >= 1; i--)
	{
		if(i < Ma)
			jz *= jin[i+1];
		ans += jz * (a[i] - b[i]);
	}
	cout << ans;
	return 0;
}
