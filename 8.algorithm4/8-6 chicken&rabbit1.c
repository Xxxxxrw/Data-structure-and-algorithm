#include <stdio.h>
int main()
{
    int chicken,rabbit,head,foot;
    printf("输入头数和脚数:");
    scanf("%d%d",&head,&foot);
    rabbit=(foot-2*head)/2; //用总脚数foot减去鸡脚数2*head
    chicken=head-rabbit;  //用总头数减去兔子数，剩余的就是鸡数
    printf("鸡有:%d只,兔子有:%d只。",chicken,rabbit);
    getch();
    return 0;
}
