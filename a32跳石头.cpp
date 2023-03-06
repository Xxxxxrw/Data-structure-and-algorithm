#include <bits/stdc++.h>
using namespace std;
int L, M, N, a[100005];
int f(int x)
{
    int tot = 0;
    int now = 0, p = 0;
    while(p != N + 1)
    {
        p++;
        if(a[p] - a[now] < x)
        {
            tot++;
        }
        else{
            now = p;
        }
    }
    return tot;
}
int main()
{
    cin >> L >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    a[N + 1] = L;
    int l = 1, r = L + 1;
    while(l < r)
    {
        int mid = l + (r - l) / 2;
        if(f(mid) > M)
        {
            r = mid;
        }else{
            l = mid + 1;
        }
        //cout << f(mid) << " "<< mid << endl;
    }
    cout << l - 1;
    return 0;
}
