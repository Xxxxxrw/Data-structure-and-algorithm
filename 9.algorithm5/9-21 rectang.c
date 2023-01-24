#include <stdio.h>
#define MAXN 50
#define MAXK 3
typedef struct VERTEX
{
   int x, y;	//点的坐标 
}VERTEX;
typedef struct rect
{
   VERTEX lt;	//左上角坐标
   VERTEX rb;	//右下角坐标 
}RECT;
RECT rect[MAXK]; 
VERTEX v[MAXK][MAXN];	//保存顶点数  
int n, k;
int intersect(RECT rect1, RECT rect2) //判断两矩形是否有公共点(是否交叉)
{
   if (rect2.lt.x > rect1.rb.x || rect1.lt.x > rect2.rb.x)	//矩形2左边大于矩形1的右边 /或矩形1左边大于矩形2的右边 
	  return 0;
   if (rect2.lt.y > rect1.rb.y || rect1.lt.y > rect2.rb.y)	//矩形2上边大于矩形1的底边 /或矩形1的上边大于矩形2的底边
	  return 0;
   return 1;
}
int area(RECT rect) //求矩形面积
{
   int height, s;
   height = rect.rb.y - rect.lt.y;	//高度 
   s = height * (rect.rb.x - rect.lt.x);
   return s;	//返回面积    
}
void insert(VERTEX v, RECT * rect) //将点放入矩形，并根据情况调整矩形的坐标 
{
   if (v.x < rect->lt.x)	//点的x坐标小于矩形左侧坐标 
	  rect->lt.x = v.x;	//调整矩形左侧坐标 
   if (v.x > rect->rb.x)
	  rect->rb.x = v.x;
   if (v.y < rect->lt.y)
	  rect->lt.y = v.y;
   if (v.y > rect->rb.y)
	  rect->rb.y = v.y;
}
int calc() //试探计算各矩形的面积 
{
   VERTEX v0;	//临时交换使用 
   int i, j, m, s, temp, min;
   min = 2147483647;	//保存一个最大值 
   switch (k)	//根据矩形个数进行不同处理 
   {
   case 1:	//k=1的情况
      rect[0].lt.x=v[0][1].x; //横向升序排列坐标的x值 
      rect[0].lt.y=v[1][1].y; //纵向升序排列坐标的y值 
      rect[0].rb.x=v[0][n].x; //横向升序排列坐标的x值 
      rect[0].rb.y=v[1][n].y; //纵向升序排列坐标的y值 
	  min = area(rect[0]);	//计算面积 
	  break;
   case 2:	//k=2的情况 
	  for (s = 0; s <= 1; s++)
	  {
		 rect[0].lt = rect[1].rb = v[s][1];	//第1个矩形
		 for (i = 2; i <= n; i++)	//将各点试着放入第2个矩形 
		 {
			insert(v[s][i - 1], &rect[0]);	//将第i-1点放入矩形1
			rect[1].lt = rect[2].rb = v[s][i];	//设置第2个矩形的初始值 
			for (m = i + 1; m <= n; m++)	//将剩余点添加到矩形2 
			   insert(v[s][m], &rect[1]);
			if (!intersect(rect[0], rect[1]))	//若两矩形不相交 
			{
			   temp = 0;
			   for (m = 0; m < k; m++)	//计算两矩形面积 
				  temp += area(rect[m]);
			   if (temp < min)	//若两矩形面积小于min 
				  min = temp;	//保存较小的面积 
			}
		 }
	  }
	  break;
   case 3:
	  //flag=0,1的情况
	  for (s = 0; s <= 1; s++)
	  {
		 rect[0].lt = rect[0].rb = v[s][1];	//第1个矩形 
		 for (i = 2; i <= n - 1; i++)	//将各点试着放入第2个矩形 
		 {
			insert(v[s][i - 1], &rect[0]);	//将第i-1点放入矩形1
			rect[1].lt = rect[1].rb = v[s][i];	//设置第2个矩形的初始值 
			if (intersect(rect[0], rect[1]))	//若两个矩形相交 
			   continue;	//继续处理下一个矩形 
			for (j = i + 1; j <= n; j++)	//将各点试着放入第2个矩形 
			{
			   insert(v[s][j - 1], &rect[1]);	//将第i-1点放入矩形1
			   rect[2].lt = rect[2].rb = v[s][j];	//设置第3个矩形的初始值 
			   for (m = j + 1; m <= n; m++)	//将剩余点添加到矩形3 
				  insert(v[s][m], &rect[2]);
			   if (intersect(rect[1], rect[2]))	//若矩形2与矩形3相交 
				  continue;	//继续处理下一个矩形 
			   temp = 0;
			   for (m = 0; m < k; m++)	//计算各矩形面积 
				  temp += area(rect[m]);
			   if (temp < min)
				  min = temp;
			}
		 }
	  }
	  //flag=2的情况:先竖直划分大矩形；再在右矩形中水平划分
	  rect[0].lt = rect[0].rb = v[0][1];	//第1个矩形初始值 
	  for (i = 2; i <= n - 1; i++)
	  {
		 for (m = 1; m <= n; m++)	//v[2][i]保存横坐标
			v[2][m] = v[0][m];
		 for (m = i; m <= n - 1; m++)	//将v[2][i]按坐标升序排序 
		 {
			for (s = m + 1; s <= n; s++)
			{
			   if (v[2][m].y > v[2][s].y)
			   {
				  v0 = v[2][m];
				  v[2][m] = v[2][s];
				  v[2][s] = v0;
			   }
			}
		 }
		 insert(v[2][i - 1], &rect[0]);	//将第i-1点放入矩形1
		 rect[1].lt = rect[1].rb = v[2][i];	//设置第2个矩形初始值
		 if (intersect(rect[0], rect[1]))	//矩形1与矩形2相交 
			continue;
		 for (j = i + 1; j <= n; j++)
		 {
			insert(v[2][j - 1], &rect[1]);	//将第j-1点放入矩形2
			rect[2].lt = rect[2].rb = v[2][j];	//设置第3个矩形初始值 
			for (m = j + 1; m <= n; m++)	//将后续顶点放入矩形3
			   insert(v[2][m], &rect[2]);
			if (intersect(rect[1], rect[2]))	//若矩形2与矩形3相交 
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)	//计算各矩形的面积 
			   temp += area(rect[m]);
			if (temp < min)	//保存面积最小值 
			   min = temp;
		 }
	  }
	  //flag=3的情况 
	  for (j = 3; j <= n; j++)
	  {
		 for (m = 1; m <= n; m++)
			v[2][m] = v[0][m];
		 for (m = 1; m <= j - 2; m++)	//按纵坐标排序 
		 {
			for (s = m + 1; s <= j - 1; s++)
			{
			   if (v[2][m].y > v[2][s].y)
			   {
				  v0 = v[2][m];
				  v[2][m] = v[2][s];
				  v[2][s] = v0;
			   }
			}
		 }
		 rect[2].lt = rect[2].rb = v[2][j];	//初始化第3个矩形 
		 for (m = j + 1; m <= n; m++)	//将点增加到第3个矩形 
			insert(v[2][m], &rect[2]);
		 for (i = 2; i <= j - 1; i++)
		 {
			rect[1].lt = rect[1].rb = v[2][i];	//设置第2个矩形初始值 
			for (m = i + 1; m <= j - 1; m++)	//将点添加到第2个矩形 
			   insert(v[2][m], &rect[1]);
			rect[0].lt = rect[0].rb = v[2][1];	//设置第1个矩形初始值 
			for (m = 2; m <= i - 1; m++)	//将点添到加第1个矩形 
			   insert(v[2][m], &rect[0]);
			if (intersect(rect[0], rect[1]) || intersect(rect[1], rect[2])
			   || intersect(rect[0], rect[2]))	//若3个矩形有相交情形 
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)	//计算各矩形面积 
			   temp += area(rect[m]);
			if (temp < min)	//保存最小面积 
			   min = temp;
		 }
	  }
	  //flag=4的情况 
	  for (j = 3; j <= n; j++)
	  {
		 for (m = 1; m <= n; m++)
			v[2][m] = v[1][m];
		 for (m = 1; m <= j - 2; m++)
		 {
			for (s = m + 1; s <= j - 1; s++)
			{
			   if (v[2][m].x > v[2][s].x)
			   {
				  v0 = v[2][m];
				  v[2][m] = v[2][s];
				  v[2][s] = v0;
			   }
			}
		 }
		 rect[2].lt = rect[2].rb = v[2][j];
		 for (m = j + 1; m <= n; m++)
			insert(v[2][m], &rect[2]);
		 for (i = 2; i <= j - 1; i++)
		 {
			rect[1].lt = rect[1].rb = v[2][i];
			for (m = i + 1; m <= j - 1; m++)
			   insert(v[2][m], &rect[1]);
			rect[0].lt = rect[0].rb = v[2][1];
			for (m = 2; m <= i - 1; m++)
			   insert(v[2][m], &rect[0]);
			if (intersect(rect[0], rect[1]) || intersect(rect[1], rect[2])
			   || intersect(rect[0], rect[2]))
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)
			   temp += area(rect[m]);
			if (temp < min)
			   min = temp;
		 }
	  }
	  //flag=5的情况 
	  rect[0].lt = rect[0].rb = v[1][1];	//第1个矩形初始值 
	  for (i = 2; i <= n - 1; i++)
	  {
		 for (m = 1; m <= n; m++)
			v[2][m] = v[1][m];
		 for (m = i; m <= n - 1; m++)
		 {
			for (s = m + 1; s <= n; s++)
			{
			   if (v[2][m].x > v[2][s].x)
			   {
				  v0 = v[2][m];
				  v[2][m] = v[2][s];
				  v[2][s] = v0;
			   }
			}
		 }
		 insert(v[2][i - 1], &rect[0]);
		 rect[1].lt = rect[1].rb = v[2][i];
		 if (intersect(rect[0], rect[1]))
			continue;
		 for (j = i + 1; j <= n; j++)
		 {
			insert(v[2][j - 1], &rect[1]);
			rect[2].lt = rect[2].rb = v[2][j];
			for (m = j + 1; m <= n; m++)
			   insert(v[2][m], &rect[2]);
			if (intersect(rect[1], rect[2]))
			   continue;
			temp = 0;
			for (m = 0; m < k; m++)
			   temp += area(rect[m]);
			if (temp < min)
			   min = temp;
		 }
	  }
	  break;
   }
   return min;
}
int main()
{
   VERTEX v0;	//临时交换用顶点 
   int i, j, value;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("rectang.in", "r")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1, "%d%d\n", &n, &k);	//读入点数n和矩形数k
   for (i = 1; i <= n; i++)	//读入各点的坐标 
   {
	  fscanf(fp1, "%d%d\n", &v[0][i].x, &v[0][i].y);
	  v[1][i] = v[0][i];
   }
   fclose(fp1);
   for (i = 1; i <= n - 1; i++)	//按横坐标升序排列各点，存入v[0][i]
   {
	  for (j = i + 1; j <= n; j++)
	  {
		 if (v[0][i].x > v[0][j].x)
		 {
			v0 = v[0][i];
			v[0][i] = v[0][j];
			v[0][j] = v0;
		 }
	  }
   }
   for (i = 1; i <= n - 1; i++)	//将纵坐标升序排列，存入v[i][1] 
   {
	  for (j = i + 1; j <= n; j++)
	  {
		 if (v[1][i].y > v[1][j].y)
		 {
			v0 = v[1][i];
			v[1][i] = v[1][j];
			v[1][j] = v0;
		 }
	  }
   }
   value = calc();
   if ((fp2 = fopen("rectang.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n", value);
   fprintf(fp2, "%d\n", value);
   fclose(fp2);
   getch();
   return 0;
}
