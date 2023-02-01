#include <bits/stdc++.h>
using namespace std;
int a[11][11];
int main()
{
    int t, M, N;
    cin >> t;
    for(int i = 0; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            if(i == 1 || j == 1 || i == 0)
                a[i][j] = 1;
            else if(i >= j)
                a[i][j] = a[i - j][j] + a[i][j - 1];
            else 
                a[i][j] = a[i][i];
        }
    }
    for(int i = 0; i < t; i++)
    {
        cin >> M >> N;
        cout << a[M][N] << endl;   
    }
    return 0;
}
