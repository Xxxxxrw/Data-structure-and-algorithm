#include <stdio.h>
#include <time.h>
int main()
{
	int rightNum=-1,num,n;
	printf("��ѡ��a:������������ b:ʹ��ϵͳ�Զ����ɵ�������(Ĭ���������[1,1000],�ɲ´���Ϊ8)��\n");
	
	
	if(getchar()=='a')
	{
		printf("��������ȷ������\n"); 
		scanf("%d",&rightNum);
		printf("������ɲ²������\n");
	    scanf("%d",&n); 
    }
	else
	{
		srand((unsigned int)time(NULL));
		rightNum=rand()%1000+1; 
		n=9;
	}
	system("cls");
	
	while(n>0)
	{
		n--;
		printf("���������µ�����");
		scanf("%d",&num);
		if(num>rightNum)
		{
			printf("�´���\n"); 
		}
		else if(num<rightNum)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			break;
		}
	}
	if(n==0)
	{
		printf("��������ȫ����������ȷ��Ϊ%d������Ϸ��",rightNum);
	}
	getch();
	return 0;
}
