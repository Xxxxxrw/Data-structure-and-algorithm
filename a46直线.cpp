#include <bits/stdc++.h>
using namespace std;
set<pair<double,double> > st;
set<int> st2;
int ans = 1;
int main()
{
  int m, n;
  cin >> m >> n;
  for(int i = 0; i <= m; i++)
  {
  	for(int j = 0; j <= n; j++)
  	{
  		for(int x = 0; x <= m; x++)
  		{
  			for(int y = 0; y <= n; y++)
  			{
  				if(i == x && j == y) continue;
  				if(i == x) continue;
  				else{
  					double k = (y - j) * 1.0 / (x - i);
  					double b = y - k * x;
  					st.insert(make_pair(k, b));
				  }
			  }
		  }
	  }
  }
  set<pair<double, double> >::iterator it = st.begin();
  it++;
  for(; it != st.end(); it++)
  {
  	double a1 = (*it).first, b1 = (*it).second;
  	it--;
  	double a2 = (*it).first, b2 = (*it).second;
  	it++;
  	if(fabs(a1 - a2) > 1e-8 || fabs(b1 - b2) > 1e-8)
  		ans++;
  }
  cout << ans + 20;
  return 0;
}
