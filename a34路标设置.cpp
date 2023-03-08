#include <bits/stdc++.h>
using namespace std;
int L, N, K;
int a[1000005];
int f(int x)
{
    int tot = 0, now = a[0], i = 1; 
    while(i <= N+1)
    {
        if(a[i] - now > x)
        {
            now += x;
            tot++;
        }else{
            now = a[i];
            i++;
        }
    }
    return tot;
}
int main()
{
    cin >> L >> N >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i + 1];
    }
    a[N] = L;
    int l = 1, r = L;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(f(mid) > K)
        {
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    cout << l;
    return 0;
}
