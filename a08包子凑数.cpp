#include <iostream>
using namespace std;
int a[20000];
int b[105], ans;
int gcd(int x, int y)
{
  if(y == 0)
    return x;
  return gcd(y, x % y);
}
int main()
{
  a[0] = 1;
  int n, t;
  cin >> n;
  for(int i = 0; i < n; i++)
  {

    cin >> t;
    b[i] = t;
  }
  int g = gcd(b[0], b[1]);
  for(int i = 2; i < n; i++)
  {
    g = gcd(g, b[i]);
  }
  if(g != 1)
  {
    cout << "INF";
    return 0;
  }
  for(int i = 0; i <= 19000; i++)
  {
    if(a[i])
    {
      for(int j = 0; j < n; j++)
      {
        a[i + b[j]] = 1;
      }
    }
  }
  for(int i = 0; i <= 19000; i++)
  {
    if(a[i] == 0)
      ans++;
  }

    cout << ans;
  return 0;
}
