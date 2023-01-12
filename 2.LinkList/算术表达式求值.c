#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
typedef int DATA;
#include "2-8 SeqStack.h"
int IsOperator(char c)
{
	switch(c)
	{
		case'+':
		case'-':
		case'*':
		case'/':
		case'(':
		case')':
		case'=':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}
int PRI(char oper1,char oper2)
{
	int pri;
	switch(oper2)
	{
		case'+':
		case'-':
			if(oper1=='('||oper1=='=')
				pri=-1;
			else
				pri=1;
			break;
		case'*':
		case'/':
			if(oper1=='*'||oper1=='/'||oper1==')')
				pri=1;
			else
				pri=-1;
			break;
		case'(':
			if(oper1==')')
			{
				printf("语法错误\n");
				exit(0);
			}
			else
				pri=-1;
				break;
		case')':
			if(oper1=='(')
			{
				pri=0;
			}else if(oper1=='=')
			{
				printf("括号不匹配\n");
				exit(0);
			}else
				pri=1;
			break;
		case'=':
			if(oper1=='(')
			{
				printf("括号不匹配\n");
				exit(0);
			}
			else if(oper1=='=')
			{
				pri=0;
			}
			else
				pri=1;
			break;			
	}
	return pri;
}
int Calc(int a,int oper,int b)
{
	switch(oper)
	{
		case'+':return a+b;
		case'-':return a-b;
		case'*':return a*b;
		case'/':
			if(b!=0)
				return a/b;
			else
			{
				printf("除以0溢出\n");
				exit(0);
			}
	}
}
int CalcExp(char exp[])
{
	SeqStack * StackOper,*StackData;
	int i=0,flag=0;
	DATA a,b,c,q,x,t,oper;
	
	StackOper=SeqStackInit();
	StackData=SeqStackInit();
	
	q=0;
	x='=';
	SeqStackPush(StackOper,x);
	c=exp[i++];
	while(c!='='||x!='=')
	{
		if(IsOperator(c)){
		
		if(flag)
		{
			SeqStackPush(StackData,q);
			q=0;
			flag=0;
		}
		switch(PRI(x,c))
		{
			case -1:
				SeqStackPush(StackOper,c);
				c=exp[i++];
				break;
			case 0:
				c=SeqStackPop(StackOper);
				c=exp[i++];
				break;
			case 1:
				oper=SeqStackPop(StackOper);
				b=SeqStackPop(StackData);
				a=SeqStackPop(StackData);
				t=Calc(a,oper,b);
				SeqStackPush(StackData,t);
				break;
		}
	}
	else if(c>='0'&&c<='9')
	{
		c-='0';
		q=q*10+c;
		flag=1;
		c=exp[i++];
	}
	else
	{
		printf("输入错误\n");
		getch();
		exit(0);
	}
	x=SeqStackPeek(StackOper);
}
	q=SeqStackPop(StackData);
	SeqStackFree(StackOper);
	SeqStackFree(StackData);
	return q;
}
int main()
{
	int c;
	char exp[80];
	printf("请输入要计算的表达式（以=结束）:");
	scanf("%s",exp);
	printf("%s%d\n",exp,CalcExp(exp));
	getch();
	return 0;
}
