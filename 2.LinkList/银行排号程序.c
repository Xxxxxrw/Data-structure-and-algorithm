#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
	int num;
	long time;
}DATA;
#include "2-12 CycQueue.h"
int num;
void add(CycQueue *q)
{
	DATA data;
	if(!CycQueueIsFull(q))
	{
		data.num=++num;
		data.time=time(NULL);
		//printf("\nʱ��Ϊ%d\n",data.time);
		CycQueueIn(q,data); 
	}else{
		printf("\n�Ŷӵ���̫�࣬���Ժ����ţ�\n");
	}
}
void next(CycQueue * q)
{
	DATA * data;
	if(!CycQueueIsEmpty(q))
	{
		data=CycQueueOut(q);
		printf("\n����Ϊ%d�Ĺ˿Ͱ���ҵ��\n",data->num);
	}
	if(!CycQueueIsEmpty(q))
	{
		data=CycQueuePeek(q);
		printf("\n����Ϊ%d�Ĺ˿�׼������ҵ��\n",data->num);
	}
}
int main()
{
	CycQueue *queuel;
	int i,n;
	char select;
	num=0;
	queuel=CycQueueInit();
	if(queuel==NULL)
	{
		printf("��������ʱ����\n");
		getch();
		return 0;
	}
	do{
		printf("\n��ѡ����������\n");
		printf("1.�µ��˿�\n");
		printf("2.��һ���˿�\n");
		printf("0.�˳�\n");
		fflush(stdin);
		select=getch();
		switch(select)
		{
			case '1':
				add(queuel);
				printf("\n������%d���˿��ڵȴ�\n",CycQueueLen(queuel));
				
				break;
			case '2':
				next(queuel);
				printf("\n������%d���˿��ڵȴ�\n",CycQueueLen(queuel));
				break;
			case '0':
				break;
		}
	}while(select!='0');
	CycQueueFree(queuel);
	getch();
	return 0;
}
