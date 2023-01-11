#include <stdio.h>
#include <time.h>
int main()
{
	int rightNum=-1,num,n;
	printf("请选择：a:自行设置数据 b:使用系统自动生成的正整数(默认随机数在[1,1000],可猜次数为8)：\n");
	
	
	if(getchar()=='a')
	{
		printf("请输入正确的数：\n"); 
		scanf("%d",&rightNum);
		printf("请输入可猜测次数：\n");
	    scanf("%d",&n); 
    }
	else
	{
		srand((unsigned int)time(NULL));
		rightNum=rand()%1000+1; 
		n=9;
	}
	system("cls");
	
	while(n>0)
	{
		n--;
		printf("请输入您猜的数：");
		scanf("%d",&num);
		if(num>rightNum)
		{
			printf("猜大了\n"); 
		}
		else if(num<rightNum)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}
	}
	if(n==0)
	{
		printf("您已用完全部次数，正确答案为%d结束游戏！",rightNum);
	}
	getch();
	return 0;
}
