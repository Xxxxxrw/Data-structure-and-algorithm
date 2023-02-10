#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
bool s[8][8];
bool vis[8][8];
int ans, f, t;
void Judge(int tx, int ty)
{
  
  for(int i = 0; i < 4; i++)
  {
    int x = tx + dx[i];
    int y = ty + dy[i];
    if(x > 0 && x < 7 && y > 0 && y < 7 && !vis[x][y] && s[x][y] == t)
    {
      f++;
      vis[x][y] = 1;
      Judge(x, y);
    }
  }

}
void dfs(int x, int y)
{
  if(x == 4)
  {
    f = 1;
    t = s[1][1];
    memset(vis, 0, sizeof(vis));
    vis[1][1] = 1;
    Judge(1, 1);
    if(f == 18)
    {
      ans++;
    }
    return;
  }
  if(y == 7)
  {
    dfs(x + 1, 1);
    return;
  }
  s[x][y] = 0;
  s[7 - x][7 - y] = 1;
  dfs(x, y + 1);
  s[x][y] = 1;
  s[7 - x][7 - y] = 0;
  dfs(x, y + 1);
}
int main()
{
  dfs(1, 1);
  ans = ans / 4;
  cout << ans;
  return 0;
}
