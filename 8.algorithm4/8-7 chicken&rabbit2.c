#include <stdio.h>
int main()
{
    int chicken,rabbit,head,foot;
    printf("����ͷ���ͽ���:");
    scanf("%d%d",&head,&foot);
    for(chicken=0;chicken<=head;chicken++)
    {
        rabbit=head-chicken;
        if(chicken*2+rabbit*4==foot)
        {
            printf("����:%dֻ,������:%dֻ��",chicken,rabbit);            
        }            
    }
    getch();
    return 0;
}
