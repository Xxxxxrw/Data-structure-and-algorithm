#include <bits/stdc++.h>
using namespace std;
int N, M;
const int mod = 200005;
long long a[mod];
long long ans;
int main()
{
  cin >> N >> M;
  for(int i = 0; i < N + M + 1; i++)
  {
    cin >> a[i];
  }
  if(!M)
  {
    for(int i = 0; i < N + M + 1; i++)
    {
      ans += a[i];
    }
    cout << ans;
    return 0;
  }
  sort(a, a + N + M + 1, greater<int>());
  ans = a[0] - a[N + M];
  for(int i = 1; i < N + M; i++)
  {
    ans += abs(a[i]);
  }
  cout << ans;
  return 0;
}
