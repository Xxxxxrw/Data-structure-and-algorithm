#include <cstdio>
int N, n;
bool Isprime(int x)
{
    if(x == 1)
        return 0;
    for(int i = 2; i * i <= x; i++)
    {
        if(x % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    scanf("%d", &N);
    if(Isprime(N))
    {
        printf("%d=%d", N, N);
        return 0;
    }
    printf("%d=",N);
    n = N;
    for(int i = 2; 2 * i <= N; i++)
    {
        if(!Isprime(i))
            continue;
        while(n % i == 0)
        {
            printf("%d", i);
            
            n /= i;
            if(n >= i)
            {
                printf("*");
            }
        }
        if(Isprime(n))
        {
            printf("%d", n);
            break;
        }
    }
    return 0;
}

