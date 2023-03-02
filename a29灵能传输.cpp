#include <iostream>
using namespace std;
int T, n;
int a[100005];
int main()
{
  cin >> T; 
  for(int i = 0; i < T; i++)
  {
    cin >> n;
    for(int j = 0; j < n; j++)
    {
      cin >> a[j];
    }
    for(int z = 0; z < 30; z++)
    {
    for(int j = 1; j < n-1; j++)
    {
      int b = a[j - 1] + a[j];
      int d = a[j + 1] + a[j];
      int max1 = max(a[j-1], max(a[j], a[j+1]));
      if(max1 > max(0-a[j], max(b, d)))
      {
      	a[j] = 0 - a[j];
        a[j - 1] = b;
        a[j + 1] = d;
      }
    }
    }
    int ans = 100000;
    for(int j = 0; j < n; j++)
    {
      cout << a[j] << " "; 
      if(a[j] < ans)
      {
        ans = a[j];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
