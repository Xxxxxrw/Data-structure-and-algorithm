#include <bits/stdc++.h>
using namespace std;
void f(int n)
{
	if(n == 0)
	{
		printf("        ");
		return;
	}
	int len = sizeof(n) * 8;
	if(n > 0)
	{
		printf(" ");
	}
	else{
		printf("*");
	}
	for(int i = 6; i >= 0; i--)
	{
		if( (n & (1<<i) )!= 0)
		{
			printf("*");
		}
		else{
			printf(" ");
		}
	}
}
int main()
{
	int d, i = 0;
	while(~scanf("%d",&d))
	{
		f(d);
		i++;
		if(i % 2 == 0)
			printf("\n");
	}
	return 0;
}
