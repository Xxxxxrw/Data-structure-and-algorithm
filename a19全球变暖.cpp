#include <bits/stdc++.h>
using namespace std;
int n;
char s[1005][1005];
int vis[1005][1005], sum, sum2;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
void Judge(int x, int y)
{
  for(int i = 0; i < 4; i++)
  {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if(tx >= 0 && tx < n && ty >= 0 && ty < n && s[tx][ty] == '.')
    {
      s[x][y] = '!';
    }
  }
}
void dfs(int x, int y)
{
  if(x < 0 || x >= n || y < 0 || y >= n || s[x][y] == '.')
  {
    return;
  }
  Judge(x, y);
  for(int i = 0; i < 4; i++)
  {
    int tx = x + dx[i];
    int ty = y + dy[i];
    if(!vis[tx][ty])
    {
      vis[tx][ty] = 1;
      dfs(tx, ty);
    }
  }
}
int main()
{
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    scanf("%s", s[i]);
  }
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(s[i][j] == '#' && vis[i][j] == 0)
      {
        dfs(i, j);
        vis[i][j] = 1;
        sum++;
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(s[i][j] == '#' && vis[i][j] == 0)
      {
        dfs(i, j);
        vis[i][j] = 1;
        sum2++;
      }
    }
  }
  cout << sum - sum2;
  return 0;
}
