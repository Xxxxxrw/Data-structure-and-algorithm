#include <stdio.h>
#include "3-1 BinTree.c"
void oper(ChainBinTree *p)
{
	printf("%c ",p->data);
	return;
}
ChainBinTree *InitRoot()
{
	ChainBinTree *node;
	if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree)))
	{
		printf("\n输入根节点数据:");
		scanf("%s",&node->data);
		node->left=NULL;
		node->right=NULL;
		return node;
	}
	return NULL;
}
void AddNode(ChainBinTree *bt)
{
	ChainBinTree *node,*parent;
	DATA data;
	char select;
	if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree)))
	{
		printf("\n输入二叉树节点数据：");
		fflush(stdin);
		scanf("%s",&node->data);
		node->left=NULL;
		node->right=NULL;
		printf("输入父节点数据：");
		fflush(stdin);
		scanf("%s",&data);
		parent=BinTreeFind(bt,data);
		if(!parent)
		{
			printf("未找到父节点！\n");
			free(node);
			return;
		}
		printf("1.添加到左子树\n2.添加到右子树\n");
		do{
			select=getch();
			select-='0';
			if(select==1||select==2)
			    BinTreeAddNode(parent,node,select);
		}while(select!=1&&select!=2);
	}
	return;
}
int main()
{
	ChainBinTree *root=NULL;
	char select;
	void (*oper1)();
	oper1=oper;
	
	
	
	return 0;
}
