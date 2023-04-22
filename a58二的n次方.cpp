#include <bits/stdc++.h>
using namespace std;
int N, a[10005], t = 1;
int main()
{
    cin >> N;
    a[0] = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < t; j++)
        {
            a[j] *= 2;
        }
        
        for(int j = 0; j <= t; j++)
        {
            a[j + 1] += a[j] / 10;
            a[j] %= 10;
        }
        if(a[t]) t++;
    }
    for(int i = t-1; i >= 0; i--)
    {
        cout << a[i];
    }
    return 0;
}
