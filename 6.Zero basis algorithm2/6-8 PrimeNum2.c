#include <stdio.h> 
#define MAXNUM 1000 //求1000以内的所有素数 
int main()
{
    int i,j,c=0;
    int prime[MAXNUM+1]; //保存素数
    for(i=2;i<=MAXNUM;i++) //初始化数组 
        prime[i]=1; //标志为1表示对应的数是素数 
    for(i=2;i*i<=MAXNUM;i++) //循环处理前i个 
    {
        if(prime[i]==1) //若为素数
        {
            for(j=2*i;j<=MAXNUM;j++) //筛去合数 
            {
                if(j%i==0) //能被整除 
                    prime[j]=0; //不是素数
            }
        }
    }
    for(i=2;i<MAXNUM;i++) //输出素数
    {
        if(prime[i]==1) //是素数，则输出 
        {
            printf("%4d ",i); //输出素数
            c++;
            if(c%10==0) //每行输出10个素数
                printf("\n");
        }
    }
    printf("\n");
    getch();
    return 0; 
}
