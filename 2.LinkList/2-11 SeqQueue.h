#define QUEUEMAX 15
typedef struct
{
	DATA data[QUEUEMAX];
	int head;
	int tail;
}SeqQueue;
SeqQueue *SeqQueueInit()
{
	SeqQueue *q;
	if(q=(SeqQueue *)malloc(sizeof(SeqQueue)))
	{
		q->head=0;
		q->tail=0;
		return q;
	}else
		return NULL;
}
void SeqQueueFree(SeqQueue *q)
{
	if(q)
		free(q);
}
int SeqQueueIsFull(SeqQueue * q)
{
	return (q->tail==QUEUEMAX);
}
int SeqQueueIn(SeqQueue *q,DATA data)
{
	if(q->tail==QUEUEMAX)
	{
		printf("��������\n");
		return 0;
	}
	else
	{
		q->data[q->tail++]=data;
		return 1;
	}
}
DATA * SeqQueueOut(SeqQueue* q)
{
	if(q->head==q->tail)
	{
		printf("\n�����ѿ�\n");
		return NULL;
	}else
	{
		return &(q->data[q->head++]);
	}
}
DATA *SeqQueuePeek(SeqQueue *q)
{
	if(SeqQueueIsEmpty(q))
	{
		printf("\n����Ϊ��\n");
		return NULL;
	}else{
		return &(q->data[q->head]);
	}
}
