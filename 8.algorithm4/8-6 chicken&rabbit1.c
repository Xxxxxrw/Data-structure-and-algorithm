#include <stdio.h>
int main()
{
    int chicken,rabbit,head,foot;
    printf("����ͷ���ͽ���:");
    scanf("%d%d",&head,&foot);
    rabbit=(foot-2*head)/2; //���ܽ���foot��ȥ������2*head
    chicken=head-rabbit;  //����ͷ����ȥ��������ʣ��ľ��Ǽ���
    printf("����:%dֻ,������:%dֻ��",chicken,rabbit);
    getch();
    return 0;
}
