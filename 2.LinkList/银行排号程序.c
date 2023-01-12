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
		//printf("\n时间为%d\n",data.time);
		CycQueueIn(q,data); 
	}else{
		printf("\n排队的人太多，亲稍后再排！\n");
	}
}
void next(CycQueue * q)
{
	DATA * data;
	if(!CycQueueIsEmpty(q))
	{
		data=CycQueueOut(q);
		printf("\n请编号为%d的顾客办理业务！\n",data->num);
	}
	if(!CycQueueIsEmpty(q))
	{
		data=CycQueuePeek(q);
		printf("\n请编号为%d的顾客准备办理业务！\n",data->num);
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
		printf("创建队列时出错\n");
		getch();
		return 0;
	}
	do{
		printf("\n请选择具体操作：\n");
		printf("1.新到顾客\n");
		printf("2.下一个顾客\n");
		printf("0.退出\n");
		fflush(stdin);
		select=getch();
		switch(select)
		{
			case '1':
				add(queuel);
				printf("\n现在有%d名顾客在等待\n",CycQueueLen(queuel));
				
				break;
			case '2':
				next(queuel);
				printf("\n现在有%d名顾客在等待\n",CycQueueLen(queuel));
				break;
			case '0':
				break;
		}
	}while(select!='0');
	CycQueueFree(queuel);
	getch();
	return 0;
}
