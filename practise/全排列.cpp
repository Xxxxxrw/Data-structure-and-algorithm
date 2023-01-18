#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
set<int> sj;
set<int> s;
int n;
int Judge(int x)
{
	sj.clear();
    int b[n+1];
    int size = 1;
    for(int i = n; i > 0; i--)
	{
		b[i] = x % 10;
		x /= 10;	
	} 
	if(b[1] > n)
	{
		return -11;
	}
    for(int i = 1; i <= n; i++)
    {
        
        sj.insert(b[i]);
        if(size != sj.size() || b[i] > n)
        {
            if(size <= n)
            {
                return size;
            }
        }
        if(sj.count(0))
        	return size;
        size++;
    }
    
    return -1;
}
int main()
{
    int i,sum = 1,is9 = 0;
    int ret;
    scanf("%d",&n);
    if(n == 9)
    {
    	is9 = 1;
    	n--;
	}
    int a[n+1];
    
    for(i = 1; i < n; i++)
        sum *= 10;
    int msum = 10 * sum;
    for(i = sum; i < msum; i++)
    {
        ret = Judge(i) -1;
        if(ret >= 1 && ret != n-1)
        {
            int sum2 = 1;
            for(int j = 1; j < n-ret; j++)
            {
                sum2 *= 10;
            }
            i = i + sum2 -1;
        }
        else if(ret == -2)
        {
            s.insert(i);
        }
        else if(ret == -11)
        {
        	break;
		}
    }
    set<int>::iterator it;
	if( is9 != 1)
	{

	for(it = s.begin(); it != s.end(); it++)
    {
        int t = *it;
        for(i = n; i > 0; i--)
        {
            a[i] = t % 10;
            t /= 10;
        }
        for(int j = 1; j <= n; j++)
        {
            printf("%5d",a[j]);
        }
        printf("\n");
    }
	}
    if( is9 == 1)
    {
    	for(int z = n+1; z > 0; z--)
	{
	
    for(it = s.begin(); it != s.end(); it++)
    {
        int t = *it;
        for(i = n; i > 0; i--)
        {
            a[i] = t % 10;
            t /= 10;
        }
        
		
        for(int j = 1; j <= n+1; j++)
        {
        	if(j == z)
        		printf("%5d",n+1);
        	if(j<n+1)
            	printf("%5d",a[j]);
            
        }
    	
        printf("\n");
    	
    }
	}
	}
    return 0;
}
