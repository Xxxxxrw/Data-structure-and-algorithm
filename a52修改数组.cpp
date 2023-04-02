#include <bits/stdc++.h>
using namespace std;
set<int> st;
vector<int> vec;
int n;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		while(st.count(t))
		{
			t++;
		}
		vec.push_back(t);
		st.insert(t);	
	}
	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << (*it) << " ";
	}
	return 0;
} 
