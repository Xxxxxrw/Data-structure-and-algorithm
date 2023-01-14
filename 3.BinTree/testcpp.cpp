#include <iostream>

using namespace std;

int main()
{
	int a[10005];
	int b[10005];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int top = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j < top; j++)
        {
            if(b[j] == a[i])
            {
                continue;
            }
            b[top++] = a[i];
        }
    }
    cout << top;
    if(top > 0)
    {
        for(int i = top-1; i > 0; i++)
        {
           cout << b[i] << " ";
        }
    }
    return 0;
}
