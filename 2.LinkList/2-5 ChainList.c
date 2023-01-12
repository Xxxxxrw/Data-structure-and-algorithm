#include <string.h>
ChainListType *ChainListAddEnd(ChainListType *head, DATA data)
{
	ChainListType * p=head;
	ChainListType * node;
	if(!(node=(ChainListType *)malloc(sizeof(ChainListType))));
	{
		printf("·ÖÅäÄÚ´æ¿Õ¼äÊ§°Ü\n");
		return NULL;
	}
	while(p->next)
	{
		p=p->next;
	}
	node->data=data;
	node->next=NULL;
	if(head==NULL)
	{
		head=node;
		return head;
	}
	p->next=node;
	
	return head;
	
}
ChainListType *ChainListAddFirst(ChainListType* head,DATA data)
{
	ChainListType * node;
	if(!(node=(ChainListType*)malloc(sizeof(ChainListType))));
	{
		printf("·ÖÅäÄÚ´æ¿Õ¼äÊ§°Ü\n");
		return NULL;
	}
	node->data=data;
	node->next=head;
	head=node;
	return head;
}
ChainListType *ChainListFind(ChainListType * head,char * key)
{
	ChainListType * p=head;
	while(p->next)
	{
		if(strcmp(p->data.key,key)==0)
			return p;
		p=p->next;
	}
	return NULL;
}
ChainListType *ChainListInsert(ChainListType * head,char* findkey,DATA data)
{
	ChainListType * node,*node1;
	if(!(node=(ChainListType*)malloc(sizeof(ChainListType))));
	{
		printf("·ÖÅäÄÚ´æ¿Õ¼äÊ§°Ü\n");
		return NULL;
	}
	node->data=data;
	node1=ChainListFind(head,findkey);
	if(node1)
	{
		node->next=node1->next;
		node1->next=node;
	}
	else
	{
		free(node);
		printf("Î´ÕÒµ½²åÈëÎ»ÖÃ\n");
	}
	return head;
}
int ChainListDelete(ChainListType * head,char *key)
{
	ChainListType * node,*h;
	node=h=head;
	while(h)
	{
		if(strcmp(h->data.key,key)==0)
		{
			node->next=h->next;
			free(h);
			return 1;
		}
		else
		{
			node=h;
			h=h->next;
		}
	}
	return 0;
}
int ChainListLength(ChainListType *head)
{
	int count;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}
