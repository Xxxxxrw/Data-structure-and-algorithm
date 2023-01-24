#include <stdio.h>
int main()
{
   char table[12] = { "0123456789X" };   //可能的校验位
   char str[13];
   int i, j, sum;
   FILE *fp1, *fp2;
   if ((fp1 = fopen("isbn.in", "r")) == NULL)   //读取文件ISBN
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fgets(str, 20, fp1); //从文件中读取数据 
   fclose(fp1);	//关闭文件 
   sum = 0;
   j = 1;
   for (i = 0; i < 11; i++) //计算总和 
   {
	  if (i != 1 && i != 5)
		 sum += (str[i] - '0') * j++;
   }
   sum %= 11; //求模 
   sum = 11 - sum;   //求余
   if ((fp2 = fopen("isbn.out", "w")) == NULL)   //打开输出文件
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }   
   if (str[12] == table[sum]) //校验码正确 
   {
	  fputs("Right", fp2); //输出到文件 
	  printf("Right\n");
   }
   else //校验码错误 
   {
	  str[12] = table[sum]; //保存正确校验码 
	  fputs(str, fp2); //输出正确的ISBN到文件 
	  printf("%s\n", str);
   }
   fclose(fp2); //关闭文件 
   getch();
   return 0;
}
