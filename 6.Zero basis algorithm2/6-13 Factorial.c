#include <stdio.h>
unsigned long factorial(unsigned long n)  //计算阶乘的函数 
{
    if(n<0)     //若n小于0，返回0 
        return 0;
    if(1==n)   //若n为1，返回阶乘结果为1 
        return 1;
    else
        return (unsigned long)n*factorial(n-1);  //递归调用计算阶乘 
}
int main()
{
    unsigned long n;
    printf("输入一个整数n(n>0):"); 
    scanf("%d",&n);     //输入求阶乘的数 
    printf("%lu!=%lu\n",n,factorial(n));  //输出阶乘结果 
    getch();
    return 0;
}
