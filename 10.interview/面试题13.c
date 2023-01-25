#include "stdio.h"

typedef struct BiTNode{    //定义二叉树的节点结构体
    char data;
    struct BiTNode *lchild , *rchild;
} BNode , *BTree;

void CreatBTree(BTree *T)   //构建二叉树
{
    char c;
    scanf("%c",&c);
    if(' '==c) 
        *T = NULL;
    else
    {
        *T = (BNode * )malloc(sizeof(BNode)); 
        (*T)->data = c;
        CreatBTree(&((*T)->lchild));
        CreatBTree(&((*T)->rchild));
    }
}

void DLR(BTree T )  //前序遍历（根左右） 
{
    if(T)
    {
        printf("%3c",T->data);
        DLR(T->lchild);
        DLR(T->rchild);
    }
}

void LDR(BTree T)//中序遍历（左根右）
{
    if(T)
    {
        LDR(T->lchild); 
        printf("%3c",T->data);
        LDR(T->rchild);
    }
}

void LRD(BTree T)//后序遍历（左右根）
{
    if(T)
    {
        LRD(T->lchild);
        LRD(T->rchild);
        printf("%3c",T->data);
    }
}

int main()
{
   BTree T = NULL;	
   printf("输入创建二叉树的字符串：");
   CreatBTree(&T); 
   printf("\n前序遍历二叉树：");
   DLR(T);
   printf("\n中序遍历二叉树：");
   LDR(T);
   printf("\n后序遍历二叉树：");
   LRD(T);
   getche();
   return 0;
}