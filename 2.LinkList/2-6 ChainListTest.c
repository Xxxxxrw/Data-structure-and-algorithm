#include <stdio.h>
typedef struct
{
	char key[15];
	char name[20];
	int age;
}DATA;
#include "2-4 ChainList.h"
#include "2-5 ChainList.c"
void ChainListAll(ChainListType *head)
{
	ChainListType *h;
	DATA data;
	h=head;
	printf("链表所有数据如下：\n");
	while(h)
	{
		data=h->data;
		printf("%s,%s,%d\n",data.key,data.name,data.age);
		h=h->next;
	}
	return;
}
int main()
{
	ChainListType* node,*head=NULL;
	DATA data;
	char key[15],findkey[15];
	
	printf("输入链表中的数据，包括关键字，姓名，年龄，关键字输入0，则退出：\n");
	do{
		fflush(stdin);
		scanf("%s",data.key);
		if(strcmp(data.key,"0")==0) break;
		scanf("%s%d",data.name,data.age);
		head=ChainListAddEnd(head,data);
		
	}while(1);
	
	printf("该链表共有%d个节点。\n",ChainListLength(head));
	ChainListAll(head);
	
	printf("\n插入节点，输入插入位置的关键字：");
	scanf("%s",&findkey);
	printf("输入插入节点的数据（关键字，姓名，年龄）:");
	scanf("%s %s %d",data.key,data.name,&data.age);
	head=ChainListInsert(head,findkey,data);
	
	ChainListAll(head);
	
	printf("\n在链表中查找，输入查找关键字：");
	fflush(stdin);
	scanf("%s",key);
	node=ChainListFind(head,key);
	if(node)
	{
		data=node->data;
		printf("关键字%s对应的节点数据为(%s,%s,%d)\n",key,data.key,data.name,data.age);
		
	}else
		printf("在链表中未找到关键字为%s的节点\n",key);
		
	printf("\n在链表中删除节点，输入要删除的关键字：");
	fflush(stdin);
	scanf("%s",key);
	ChainListDelete(head,key);
	ChainListAll(head);
	getch();
	return 0;
	
}
