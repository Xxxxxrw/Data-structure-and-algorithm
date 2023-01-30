#include <bits/stdc++.h>
using namespace std;
struct node{
    int x, y, step;
    node(int xx, int yy, int ss)
    {
        x = xx;
        y = yy;
        step = ss;
    }
};
queue<node > q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m, ans = -1;
char s[15][15];
bool vis[15][15];
void bfs(int x, int y, int step)
{
    node p(x, y, step);
    q.push(p);
    vis[x][y] = 1;
    while(!q.empty())
    {
        node t = q.front();
        q.pop();
        if(s[t.x][t.y] == 'T')
        {
            ans = t.step;
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            int tx = t.x + dx[i];
            int ty = t.y + dy[i];
            if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || s[tx][ty] =='*')
                continue;
            vis[tx][ty] = 1;
            q.push(node(tx, ty, t.step + 1));
        }
    }
}
int main()
{
    int tx, ty;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == 'S')
            {
                tx = i;
                ty = j;
                break;
            }
        }
    }
    bfs(tx, ty, 0);
    
    printf("%d", ans);
    return 0;
}
