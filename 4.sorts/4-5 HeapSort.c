#include <stdio.h>
#include "4-1 CreateData.c"     //生成随机数的函数
#define ARRAYLEN 10             //需要排序的数据元素数量
void HeapAdjust(int a[],int s,int n)//构成堆
{
    int j,t;
    while(2*s+1<n) //第s个结点有右子树 
    {
        j=2*s+1 ;
        if((j+1)<n)
        {            
            if(a[j]<a[j+1])//左子树小于右子树，则需要比较右子树
                j++; //序号增加1，指向右子树 
        }
        if(a[s]<a[j])//比较s与j为序号的数据
        {            
            t=a[s];  //交换数据 
            a[s]=a[j];
            a[j]=t;            
            s=j ;//堆被破坏，需要重新调整
        }
        else //比较左右孩子均大则堆未破坏，不再需要调整
            break;   //退出循环
    }
}
void HeapSort(int a[],int n)//堆排序
{
    int t,i;
    int j;
    for(i=n/2-1;i>=0;i--)    //将a[0,n-1]建成大根堆
        HeapAdjust(a, i, n);
    for(i=n-1;i>0;i--)   //取根节点与末节点交换
    {
        t=a[0];//与第i个记录交换
        a[0] =a[i];
        a[i] =t;
        HeapAdjust(a,0,i);        //将a[0]至a[i]重新调整为堆
    }  
}
int main()
{
    int i,a[ARRAYLEN];        //定义数组
    for(i=0;i<ARRAYLEN;i++)   //清空数组
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))   //判断生成随机数是否成功
    {
        printf("生成随机数不成功!\n");
        getch();
        return 1;
    }
    printf("原数据:"); 
    for(i=0;i<ARRAYLEN;i++)   //输出生成的随机数
        printf("%d ",a[i]);
    printf("\n");
    HeapSort(a,ARRAYLEN);    //调用堆排序函数
    printf("排序后:"); 
    for(i=0;i<ARRAYLEN;i++)   //输出排序后的结果
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
