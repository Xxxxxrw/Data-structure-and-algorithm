#include <stdio.h>
int main()
{
    int ladder=7;      //初始为7阶
    while(1)
    {
        if((ladder%2==1) && (ladder%3==2) && (ladder%5==4) && (ladder%6==5))
            break;
        ladder+=7;    //每次增加7阶
    }
    printf("该阶梯至少有%d阶。\n",ladder); 
    getch();
    return 0;
}
