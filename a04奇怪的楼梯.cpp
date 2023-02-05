#include <bits/stdc++.h>
using namespace std;
int N, A, B, ans = 250;
int f[205];
bool vis[205];
int f0[205];
void dfs(int now, int cnt)
{
    
    if(f0[now] < cnt)
        return;
    else
        f0[now] = cnt;
    if(cnt >= ans)
        return;
    if(now == B)
    {
        if(cnt < ans)
        {
            ans = cnt;
        }
        return;
    }
    vis[now] = 1;
    int x = now + f[now];
    if(x <= N && !vis[x])
    {
        dfs(x, cnt + 1);
    }
    int y = now - f[now];
    if(y >= 0 && !vis[y])
    {
        dfs(y, cnt + 1);
    }
    vis[now] = 0;
}
int main()
{
    cin >> N >> A >> B;
    memset(f0, 0x3f, sizeof(f0));
    for(int i = 1; i <= N; i++)
    {
        cin >> f[i];
    }
    dfs(A, 0);
    if(ans == 250)
        ans = -1;
    cout << ans << endl;
    return 0;
}
