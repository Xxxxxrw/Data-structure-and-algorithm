#include <bits/stdc++.h>
using namespace std;

long long  n, x, ans;

int main()
{
    cin >> n >> x;
    int last = 0;
    for(int i = 1; i <= n; i++)
    {
        int t1; 
        cin >> t1;
        if(t1 > x)
        {
            ans += t1 - x;
            t1 = x;
        }
        if(last + t1 > x)
        {
            ans += (last + t1 - x);
            t1 -= (last + t1 - x);
        }
        last = t1;
    }
    
    cout << ans;
    return 0;
}
