#include <stdio.h>
#define ARRAYLEN 8     //��̬���ұ�Ԫ�س���
int source[]={69,65,90,37,92,6,28,54};   //��̬���ұ�

int SeqSearch(int s[],int n,int key)  //˳����ҷ���
{
    int i;
    for(i=0;i<n && s[i]!=key;i++)     //ѭ�����ҹؼ���
        ;      //��ѭ��
    if(i<n)    //���ҳɹ�
        return i;  //�����ҵ������
    else    //����ʧ��
        return -1;  //����ʧ��ֵ
}

int main()
{
    int key,i,pos;
    printf("������ؼ���:");
    scanf("%d",&key);              //������ҹؼ���
    pos=SeqSearch(source,ARRAYLEN,key);  //���ú������в���
    printf("ԭ���ݱ�:"); 
    for(i=0;i<ARRAYLEN;i++)         //�����̬���ұ�
        printf("%d ",source[i]);
    printf("\n");
    if(pos>=0)          //�жϲ����Ƿ�ɹ�
        printf("���ҳɹ����ùؼ���λ������ĵ�%d��λ�á�\n",pos);
    else
        printf("����ʧ��!\n");
    getch();
    return 0;
}
