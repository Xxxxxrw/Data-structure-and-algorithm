#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
int main()
{
    int i,n,sum=0; 
    double x,y;
    printf("输入点的数量:");
    scanf("%d",&n);       //输入产生随机数的数量 
    srand(time(NULL));    //初始化随机数生成器 
    for(i=1;i<n;i++)
    {
        x=(double)rand()/RAND_MAX; //产生0~1之间的一个随机数 x 
        y=(double)rand()/RAND_MAX;//产生0~1之间的一个随机数 y
        if((x*x+y*y)<=1) //若在阴影区域 
            sum++; //计数 
    }
    printf("PI=%f\n",(double)4*sum/n); //输出结果 
    getch();
    return 0; 
}
