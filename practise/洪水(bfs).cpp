#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int mp[1005][1005];
bool vis[1005][1005];
int n, m, r, c, ans;
queue<pair<int, int> > q;
int main()
{
    scanf("%d%d", &n, &m);
    ans = n * m - 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &mp[i][j]);
        }
    }
    scanf("%d%d", &r, &c);
    q.push(make_pair(r, c));
    vis[r][c] = 1;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty])
            {
                vis[tx][ty] = 1;
                if(mp[tx][ty] <= mp[x][y])
                {
                    ans--;
                    //printf("%d%d\n", tx, ty);
                    q.push(make_pair(tx, ty));
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
