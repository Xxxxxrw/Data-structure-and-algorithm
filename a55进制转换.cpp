#include <bits/stdc++.h>
using namespace std;
string box = "0123456789ABCDEF";
int n;   //输入的数 S 的进制 
string s;//输入的数 
int m;	 //需要转换成 m进制 
void print(long long tot) //将十进制转换位m进制 
{
	if(tot > 0)
	{
		print(tot / m);
		cout << box[tot % m];
	}
}
int main()
{
	cin >> n >> s >> m;
	int len = s.size();
	long long tot = 0;
	for(int i = 0; i < len; i++)//将n进制转换为十进制 
	{
		tot = box.find(s[i]) + tot * n;
	}
	print(tot);
	return 0;
} 
