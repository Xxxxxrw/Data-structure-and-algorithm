#include <bits/stdc++.h>
using namespace std;
int n;
double sum, t1, p, a[100005], b[100005];
bool f(double x)
{
    double tot = 0;
    for(int i = 1; i <= n; i++)
    {
        if(b[i] - a[i] * x < 0)
        {
            tot += a[i] * x - b[i];
        }
    }
    if(p * x >= tot)
        return 1;
    return 0;
}
int main()
{
    cin >> n >> p;
    for(int i = 1; i <= n; i++)
    {
        cin >> t1 >> b[i];
        a[i] = t1;
        sum += t1;
    }
    if(sum <= p){
        cout << -1;
        return 0;
    }
    
    double l = 0.00001, r = 1.5e10;
    while(r - l > 0.000001)
    {
        double mid = (l + r) / 2;
        if(f(mid))
        {
            l = mid;
        }else{
            r = mid;
        }
    }
    printf("%f", l);
    return 0;
} 
