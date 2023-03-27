#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > vec;
//bool vis[1000005];
int final, ans1, ans2, n;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        vec.push_back(make_pair(t1, t2));
    }
    sort(vec.begin(), vec.end(), cmp);
    for(vector<pair<int, int> >::iterator it = vec.begin(); it != vec.end(); it++)
    {
        if(final <= (*it).first)
        {
            final = (*it).second;
            ans1++;
        }
    }
    cout << ans1;
    return 0;
}
