#include <stdio.h>
#define MAXN 10
int parvalue[MAXN]={10000,5000,2000,1000,500,200,100,50,20,10};//���������������� 
int num[MAXN]={0};  //��������Ǯ�и���Ӧ��ֵ������ҵ����� 
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
	printf("����������Ľ�");
	scanf("%f",&m);
	exchange((int)100*m);
	printf("\n%.2fԪ��Ǯ����ɣ�\n",m);
	for(i=0;i<MAXN;i++)
		if(num[i]>0)
			printf("%6.2f:%d��\n",(float)parvalue[i]/100.0,num[i]);	
	getch();
	return 0; 
} 
