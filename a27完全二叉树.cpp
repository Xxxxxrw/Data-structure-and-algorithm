#include <iostream>
using namespace std;
long long sum, ans, anss;
int a[100005], n;
int pows(int x, int y)
{
  int t = 1;
  for(int i = 0; i < y; i++)
  {
    t *= x;
  }
  return t;
}
int main()
{
  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }
  int m = 0, v = 0;
  while(v <= n)
  {
    m++;
    sum = 0;
    for(v = pows(2, m-1); v < pows(2, m); v++)
    {
      sum += a[v];
    }
    if(sum > ans)
    {
      ans = sum;
      anss = m;
    }
  }
  cout << anss;
  return 0;
}
