#include <bits/stdc++.h>

int n, m, ans = 100000;
char a[15][15];
bool vis[15][15];
void dfs(int x, int y,int step)
{
    if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || a[x][y] == '#')
    {
        return;
    }
    if(a[x][y] == 'R')
    {
        if(ans > step)
        {
            ans = step;
        }
        return;
    }
    vis[x][y] = 1;
    dfs(x, y + 1, step + 1);
    dfs(x, y - 1, step + 1);
    dfs(x - 1, y, step + 1);
    dfs(x + 1, y, step + 1);
    vis[x][y] = 0;
}

int main()
{
    int tx, ty;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", &a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == '@')
            {
                tx = i;
                ty = j;
            }
            if( (i == 0 || i == n-1 || j == 0 || j == m-1) && a[i][j] == '.')
            {
                a[i][j] = 'R';
            }
        }
    } 
    dfs(tx, ty, 0);
    if(ans == 100000)
        ans = -1;
    printf("%d", ans);
    
    return 0;
}
/*
4 6
#.####
#.#.##
#...@#
######
*/
