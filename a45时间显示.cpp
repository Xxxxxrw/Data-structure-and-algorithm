#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    cin >> n;
    long long mod = 24 * 60 * 60 * 1000;
    int x = n % mod;
    int modh = mod / 24;
    int modm = modh / 60;
    int modp = modm / 60;
    int h = x / modh; x %= modh;
    int m = x / modm; x %= modm;
    int p = x / modp;
    printf("%02d:%02d:%02d", h, m, p);
    return 0;
}
