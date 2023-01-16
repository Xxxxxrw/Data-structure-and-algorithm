#include <stdio.h>
#include "4-1 CreateData.c"    //引入自定义的外部文件
#define ARRAYLEN 6
void BubbleSort(int a[],int n)   //冒泡排序
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j-1]>a[j])
            {
                t=a[j-1];       //交换数据
                a[j-1]=a[j];
                a[j]=t;
            }
        }
        printf("第%2d遍:",i+1); 
        for(j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
    }
}
void BubbleSort1(int a[],int n)  //冒泡排序
{
    int i,j,t,flag=0;        //flag用来标记是否发生交换
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j-1]>a[j])//交换数据 
            {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
                flag=1;   //有数据交换，设置标志变量
            }
        }
        printf("第%2d遍:",i+1); 
        for(j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
        if(flag==0)    //没发生交换,直接跳出循环
            break;
        else
            flag=0;
    }
}
int main()
{
    int i,a[ARRAYLEN];        //定义数组
    for(i=0;i<ARRAYLEN;i++)   //清空数组
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))  //判断生成随机数是否成功
    {
        printf("生成随机数不成功!\n");
        getch();
        return 1;
    }
    printf("原数据:"); 
    for(i=0;i<ARRAYLEN;i++)   //输出生成的随机数
        printf("%d ",a[i]);
    printf("\n");
    BubbleSort1(a,ARRAYLEN);  //调用冒泡排序函数进行排序
    printf("排序后:"); 
    for(i=0;i<ARRAYLEN;i++)    //输出排序后的结果
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
