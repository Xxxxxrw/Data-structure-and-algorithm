#include <iostream>
using namespace std;
int a[100005], b[100005], c[100005];
long long ans;
int main()
{
  int N;
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  for(int i = 0; i < N; i++)
  {
    cin >> b[i];
  }
  for(int i = 0; i < N; i++)
  {
    cin >> c[i];
  }
  for(int i = 0; i < N; i++)
  {
    int x = 0, y = 0;
    for(int j = 0; j < N; j++)
    {
      if(a[j] < b[i])
      {
        x++;
      }
    }
    for(int j = 0; j < N; j++)
    {
      if(c[j] > b[i])
      {
        y++;
      }
    }
    ans += x * y;
  }
  cout << ans;
  return 0;
}
