#include <stdio.h>
#include <math.h>
int a[10];
void swap(int x,int y)
{
	int t=a[x];
	a[x]=a[y];
	a[y]=t;
}
int main()
{
	a[0]=0;
	a[1]=1;
	swap(0,1);
//	printf("%d\n",a[0]);
//	printf("%d\n",a[1]);
	int c=8;
	int d;
	d=4.6;
	printf("%d",d);
	return 0;
}
