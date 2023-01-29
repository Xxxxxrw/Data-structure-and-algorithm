#include <cstdio>
int n;
int a[10];
bool vis[10];
void dfs(int x)
{
    if(x == n)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%5d", a[i]);
        }
        printf("\n");
    }
    for(int j = 1; j <= n; j++)
    {
        if(!vis[j])
        {
            vis[j] = 1;
            a[x] = j;
            dfs(x + 1);
            vis[j] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(0);
    return 0;
}
