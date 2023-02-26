#include <bits/stdc++.h>
using namespace std;
long long N, C, tot, ans, ni[200005];
//vector<long long> pre;
long long f1(int x)
{
    int l = 1, r = N + 1;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(ni[mid] <= x)
        {
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}
long long f2(int x)
{
    int l = 1, r = N + 1;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(ni[mid] < x)
        {
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    return l;
}
int main()
{
    cin >> N >> C;
    for(int i = 1; i <= N; i++)
    {
        cin >> ni[i];
    }
    sort(ni, ni + N + 1);
    for(int i = 0; i <= N; i++)
	{
		cout << ni[i] << " ";
	 } 
	 cout << endl;
    for(int i = 1; i < N; i++)
    {
    	int t1;
        t1= f1(ni[i] + C) - f2(ni[i] + C);
        ans += t1;
        cout << t1 << " ";
    }
    cout << endl << ans;
    // sort(pre.begin(), pre.end());
    // int len = pre.size();
    // int l = 0, r = len - 1;
    // while(l < r)
    // {
    //     int mid = (l + r) / 2;
    //     if(pre[mid] >= C)
    //         r = mid;
    //     else
    //         l = mid + 1;
    // }
    // if(pre[l] != C)
    // {
    //     cout << 0;
    //     return 0;
    // }
    // while(pre[l] == C)
    // {
    //     tot++;
    //     l++;
    // }
    // cout << tot;
    return 0;
}

