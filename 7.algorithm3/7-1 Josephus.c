#include <stdio.h> 
#include <stdlib.h> 
#define N 41    //������
#define M 3     //����3����
int main()
{
    int man[N]={0};
    int count=1;
    int i=0,pos=-1;
    int alive=0;
    while(count<=N)    //��N������ѭ������
    {
        do{
            pos=(pos+1) % N;  //��״����
            if(man[pos]==0)   //���ñ���ѳ���
                i++;
            if(i==M) //����3���� 
            {
                i=0;
                break;
            }
        }while(1);
        man[pos]=count;
        count++;
    }
    printf("\nԼɪ������(���λ��-Լɪ��λ��):\n");  //�������λ��
    for(i=0;i<N;i++)
    {
        printf("%d-%d  ",i+1,man[i]);
        if(i!=0 && i%10==0) //ÿ���10������ 
            printf("\n");
    }
    printf("\n\n׼��ʣ�µ�������");
    scanf("%d", &alive);
    printf("��%d�˳�ʼλ��Ӧ�����������:\n",alive);
    alive=N-alive;          //�����������ı��
    for(i=0;i<N;i++)      //���ҵ��豣���ı��
        if(man[i]>alive)
            printf("��ʼ���:%d,Լɪ�����:%d\n",i+1,man[i]);
    printf("\n");
    getch();
    return 0;
}
