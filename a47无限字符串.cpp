#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
	string s;
	cin >> s;
	cin >> n;
	int len = s.size();

	int t = n;
	
	while(t > s.size())
	{
		len = s.size();
		while(len < t) len *= 2;
		len /= 2;
		t = t - 1 - len;
		if(!t) t = len;
	}
	cout << s[t - 1];
    return 0;
}
