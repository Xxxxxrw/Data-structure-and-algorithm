#include <stdio.h>
#include "4-1 CreateData.c"  //����������ĺ���
#define ARRAYLEN 10          //��Ҫ���������Ԫ������
int Division(int a[],int left, int right) //�ָ�� 
{
    int base=a[left];    //ȡ���Ԫ��Ϊ��׼Ԫ��
    while(left<right)      //������С���Ҳ����
    {
        while(left<right && a[right]>base)  
            --right;     //���������ҵ�һ���Ȼ�׼С��Ԫ��
        a[left]=a[right];     //���Ȼ�׼С�����Ƶ����
        while(left<right && a[left]<base )
            ++left;      //���������ҵ�һ���Ȼ�׼���Ԫ��
        a[right]=a[left];    //���Ȼ�׼������Ƶ��Ҳ�
    }
    a[left]=base;    //�����׼��
    return left;    //���ػ�׼���
}
void QuickSort(int a[],int left,int right)   //��������
{
    int i,j;
    if(left<right)      //������С���Ҳ����
    {
        i=Division(a,left,right);   //�ָ�
        QuickSort(a,left,i-1);     //����׼��ಿ�ֽ��еݹ�����
        QuickSort(a,i+1,right);    //����׼�Ҳಿ�ֽ��еݹ�����
    }
}
int main()
{
    int i,a[ARRAYLEN];      //��������
    for(i=0;i<ARRAYLEN;i++)  //�������
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))  //�ж�����������Ƿ�ɹ�
    {
        printf("������������ɹ�!\n");
        getch();
        return 1;
    }
    printf("ԭ����:"); 
    for(i=0;i<ARRAYLEN;i++)  //������ɵ������
        printf("%d ",a[i]);
    printf("\n");
    QuickSort(a,0,ARRAYLEN-1);   //���ÿ���������
    printf("�����:"); 
    for(i=0;i<ARRAYLEN;i++)   //��������Ľ��
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
