#include <bits/stdc++.h>

int n, k, ans, cnt, step;

int a[25];
bool Judge(int x)
{
    for(int i = 2; i <= sqrt(x); i++)
    {
        if(x % i == 0)
            return false;
    }
    if(x == 1)
        return false;
    return true;
}
void dfs(int x)
{
    step++;
    cnt += a[x];
    if(step == k)
    {
        if(Judge(cnt))
        {
            ans++;
        }
        //cnt -= a[x];
        return;
    }
    
    for(int i = x + 1; i < n; i++)
    {
        dfs(i);
        cnt -= a[i];
        step--;
    }
    
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 0; i <= n-k; i++)
    {
        dfs(i);
        cnt-=a[i];
        step--;
    }
    printf("%d",ans);
    
    return 0;
}
