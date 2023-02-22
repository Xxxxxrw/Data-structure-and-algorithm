#include <bits/stdc++.h>
using namespace std;
int n;
int a[15];
void f(int cnt, int x, int step)
{
    if(cnt == 0)
    {
        for(int i = 0; i < step - 1; i++)
        {
            cout << a[i] << "+";
        }
        if(step > 1)
        	cout << a[step - 1] << endl;
        return;
    }
    if(cnt < x)
    {
        return;
    }
    int y = x;
    while(cnt - y >= 0)
    {
        a[step] = y;
        f(cnt - y, y, step + 1);
        y++;
    }
}
int main()
{
    cin >> n;
    f(n, 1, 0);
    return 0;
}
