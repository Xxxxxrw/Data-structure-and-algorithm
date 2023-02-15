#include <bits/stdc++.h>
using namespace std;
int n, m, t1, t2;
queue<int> q;
int eat[5005], beeat[5005];
bool vis[5005];
long long ni[5005];
vector<int > vec[5005];
long long sum;
void bfs()
{
    while(!q.empty())
    {
    int h = q.front();
    q.pop();
    int len = vec[h].size();
    for(int i = 0; i < len; i++)
    {
        int next = vec[h][i];
        eat[next]--;
        ni[next] = (ni[next] + ni[h]) % 80112002;
        if(!eat[next])
        {
            q.push(next);
        }
    }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> t1 >> t2;
        vec[t1].push_back(t2);
        eat[t2]++;//入度
        beeat[t1]++;//出度
    }
    for(int i = 1; i <= n; i++)
    {
        if(eat[i] == 0)
        {
            ni[i] = 1;
            q.push(i);
        }
    }
    bfs();
    for(int i = 1; i <= n; i++)
    {
        if(beeat[i] == 0)
        {
            sum += ni[i];
            sum %= 80112002;
        }
    }
    cout << sum;
    return 0;
}
