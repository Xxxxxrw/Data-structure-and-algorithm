#include <stdio.h>
#define MAXN 10
int parvalue[MAXN]={10000,5000,2000,1000,500,200,100,50,20,10};//定义人民币面额数组 
int num[MAXN]={0};  //定义找零钱中各对应面值的人民币的数量 
int exchange(int n)
{
	int i=0;
	while(n>0)
	{
		if(n>=parvalue[i])
		{
			n=n-parvalue[i];
			num[i]++;
		}
		else if(n<10)
		{
			num[MAXN-1]++;
			break;
		}
		else
			i++;
			
	}
}

int main()
{
	int i;
	float m;
	printf("请输入找零的金额：");
	scanf("%f",&m);
	exchange((int)100*m);
	printf("\n%.2f元零钱的组成：\n",m);
	for(i=0;i<MAXN;i++)
		if(num[i]>0)
			printf("%6.2f:%d张\n",(float)parvalue[i]/100.0,num[i]);	
	getch();
	return 0; 
} 
