#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	//用scanf输入string length(),size(),reverse(a.begin(),a.end())等不可使用 
	string a;
	scanf("%s",&a[0]);
	printf("%d\n",a.length());
	printf("%d\n",a.size());
	
	char arr[100];
	scanf("%s",arr);
	a = arr;
	printf("%d\n",a.length());
	printf("%d\n",a.size());
	
	
	strrev(&a[0]); 
	printf("%s\n",a.c_str());
	return 0;
}
