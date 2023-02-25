#include <cstdio>
int n;
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
char ss[8] = "yizhong";
char s[105][105];
int vis[105][105];
int f;
void dfs(int i, int j, int d1, int d2, int cnt)
{
    if(i < 0 || i >= n || j < 0 || j >= n)
    {
        return;
    }
    if(cnt == 6 && ss[6] == s[i][j])
    {
        f = 1;
        return;
    }
    if(s[i][j] != ss[cnt])
    {
        return;
    }
    vis[i][j]++;
    dfs(i + d1, j + d2, d1, d2, cnt + 1);
    if(!f)
        vis[i][j]--;
}
int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(s[i][j] == 'y')
            {
                for(int z = 0; z < 8; z++)
                {
                    f = 0;
                    dfs(i, j, dx[z], dy[z], 0);
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(vis[i][j])
            {
                printf("%c", s[i][j]);
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}
