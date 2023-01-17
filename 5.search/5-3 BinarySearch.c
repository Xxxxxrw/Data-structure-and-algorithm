#include <stdio.h>
#define ARRAYLEN 10
int source[]={6,12,28,37,54,65,69,83,90,92};  //������ұ�

int BinarySearch(int s[],int n,int key)   //�۰���Һ���
{
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)        //���ҷ�Χ��������һ��Ԫ�� 
    {
        mid=(low+high)/2;   //�����м�λ����� 
        if(s[mid]==key)      //�м�Ԫ����ؼ������ 
            return mid;      //������� 
        else if(s[mid]>key)  //�м�Ԫ�ش��ڹؼ��� 
            high=mid-1;     //�ض�����ҷ�Χ 
        else                 //�м�Ԫ��С�ڹؼ��� 
            low=mid+1;       //�ض�����ҷ�Χ 
    }
    return -1;               //���ز���ʧ�� 
}

int main()
{
    int key,i,pos;
    printf("������ؼ���:");
    scanf("%d",&key);                       //������ҹؼ���
    pos=BinarySearch(source,ARRAYLEN,key);  //�����۰���Һ������в���
    printf("ԭ���ݱ�:"); 
    for(i=0;i<ARRAYLEN;i++)            //��ʾ���ұ��е�����
        printf("%d ",source[i]);
    printf("\n");
    if(pos>=0)      //���ݲ��ҽ�������ͬ��ֵ
        printf("���ҳɹ����ùؼ���λ������ĵ�%d��λ�á�\n",pos);
    else
        printf("����ʧ��!\n");
    getch();
    return 0;
}
