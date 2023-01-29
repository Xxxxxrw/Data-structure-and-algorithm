#include <cstdio>
int n;
long long ans = 1000000000, cnt;
int a[20][20];
bool v[20];
void dfs(int x)
{
    if(cnt >= ans)
        return;
    if(x == n)
    {
        if(cnt < ans)
        {
            ans = cnt;
        }
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!v[i])
        {
            v[i] = 1;
            cnt += a[x][i];
            dfs(x + 1);
            v[i] = 0;
            cnt -= a[x][i];
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            a[i][j] = 1000 - a[i][j];
        }
    }
    dfs(0);
    ans = 1000 * n - ans;
    printf("%lld", ans);
    return 0;
}
