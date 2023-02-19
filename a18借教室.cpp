#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m;
long long p[maxn], sum, r[maxn], d[maxn], s[maxn], t[maxn];
bool f(int x)
{
    memset(p, 0, sizeof(p));
    sum = 0;
    for(int i = 1; i <= x; i++)
    {
        p[s[i]] += d[i];
        p[t[i] + 1] -= d[i];
    }
    for(int i = 1; i <= n; i++)
    {
        sum += p[i];
        if(sum > r[i])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> r[i + 1];
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> d[i] >> s[i] >> t[i];
    }
    if(f(m))
    {
        cout << 0 << endl;
        return 0;
    }
    int left = 1, right = m;
    int mid = (left + right) / 2;
    while(left < right)
    {
        if(f(mid) == 1)
        {
            left = mid + 1;
        }
        else{
            right = mid;
        }
        mid = (left + right) / 2;
    }
    cout << "-1" << endl << left;
    return 0;
}
