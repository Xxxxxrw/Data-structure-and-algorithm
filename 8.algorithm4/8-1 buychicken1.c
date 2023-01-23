#include <stdio.h>
int main()
{
    int x,y,z;
    for(x=0;x<=20;x++)    //公鸡数量
    {
        for(y=0;y<=33;y++)   //母鸡数量
        {
            z=100-x-y;   //小鸡数量
            if (z%3==0 &&x*5+y*3+z/3==100)  
                printf("公鸡：%d,母鸡：%d,小鸡：%d\n",x,y,z);
        }
    }  
    getch();
    return 0;
}
