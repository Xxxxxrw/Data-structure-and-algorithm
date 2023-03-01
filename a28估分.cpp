#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int mi[maxn], ni[maxn], t, m, n;
long long ans;
int f(int x)
{
    int l = 0, r = m + 1;
    while(r > l)
    {
        int mid = (l + r) / 2;
        if(x < mi[mid])
        {
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    return min(abs(mi[l] - x), abs(mi[l - 1] - x));
}
int main()
{
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        cin >> mi[i];
    }
    sort(mi, mi + m + 1);
    mi[0]=-0x3f3f3f3f,mi[m+1]=0x3f3f3f3f;//из╠Ь╥ют╫╫Г
    for(int i = 1; i <= n; i++)
    {
        cin >> t;
        ans += f(t);
    }
    cout << ans;
    return 0;
}
