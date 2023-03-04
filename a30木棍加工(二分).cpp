#include <bits/stdc++.h>
using namespace std;
/*
	�������������mid == l, ����ѭ�����³�ʱ������ļ���˼· 
	1. while(l + 1 < r)  ��l, r �ĸı�ֻ�� l = mid, r = mid ����
	
	2. while(l < r)  ��l, r �ĸı���� l = mid + 1 ���� r = mid - 1 ʱ, ��չ r, l �ı߽硣
	   �������������һ��������������ֵ�������� ��ֵ-1 
	
	3.���У�if(mid == l) mid += 1; ������ѭ�� 
*/
int n, k;
const int maxn = 1e5 + 5;
int a[maxn];
long long f(int x)
{
    long long tot = 0;
    for(int i = 0; i < n; i++)
    {
        tot += a[i] / x;
        if(tot > k)
        {
            return tot;
        }
    }
    return tot;
}
int main()
{
    cin >> n >> k;
    int r = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    int l = 1;
    //r += 1;
    if(f(l) < k)
    {
        cout << 0 << endl;
        return 0;
    }
    while(l < r)
    {
        int mid = l + (r - l) / 2;
        if(mid == l)
        {
            mid += 1;
        }
        
        if(f(mid) < k)
        {
            r = mid - 1;
        }
        else{
            l = mid ;
        }
    }
    cout << l  << endl;
    return 0;
}
