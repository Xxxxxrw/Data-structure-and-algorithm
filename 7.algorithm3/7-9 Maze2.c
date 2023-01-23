#include <stdio.h>
#include <stdlib.h>
#define MAXROW 25
int maze[MAXROW][MAXROW] = {
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
                {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
                {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,1},
                {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                {1,1,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1},
                {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1},
                {1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1}, 
                {1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1},
                {1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1},
                {1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
                {1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
}; //�Թ����� 
int InX = 1, InY = 1;		// ���
int OutX = MAXROW-2,OutY = MAXROW-2	;	// ����
void PrintMaze()
{
   int i,j;
   for (i = 0; i < MAXROW; i++)    //ѭ����ʾ����
   {
      for (j = 0; j < MAXROW; j++)   //ѭ����ʾһ���еĸ���
      {
         if (maze[i][j] == 1)   //��Ϊ1
            printf("��");    //����ϰ�
         else if (maze[i][j] == -1)   //��Ϊ-1��ʾ��ͨ��
            printf("��");   //���·��
         else
            printf("  ");
            }
      printf("\n");     
  } 
  getch();
}
void pass(int x, int y)
{
   int m, n;
   maze[x][y] = -1; //��ʼ���λ�ÿ�ͨ�� 
   if (x == OutX && y == OutY) //���ѵ��յ� 
   {
	  printf("\n·��:\n");
	  PrintMaze();
   }
   if (maze[x][y + 1] == 0) //���Ҳ�λ��Ϊ�� 
	  pass(x, y + 1); //�ݹ����pass���������Ҳ� 
   if (maze[x + 1][y] == 0) //����λ��Ϊ�� 
	  pass(x + 1, y); //�ݹ����pass���������·� 
   if (maze[x][y - 1] == 0) //�����λ��Ϊ�� 
	  pass(x, y - 1);
   if (maze[x - 1][y] == 0) //���Ҳ�λ��Ϊ�� 
	  pass(x - 1, y);
   maze[x][y] = 0; //����λ���������Ҷ�û��·��������Ϊ��ͨ 
}
int main(void)
{
   int i, j,x,y;   
   printf("�Թ�:\n");
   PrintMaze();
   pass(InX, InY);
   getch();
   return 0;
}

/*
int maze[9][9] = {
                {1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 1, 0, 1, 1, 0, 1},
                {1, 0, 1, 0, 0, 1, 0, 0, 1},
                {1, 0, 1, 0, 1, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 1, 0, 1},
                {1, 1, 0, 1, 1, 0, 1, 1, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1}
}

25
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
                {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
                {1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,0,0,1},
                {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                {1,1,1,0,1,0,1,1,1,0,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1},
                {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,1,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1},
                {1,0,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1}, 
                {1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,0,1},
                {1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,1},
                {1,0,1,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
                {1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
                {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
                {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}




*/