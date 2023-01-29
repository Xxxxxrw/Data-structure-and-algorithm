#include <cstdio>
#include <string.h>
char s[101][101];
char min[101];
bool vis[101];
int N, f;
bool Judge(char m[101], char str[101])
{
    int t1 = 0, t2 = 0;
    int len1 = strlen(m);
    int len2 = strlen(str);
    
    while(t1 < len1 && t2 < len2)
    {
    long long sum1 = 0, sum2 = 0;
    while(m[t1] >= '0' && m[t1] <= '9')
    {
        sum1 = sum1 * 10 + m[t1];
        t1++;
    }
    while(str[t2] >= '0' && str[t2] <= '9')
    {
        sum2 = sum2 * 10 + str[t2];
        t2++;
    }
    if(sum1 > sum2)
        return 1;
    if(sum1 < sum2)
        return 0;
    t1++;
    t2++;
    }
    return len1 > len2;
}
int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s", s[i]);
    }
    for(int i = 0; i < N; i++)
    {
        strcpy(min, "123344555667788");
        for(int j = 0; j < N; j++)
        {
            if(!vis[j] && Judge(min, s[j]))
            {
                strcpy(min, s[j]);
                f = j;
            }
        }
        vis[f] = 1;
        printf("%s\n", min);
    }
    return 0;
}
