#include <stdio.h>

int main()
{
	int a=1;
	int * p1=&a;
	int * p2=NULL;
	if(p1=p2)
	{
		printf("1\n");
	}
	else if(p1==NULL)
	{
		printf("2\n");
	}else if(p2=NULL)
	{
		printf("3\n");
	}else
	{
		printf("4\n");
	}
	
	
	return 0;
}
