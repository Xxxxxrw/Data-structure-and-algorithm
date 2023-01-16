#include <stdio.h>
#include "4-1 CreateData.c"   //生成随机数的函数
#define ARRAYLEN 10     //需要排序的数据元素数量
void SelectSort(int a[],int n)   //简单选择排序函数
{
    int i,j,t,k;
    for(i=0;i<n-1;i++)
    {
        k=i;                       //记录需和第k个元素交换
        for(j=i+1;j<n;j++)         //查找最小数据，保存其序号在k中
            if(a[k]>a[j]) k=j;
        t=a[i];                 //交换最小数据到数组前面
        a[i]=a[k];
        a[k]=t;    
    }
}
int main()
{
    int i,a[ARRAYLEN];         //定义数组
    for(i=0;i<ARRAYLEN;i++)   //清空数组
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))   //判断生成随机数是否成功
    {
        printf("生成随机数不成功!\n");
        getch();
        return 1;
    }
    printf("原数据:"); 
    for(i=0;i<ARRAYLEN;i++)   //输出成的随机数
        printf("%d ",a[i]);
    printf("\n");
    SelectSort(a,ARRAYLEN);   //调用简单选择排序算法
    printf("排序后:"); 
    for(i=0;i<ARRAYLEN;i++)   //输出排序后的结果
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
