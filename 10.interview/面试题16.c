#include "stdio.h"

int StrRev()       //递归调用实现字符串反转
{
    char c;
    scanf("%c",&c);
    if('#' == c)
    {
        printf("反转后的字符串："); 
        return 0;
    }
    StrRev();
    printf("%c",c);
}

int main()
{
   printf("请输入英文字符串(以#结束):"); 
   StrRev();
   getche();
   return 0;
}