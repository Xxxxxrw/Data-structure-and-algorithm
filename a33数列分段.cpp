#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M;
int a[100005];

int f(int x)
{
    ll sum = 0, d = 1;
    for(int i = 1; i <= N - 1; i++)
    {
        sum += a[i];
        if(sum + a[i+1] > x)
        {
            sum = 0;
            d++;
        }
    }
    return d;
}
int main()
{
    cin >> N >> M;
    int l = 0, r = 0;
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
        
        l = max(l, a[i]);
        r += a[i];
    }
    while(l < r)
    {
        int mid = l + (r - l) / 2;
        if(f(mid) <= M)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l;
    return 0;
}
