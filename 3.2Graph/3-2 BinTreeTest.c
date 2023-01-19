#include <stdio.h> 
#include "3-1 BinTree.c"   //�����Զ���ĺ����ļ�
void oper(ChainBinTree *p) //����������������� 
{
     printf("%c ",p->data); //�������
     return;
}
ChainBinTree *InitRoot()  //��ʼ���������ĸ� 
{
    ChainBinTree *node;
    if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))) //�����ڴ�
    {
        printf("\n������������:");
        scanf("%s",&node->data);
        node->left=NULL;                //������������Ϊ��
        node->right=NULL;
        return BinTreeInit(node);       //���ظ��ڵ�
    }
    return NULL;
}
void AddNode(ChainBinTree *bt)     //��������������ӽڵ�
{
     ChainBinTree *node,*parent;
     DATA data;
     char select;
    if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))) //�����ڴ�
    {
        printf("\n����������������:");
        fflush(stdin);//������뻺���� 
        scanf("%s",&node->data);
        node->left=NULL; //������������Ϊ�� 
        node->right=NULL;
        printf("���븸�������:");
        fflush(stdin);//������뻺���� 
        scanf("%s",&data);
        parent=BinTreeFind(bt,data);//����ָ�����ݵĽ�� 
        if(!parent)//��δ�ҵ�ָ�����ݵĽ�� 
        {
            printf("δ�ҵ������!\n");
            free(node); //�ͷŴ����Ľ���ڴ� 
            return;
         }
         printf("1.���ӵ�������\n2.���ӵ�������\n");
         do{
            select=getch();
            select-='0';
            if(select==1 || select==2)
                BinTreeAddNode(parent,node,select); //���ӽ�㵽������ 
         }while(select!=1 && select!=2);
    }
    return ;
}
int main() 
{
    ChainBinTree *root=NULL; //rootΪָ�������������ָ�� 
    char select;
    void (*oper1)(); //ָ������ָ�� 
    oper1=oper; //ָ���������ĺ��� 
    do{
        printf("\n1.���ö�������Ԫ��    2.���Ӷ��������\n");
        printf("3.�������            4.�������\n");
        printf("5.�������            6.�������\n");
        printf("7.���������          0.�˳�\n");
        select=getch();
        switch(select){
        case '1': //���ø�Ԫ�� 
             root=InitRoot();
             break;
        case '2': //���ӽ�� 
             AddNode(root);
             break;
        case '3'://�������
             printf("\n��������Ľ����");
             BinTree_DLR(root,oper1);
             printf("\n");
             break;
        case '4'://������� 
             printf("\n��������Ľ����");
             BinTree_LDR(root,oper1);
             printf("\n");
             break;
        case '5'://������� 
             printf("\n��������Ľ����");
             BinTree_LRD(root,oper1);
             printf("\n");
             break;
        case '6'://�������
             printf("\n��������Ľ����");
             BinTree_Level(root,oper1);
             printf("\n");
             break;
        case '7'://�����������
            printf("\n���������Ϊ:%d\n",BinTreeDepth(root));
            break; 
        case '0':
             break;
        }
    }while(select!='0');
    BinTreeClear(root);//��ն����� 
    root=NULL;
    getch();
    return 0;
}