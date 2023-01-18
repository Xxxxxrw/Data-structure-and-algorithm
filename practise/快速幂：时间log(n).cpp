#include <bits/stdc++.h>
using namespace std;
long long a, b, p;
long long powab(long long x, long long y)
{
    long long ans = 1, base = x;
    while(y)
    {
        if(y & 1)
        {
            ans *= base;
            ans %= p;
        }
        y >>= 1;
        base *= base;
        base %= p;
    }
    return ans % p;
}

int main()
{
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod "<< p << "="<< powab(a, b) << endl;
    return 0;
}
