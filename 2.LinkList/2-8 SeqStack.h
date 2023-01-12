typedef struct stack
{
	DATA data[SIZE+1];
	int top;
}SeqStack;
SeqStack *SeqStackInit()
{
	SeqStack *p;
	if(p=(SeqStack *)malloc(sizeof(SeqStack)))
	{
		p->top=0;
		return p;
	}
	return NULL;
}
void SeqStackFree(SeqStack* s)
{
	if(s)
		free(s);
}
int SeqStackIsEmpty(SeqStack *s)
{
	return (s->top==0);
}
void SeqStackClear(SeqStack * s)
{
	s->top=0;
}
int SeqStackIsFull(SeqStack* s)
{
	return (s->top==SIZE);
}
int SeqStackPush(SeqStack * s,DATA data)
{
	if((s->top+1)>SIZE)
	{
		printf("Õ»Òç³ö\n");
		return 0;
	}
	s->data[++s->top]=data;
	return 1;
}
DATA SeqStackPop(SeqStack * s)
{
	if((s->top)==0)
	{
		printf("Õ»Îª¿Õ\n");
		exit(0);
		}	
	return (s->data[s->top--]);
} 
DATA SeqStackPeek(SeqStack *s)
{
	if(s->top==0)
	{
		printf("Õ»Îª¿Õ\n");
		exit(0);
	}
	return (s->data[s->top]);
}
