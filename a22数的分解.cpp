#include <iostream>
using namespace std;
long long ans;
bool Judge(int x)
{
  while(x)
  {
    if(x % 10 == 2 || x % 10 == 4)
    {
      return 0;
    }
    x /= 10;
  }
  return 1;
}
int main()
{
  for(int i = 1; i < 2019 / 3; i++)
  {
    for(int j = i + 1; j < 2019; j++)
    {
      for(int z = j + 1; z < 2019; z++)
      {
        if((i + j + z) == 2019 && Judge(i) && Judge(j) && Judge(z))
        {
          ans++;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
