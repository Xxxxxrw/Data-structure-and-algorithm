#include <bits/stdc++.h>
using namespace std;
int v[10005];

int t1 = 1;
int n;
void vdouble()
{
	for(int i = 0; i < t1; i++)
	{
		v[i] *= 2;
	}
    for(int i = 0; i < t1; i++)
    {
    	if(v[i] > 9)
    	{
    		v[i + 1] += v[i] / 10;
    		if(i + 1 >= t1) t1++;
    		v[i] %= 10;
		}
	}
}

int main()
{
    cin >> n;
    
    v[0] = 1;
    while(n)
    {
        vdouble();
        n--;
    }
    
    for(int i = t1 - 1; t1 >= 0; t1--)
    {
        cout << v[i];
    }
    return 0;
}
