#include <bits/stdc++.h>
using namespace std;
/*
	解决二分问题中mid == l, 不断循环导致超时的问题的几种思路 
	1. while(l + 1 < r)  对l, r 的改变只做 l = mid, r = mid 处理
	
	2. while(l < r)  对l, r 的改变存在 l = mid + 1 或者 r = mid - 1 时, 扩展 r, l 的边界。
	   如下例可先求第一个不满足条件的值，最后输出 该值-1 
	
	3.特判，if(mid == l) mid += 1; 避免死循环 
*/
int n, k;
const int maxn = 1e5 + 5;
int a[maxn];
long long f(int x)
{
    long long tot = 0;
    for(int i = 0; i < n; i++)
    {
        tot += a[i] / x;
        if(tot > k)
        {
            return tot;
        }
    }
    return tot;
}
int main()
{
    cin >> n >> k;
    int r = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    int l = 1;
    //r += 1;
    if(f(l) < k)
    {
        cout << 0 << endl;
        return 0;
    }
    while(l < r)
    {
        int mid = l + (r - l) / 2;
        if(mid == l)
        {
            mid += 1;
        }
        
        if(f(mid) < k)
        {
            r = mid - 1;
        }
        else{
            l = mid ;
        }
    }
    cout << l  << endl;
    return 0;
}
