#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int vis[405][405],step[405][405];
queue<pair<int, int> > q;
void bfs()
{
    q.push(make_pair(x, y));
    vis[x][y] = 1;
    step[x][y] = 0;
    while(!q.empty())
    {
        int x0 = q.front().first;
        int y0 = q.front().second;
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int tx = x0 + dx[i];
            int ty = y0 + dy[i];
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty])
            {
                vis[tx][ty] = 1;
                step[tx][ty] = step[x0][y0] + 1;
                q.push(make_pair(tx, ty));
            }
        }
    }
}
int main()
{
    cin >> n >> m >> x >> y;
    memset(step, -1, sizeof(step));
    bfs();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            printf("%-5d", step[i][j]);
        }
        cout << endl;
    }
    return 0;
}
