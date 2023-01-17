#include <stdio.h>
#define ARRAYLEN 8     //静态查找表元素长度
int source[]={69,65,90,37,92,6,28,54};   //静态查找表

int SeqSearch(int s[],int n,int key)  //顺序查找方法
{
    int i;
    for(i=0;i<n && s[i]!=key;i++)     //循环查找关键字
        ;      //空循环
    if(i<n)    //查找成功
        return i;  //返回找到的序号
    else    //查找失败
        return -1;  //返回失败值
}

int main()
{
    int key,i,pos;
    printf("请输入关键字:");
    scanf("%d",&key);              //输入查找关键字
    pos=SeqSearch(source,ARRAYLEN,key);  //调用函数进行查找
    printf("原数据表:"); 
    for(i=0;i<ARRAYLEN;i++)         //输出静态查找表
        printf("%d ",source[i]);
    printf("\n");
    if(pos>=0)          //判断查找是否成功
        printf("查找成功，该关键字位于数组的第%d个位置。\n",pos);
    else
        printf("查找失败!\n");
    getch();
    return 0;
}
