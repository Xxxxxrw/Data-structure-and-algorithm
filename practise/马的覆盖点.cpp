#include <cstdio>
int dir[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
int n, m, X, Y;
char s[105][105];
bool vis[105][105];
void dfs(int x, int y, int step)
{
    if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || step == 4)
        return;
    s[x][y] = '#';
    vis[x][y] = 1;
    for(int i = 0; i < 8; i++)
    {    
        dfs(x + dir[i][0], y + dir[i][1], step + 1);
    }
    vis[x][y] = 0;
}
int main()
{
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    scanf("%d%d%d%d", &n, &m, &X, &Y);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            s[i][j] = '.';
        }
    }
    dfs(X - 1, Y - 1, 0);
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", s[i]);
    }
    return 0;
}
