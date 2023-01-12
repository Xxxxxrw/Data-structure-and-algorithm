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
	printf("���������������£�\n");
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
	
	printf("���������е����ݣ������ؼ��֣����������䣬�ؼ�������0�����˳���\n");
	do{
		fflush(stdin);
		scanf("%s",data.key);
		if(strcmp(data.key,"0")==0) break;
		scanf("%s%d",data.name,data.age);
		head=ChainListAddEnd(head,data);
		
	}while(1);
	
	printf("��������%d���ڵ㡣\n",ChainListLength(head));
	ChainListAll(head);
	
	printf("\n����ڵ㣬�������λ�õĹؼ��֣�");
	scanf("%s",&findkey);
	printf("�������ڵ�����ݣ��ؼ��֣����������䣩:");
	scanf("%s %s %d",data.key,data.name,&data.age);
	head=ChainListInsert(head,findkey,data);
	
	ChainListAll(head);
	
	printf("\n�������в��ң�������ҹؼ��֣�");
	fflush(stdin);
	scanf("%s",key);
	node=ChainListFind(head,key);
	if(node)
	{
		data=node->data;
		printf("�ؼ���%s��Ӧ�Ľڵ�����Ϊ(%s,%s,%d)\n",key,data.key,data.name,data.age);
		
	}else
		printf("��������δ�ҵ��ؼ���Ϊ%s�Ľڵ�\n",key);
		
	printf("\n��������ɾ���ڵ㣬����Ҫɾ���Ĺؼ��֣�");
	fflush(stdin);
	scanf("%s",key);
	ChainListDelete(head,key);
	ChainListAll(head);
	getch();
	return 0;
	
}
