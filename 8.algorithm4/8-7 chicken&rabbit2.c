#include <stdio.h>
int main()
{
    int chicken,rabbit,head,foot;
    printf("输入头数和脚数:");
    scanf("%d%d",&head,&foot);
    for(chicken=0;chicken<=head;chicken++)
    {
        rabbit=head-chicken;
        if(chicken*2+rabbit*4==foot)
        {
            printf("鸡有:%d只,兔子有:%d只。",chicken,rabbit);            
        }            
    }
    getch();
    return 0;
}
