#include <stdio.h>
#define MONTH 12
int main()
{
   int money[MONTH], save, balance, i;          //数组money保存每月的预算
   FILE *fp1, *fp2;
   if ((fp1 = fopen("save.in", "r")) == NULL)   //打开文件，读取数据
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   if ((fp2 = fopen("save.out", "w")) == NULL)  //打开文件，写入数据
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   for (i = 0; i < MONTH; i++)	//读入12个月的预算 
	  fscanf(fp1, "%d", &money[i]);
   fclose(fp1);
   save = 0;
   balance = 0;
   for (i = 0; i < MONTH; i++)
   {
	  balance = balance + 300 - money[i];	//每月剩余金额 
	  while (balance >= 100)	//超过100 
	  {
		 save += 100;	//储蓄100 
		 balance -= 100;	//剩余部分 
	  }
	  if (balance < 0)	//若剩余部分小于0 
	  {
		 printf("%d\n", -(i + 1));	//输出本月不够 
		 fprintf(fp2, "%d\n", -(i + 1));
		 break;
	  }
   }
   if (balance > 0)	//余额大于0 
   {
	  printf("%.2f\n", balance + (save * 1.2));	//输出最后总的金额 
	  fprintf(fp2, "%.2f\n", balance + (save * 1.2));
   }
   getch();
   return 0;
}
