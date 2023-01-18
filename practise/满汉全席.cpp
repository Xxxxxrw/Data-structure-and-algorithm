#include <cstdio>
using namespace std;
int k,n,m;
int favor[1005][4];
bool cheif[55];
bool Judge(int b, int x)
{
    cheif[n - x + 1] = b;
    
    if( x == 1)
    {
        for(int i = 1; i <= m; i++)
        {
            if( cheif[favor[i][1]] != favor[i][0] && cheif[favor[i][3]] != favor[i][2])
            {
                return 0;
            }
        }
        return 1;
    }
    if(Judge(1,x-1) || Judge(2,x-1))
    {
        return 1;
    }
    else 
        return 0;
}

int main()
{
    scanf("%d",&k);
    for(int i = 0; i < k; i++)
    {
        scanf("%d %d", &n, &m);
        char str1[3];
        char str2[3];
        for(int j = 1; j <= m; j++)
        {
            scanf("%s %s",str1,str2);
            if(str1[0] == 'm')     //用 1 代表 m满，用 2 代表 h汉 
            {
                favor[j][0] = 1;
            }
            else
            {
                favor[j][0] = 2;
            }
            favor[j][1] = str1[1] - '0';
            if(str2[0] == 'm')
            {
                favor[j][2] = 1;
            }
            else
            {
                favor[j][2] = 2;
            }
            favor[j][3] = str2[1] - '0';
        }
        if(Judge( 1, n ) || Judge( 2, n) )
            printf("GOOD\n");
        else
            printf("BAD\n");
        printf("\n");
    }
    return 0;
}
