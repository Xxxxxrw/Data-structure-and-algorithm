#include <stdio.h>
#define ARRAYLEN 10
int source[]={6,12,28,37,54,65,69,83,90,92};  //有序查找表

int BinarySearch(int s[],int n,int key)   //折半查找函数
{
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)        //查找范围包含至少一个元素 
    {
        mid=(low+high)/2;   //计算中间位置序号 
        if(s[mid]==key)      //中间元素与关键字相等 
            return mid;      //返回序号 
        else if(s[mid]>key)  //中间元素大于关键字 
            high=mid-1;     //重定义查找范围 
        else                 //中间元素小于关键字 
            low=mid+1;       //重定义查找范围 
    }
    return -1;               //返回查找失败 
}

int main()
{
    int key,i,pos;
    printf("请输入关键字:");
    scanf("%d",&key);                       //输入查找关键字
    pos=BinarySearch(source,ARRAYLEN,key);  //调用折半查找函数进行查找
    printf("原数据表:"); 
    for(i=0;i<ARRAYLEN;i++)            //显示查找表中的数据
        printf("%d ",source[i]);
    printf("\n");
    if(pos>=0)      //根据查找结果输出不同的值
        printf("查找成功，该关键字位于数组的第%d个位置。\n",pos);
    else
        printf("查找失败!\n");
    getch();
    return 0;
}
