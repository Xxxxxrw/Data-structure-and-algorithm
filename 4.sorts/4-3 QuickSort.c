#include <stdio.h>
#include "4-1 CreateData.c"  //生成随机数的函数
#define ARRAYLEN 10          //需要排序的数据元素数量
int Division(int a[],int left, int right) //分割函数 
{
    int base=a[left];    //取左侧元素为基准元素
    while(left<right)      //左侧序号小于右侧序号
    {
        while(left<right && a[right]>base)  
            --right;     //从右向左找第一个比基准小的元素
        a[left]=a[right];     //将比基准小的数移到左侧
        while(left<right && a[left]<base )
            ++left;      //从左向右找第一个比基准大的元素
        a[right]=a[left];    //将比基准大的数移到右侧
    }
    a[left]=base;    //保存基准数
    return left;    //返回基准序号
}
void QuickSort(int a[],int left,int right)   //快速排序
{
    int i,j;
    if(left<right)      //左侧序号小于右侧序号
    {
        i=Division(a,left,right);   //分割
        QuickSort(a,left,i-1);     //将基准左侧部分进行递归排序
        QuickSort(a,i+1,right);    //将基准右侧部分进行递归排序
    }
}
int main()
{
    int i,a[ARRAYLEN];      //定义数组
    for(i=0;i<ARRAYLEN;i++)  //清空数组
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))  //判断生成随机数是否成功
    {
        printf("生成随机数不成功!\n");
        getch();
        return 1;
    }
    printf("原数据:"); 
    for(i=0;i<ARRAYLEN;i++)  //输出生成的随机数
        printf("%d ",a[i]);
    printf("\n");
    QuickSort(a,0,ARRAYLEN-1);   //调用快速排序函数
    printf("排序后:"); 
    for(i=0;i<ARRAYLEN;i++)   //输出排序后的结果
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
