#include <stdio.h>
unsigned long factorial(unsigned long n)  //����׳˵ĺ��� 
{
    if(n<0)     //��nС��0������0 
        return 0;
    if(1==n)   //��nΪ1�����ؽ׳˽��Ϊ1 
        return 1;
    else
        return (unsigned long)n*factorial(n-1);  //�ݹ���ü���׳� 
}
int main()
{
    unsigned long n;
    printf("����һ������n(n>0):"); 
    scanf("%d",&n);     //������׳˵��� 
    printf("%lu!=%lu\n",n,factorial(n));  //����׳˽�� 
    getch();
    return 0;
}
