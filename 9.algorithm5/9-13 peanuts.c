#include <stdio.h>
int main()
{
   int a[20][20],m,n,k,time,i,j,row,col,row1,col1,sum,flag; //数组A保存每株树上的蟠桃数
   FILE *fp1, *fp2;
   if ((fp1 = fopen("peanuts.in", "r")) == NULL)   //打开文件，读取数据
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   fscanf(fp1,"%d%d%d\n",&m,&n,&k); //从文件获取行、列、时间 
   for(i=0;i<m;i++) //读入蟠桃园数据 
       for(j=0;j<n;j++)
           fscanf(fp1,"%d",&a[i][j]);       
   fclose(fp1); //关闭文件 
   row=col=0;//起始位置
   sum=0; //已摘得蟠桃数量
   flag=1; //是否能去采摘蟠桃 
   do{
       row1=col1=0; //保存当前蟠桃最多位置坐标 
       for(i=0;i<m;i++) //找出蟠桃最多的坐标位置 
       {
           for(j=0;j<n;j++)
           {
               if(a[i][j]>a[row1][col1])
               {
                   row1=i;
                   col1=j;
               }
           }
       }
       time=abs(row-row1)+abs(col-col1)+row1+1;//求出从原点到含蟠桃数最多的位置摘蟠桃后，回到路边所需单位时间
       if(k<time || a[row1][col1]==0) //若剩余时间不够，或目标位置蟠桃数量为0 
            flag=0; //不采摘 
       if(flag==1) //若可以采摘蟠桃 
       {
           sum+=a[row1][col1]; //累加摘得的蟠桃总数 
           k=k-abs(row-row1)-abs(col-col1)-1; //计算剩余的时间 
           row=row1; //以当前坐标位置为起始点，进行下一步操作 
           col=col1;
           a[row][col]=0; //将采摘蟠桃后的位置清0 
       }
   }while(flag==1); //若还能采摘蟠桃 
   if ((fp2 = fopen("peanuts.out", "w")) == NULL)
   {
	  printf("不能打开文件!\n");
	  exit(1);
   }
   printf("%d\n",sum);
   fprintf(fp2,"%d\n",sum);
   fclose(fp2);
   getch();
   return 0;
}
