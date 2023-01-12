#define QUEUEMAX 15
typedef struct
{
	DATA data[QUEUEMAX];
	int head;
	int tail;
}CycQueue;
CycQueue* CycQueueInit()
{
	CycQueue* q;
	if(q=(CycQueue*)malloc(sizeof(CycQueue)))
	{
		q->head=0;
		q->tail=0;
		return q;
	}else{
		return NULL;
	}
} 
void CycQueueFree(CycQueue *q)
{
	if(q)
		free(q);
}
int CycQueueIsEmpty(CycQueue *q)
{
	return (q->head==q->tail);
}
int CycQueueIsFull(CycQueue *q)
{
	return ((q->tail+1)%QUEUEMAX==q->head);
}
int CycQueueIn(CycQueue*q,DATA data)
{
	if((q->tail+1)%QUEUEMAX==q->head)
	{
		printf("队列满了\n");
		return 0;
	}
	else
	{
		q->tail=(q->tail+1)%QUEUEMAX;
		q->data[q->tail]=data;
		return 1;
	}
}
DATA* CycQueueOut(CycQueue *q)
{
	if(q->head==q->tail)
	{
		printf("队列已空\n");
		return NULL;
	}else{
		q->head=(q->head+1)%QUEUEMAX;
		return &(q->data[q->head]);
	}
}
int CycQueueLen(CycQueue *q)
{
	int n;
	n=(q->tail-q->head+QUEUEMAX)%QUEUEMAX;
	return n;
}
DATA *CycQueuePeek(CycQueue *q)
{
	if(q->head==q->tail)
	{
		printf("队列已空\n");
		return NULL;
	}else{
		return &(q->data[(q->head+1)%QUEUEMAX]);
	}	
}
