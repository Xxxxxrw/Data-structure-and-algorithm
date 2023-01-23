#include<stdio.h>
typedef struct card
{
   int Suit;	//花色 
   char Number;	//牌数 
   float Num;	//游戏中的点数 
}Card;
Card card1[52];	//保存每张扑克的花色、数字、点数 
void ShowCard();	//显示牌
void Shuffle();	//洗牌 
void Deal();	//按顺序发牌 
int main()
{
   int i, suit1, temp;
   char again;
   suit1 = 2;
   for (i = 0; i < 52; i++)	//生成52张牌 
   {
	  if (i % 13 == 0)
		 suit1++;	//改变花色 
	  card1[i].Suit = suit1;	//保存花色 
	  temp = i % 13;
	  if (temp == 0)
		 card1[i].Number = 'A';
	  else if (temp == 9)
		 card1[i].Number = '0';
	  else if (temp == 10)
		 card1[i].Number = 'J';
	  else if (temp == 11)
		 card1[i].Number = 'Q';
	  else if (temp == 12)
		 card1[i].Number = 'K';
	  else
		 card1[i].Number = temp + '1';
	  if (temp >= 10)
		 card1[i].Num = 0.5;
	  else
		 card1[i].Num = temp + 1;
   }
   do
   {
	  ShowCard();	//显示52张牌给游戏者检查 
	  Shuffle();	//洗牌 
	  Deal();	//发牌
	  printf("\n继续玩(y/n)？");
	  fflush(stdin);
	  scanf("%c", &again);
   }while (again == 'y' || again == 'Y');
   getchar();
   return 0;
}
void ShowCard() //显示牌 
{
   int i, j;
   printf("牌列表:");	//显示整副牌给游戏者检查 
   for (i = 0, j = 0; i < 52; i++, j++)
   {
	  if (!(j % 13))
		 printf("\n");
	  printf("  %c%c", card1[i].Suit, card1[i].Number);
   }
}
void Shuffle() //洗牌整副牌给游戏者检查 
{
   int i, j;
   Card tempcard;
   srand((int) time(0));
   for (i = 0; i < 52; i++)
   {
	  j = rand() % 52;	//随机换牌，将牌的顺序打乱,达到洗牌的效果 
	  tempcard = card1[j];
	  card1[j] = card1[i];
	  card1[i] = tempcard;
   }
}
void Deal() //按顺序发牌 
{
   int i, iCount = 0, iMan = 0, iComputer = 0, flag = 1, flag1 = 1;	//iCount为牌的计数器,iMan为游戏者牌的数量,iComputer为计算机牌的数量 
   char continue1;
   float TotalM = 0, TotalC = 0;	//统计游戏者和计算机的总点数 
   Card Man[18], Computer[18];	//保存游戏者和计算机手中的牌 
   while (flag == 1 && iCount < 52)	//还有牌 
   {
	  //游戏者取牌 
	  Man[iMan++] = card1[iCount++];	//发一张牌给游戏者 
	  TotalM += Man[iMan - 1].Num;	//累加游戏者拿牌的总点数 
	  //接下为由计算机取牌
	  if (iCount >= 52)	//牌已取完 
		 flag = 0;
	  else if (TotalM > 10.5)	//游戏者爆了,则不再要牌了
		 flag1 = 0; //计算机不再要牌 
	  else
	  {
		 if ((TotalC < 10.5 && TotalC < TotalM) ||
             TotalC < 7)	//若当前点数小于10.5,且小于游戏者的点数 
		 {
			Computer[iComputer++] = card1[iCount++];	//计算机取一张牌 
			TotalC += Computer[iComputer - 1].Num;	//累计计算机取得牌的总点数 
		 }
	  }
	  printf("\n");
	  printf("你的牌:");
	  for (i = 0; i < iMan; i++)
		 printf("  %c%c", Man[i].Suit, Man[i].Number);
	  printf("\n总点数为:%.1f\n", TotalM);
	  printf("电脑的牌为:");
	  for (i = 0; i < iComputer; i++)
		 printf("  %c%c", Computer[i].Suit, Computer[i].Number);
	  printf("\n总点数为:%.1f\n", TotalC);
	  if (TotalM < 10.5)	//若游戏者点数小于10.5,可继续要牌 
	  {
		 do
		 {
			printf("还要牌吗(y/n)?");
			fflush(stdin);
			scanf("%c", &continue1);
		 }while (continue1 != 'y' && continue1 != 'Y' && continue1 != 'n' && continue1 != 'N');
		 if (continue1 == 'y' || continue1 == 'Y')
			flag = 1;
		 else
			flag = 0;
		 if (iCount == 52)
		 {
			printf("牌已经发完了！\n");
			getch();
			break;
		 }
	  }
      else
		 break;
   }
   while (flag1==1 && iCount < 52)	//游戏者不要牌以后，计算机根据需要可继续要牌 
   {
	  if (TotalM > 10.5)	//游戏者爆了,则不再要牌了
		 break;
	  else
	  {
		 if (TotalC < 10.5 && TotalC < TotalM)	//若当前点数小于10.5,且小于游戏者的点数 
		 {
			Computer[iComputer++] = card1[iCount++];	//计算机取一张牌 
			TotalC += Computer[iComputer - 1].Num;	//累计计算机取得牌的总点数 
		 }
		 else
		     break;
	  }
   }
   printf("\n你的牌:");
   for (i = 0; i < iMan; i++)
	  printf("  %c%c", Man[i].Suit, Man[i].Number);
   printf("\n你的总点数:%.1f\n", TotalM);
   printf("计算机的牌为:");
   for (i = 0; i < iComputer; i++)
	  printf("  %c%c", Computer[i].Suit, Computer[i].Number);
   printf("\n计算机的总点数为:%.1f\n", TotalC);
   if (TotalM > 10.5)	//游戏者爆了 
	  if (TotalC > 10.5)	//计算机爆了
		 printf("\n你赢了！\n");
	  else
		 printf("\n你输了!\n");
   else if (TotalM == 10.5)
	  if (TotalC == 10.5)
		 printf("\n你和计算机打成了平手!\n");
	  else
		 printf("\n你赢了！\n");
   else if (TotalC > 10.5)
	  printf("\n你赢了！\n");
   else if (TotalC > TotalM)
	  printf("\n计算机赢了！\n");
   else if (TotalC == TotalM)
	  printf("\n你和计算机打成了平手！\n");
   else
	  printf("\n你赢了！\n");
}
