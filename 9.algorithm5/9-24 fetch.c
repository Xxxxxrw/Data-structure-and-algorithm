#include <stdio.h>
#define MAXN 11
int a[MAXN][MAXN], flag[MAXN][MAXN][MAXN][MAXN], n;  //定义二维数组a和四维数组flag
int max(int x, int y)  //求两个数的最大值
{
   if (x > y)
	  return x;
   else
	  return y;
}
void calc()  //根据状态方程求解函数
{
   int x1, x2, y1, y2;
   for (x1 = 1; x1 <= n; x1++)
   {
	  for (y1 = 1; y1 <= n; y1++)
	  {
		 for (x2 = x1; x2 <= n; x2++)
		 {
			for (y2 = 1; y2 <= y1; y2++)
			{
			   if (x1 == x2 && y1 == y2)
				  flag[x1][y1][x2][y2] =
					 flag[x1 - 1][y1][x2][y2 - 1] + a[x1][y1];
			   else if (x1 == x2 - 1 && y1 == y2)
				  flag[x1][y1][x2][y2] =
					 max(flag[x1 - 1][y1][x2][y2 - 1],
					 flag[x1][y1 - 1][x2][y2 - 1]) + a[x1][y1] + a[x2][y2];
			   else if (x1 == x2 && y1 == y2 + 1)
				  flag[x1][y1][x2][y2] =
					 max(flag[x1 - 1][y1][x2][y2 - 1],
					 flag[x1 - 1][y1][x2 - 1][y2]) + a[x1][y1] + a[x2][y2];
			   else
			   {
				  flag[x1][y1][x2][y2] =
					 max(flag[x1 - 1][y1][x2][y2 - 1],
					 flag[x1 - 1][y1][x2 - 1][y2]);
				  flag[x1][y1][x2][y2] =
					 max(flag[x1][y1][x2][y2], flag[x1][y1 - 1][x2][y2 - 1]);
				  flag[x1][y1][x2][y2] =
					 max(flag[x1][y1][x2][y2], flag[x1][y1 - 1][x2 - 1][y2]);
				  flag[x1][y1][x2][y2] =
					 flag[x1][y1][x2][y2] + a[x1][y1] + a[x2][y2];
			   }
			}
		 }
	  }
   }
}
int main()
{
   int x, y, p;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("fetch.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }    
   fscanf(fp1, "%d\n", &n);     //读入数据数量
   while (1)      //循环读入数据
   {
	  fscanf(fp1, "%d%d%d\n", &x, &y, &p);
	  if (x == 0 && y == 0 && p == 0)   //若为0，则退出循环
		 break;
	  a[x][y] = p;
   }
   fclose(fp1);
   calc(); //调用函数进行计算 
   if ((fp2 = fopen("fetch.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n", flag[n][n][n][n]); //输出结果 
   fprintf(fp2, "%d\n", flag[n][n][n][n]);
   fclose(fp2);
   getch();
   return 0;
}
