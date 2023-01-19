#include <stdio.h> 
#define MAXNUM 1000 //求1000以内的所有素数 
int PrimeNum(int i) //判断数i是否为质数 
{
    int j,flag=1;
    for(j=2;j<i-1;j++) //循环除以每个数 
    {
        if(i%j==0) //i能被j整除，表示不是质数 
        {
            flag=0;
            break; 
        }
    }
    return flag; //返回结果 
}
int PrimeNum1(int i) //判断数i是否为素数 
{
    int j,flag=1;
    for(j=2;j*j<i;j++) //循环除以每个数 
    {
        if(i%j==0) //i能被j整除，表示不是素数 
        {
            flag=0;
            break; 
        }
    }
    return flag; //返回结果 
}
int main()
{
    int i,j,c=0;
    int prime[MAXNUM+1]; //保存素数 
    for(i=2;i<=MAXNUM;i++) //初始化数组 
        prime[i]=1; //标志为1表示对应的数是素数 
    for(i=3;i<=MAXNUM;i++) //循环计算各数 
    {
        prime[i]=PrimeNum(i); //计算数i是否为素数 
    }
    for(i=2;i<MAXNUM;i++) //输出素数 
    {     
        if(prime[i]==1) //若是素数 
        {
            printf("%4d ",i); //输出素数 
            c++;
            if(c%10==0) //每行输出10个数据 
                printf("\n");
        }
    }
    printf("\n");
    getch();
    return 0; 
}
