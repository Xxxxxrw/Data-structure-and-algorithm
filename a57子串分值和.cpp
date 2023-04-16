#include <bits/stdc++.h>
using namespace std;
string  s;
long long ans;
set<char> st;
int main()
{
	cin >> s;
	int len = s.size();
	for(int i = 0; i < len; i++)
	{
		st.clear();
    	int l = 0;
		for(int j = i; j < len; j++)
		{
			//char c = s[j];
			if(st.insert(s[j]).second)
        		l++;
			ans += l;
		}
	}
	cout << ans;
	return 0;
 } 
