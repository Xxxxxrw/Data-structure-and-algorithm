#include <stdio.h>
#include "4-1 CreateData.c"   //����������ĺ���
#define ARRAYLEN 10     //��Ҫ���������Ԫ������
void SelectSort(int a[],int n)   //��ѡ��������
{
    int i,j,t,k;
    for(i=0;i<n-1;i++)
    {
        k=i;                       //��¼��͵�k��Ԫ�ؽ���
        for(j=i+1;j<n;j++)         //������С���ݣ������������k��
            if(a[k]>a[j]) k=j;
        t=a[i];                 //������С���ݵ�����ǰ��
        a[i]=a[k];
        a[k]=t;    
    }
}
int main()
{
    int i,a[ARRAYLEN];         //��������
    for(i=0;i<ARRAYLEN;i++)   //�������
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))   //�ж�����������Ƿ�ɹ�
    {
        printf("������������ɹ�!\n");
        getch();
        return 1;
    }
    printf("ԭ����:"); 
    for(i=0;i<ARRAYLEN;i++)   //����ɵ������
        printf("%d ",a[i]);
    printf("\n");
    SelectSort(a,ARRAYLEN);   //���ü�ѡ�������㷨
    printf("�����:"); 
    for(i=0;i<ARRAYLEN;i++)   //��������Ľ��
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}
