#include <bits/stdc++.h>
using namespace std;
int N, ma;
int a[1000005];
long long M;
long long f(int x)
{
    long long sum = 0;
    for(int i = 1; i <= N; i++)
    {
        if(a[i] > x)
            sum += a[i] - x;
    }
    return sum;
}
int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    int l = 0, r = ma;
    while(l < r)
    {
        int mid = (l + r) / 2;
        cout << l << " " << mid << " " << r << endl;
        if(f(mid) < M)
        {
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    
    cout << l - 1;
    return 0;
}
