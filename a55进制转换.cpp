#include <bits/stdc++.h>
using namespace std;
string box = "0123456789ABCDEF";
int n;   //������� S �Ľ��� 
string s;//������� 
int m;	 //��Ҫת���� m���� 
void print(long long tot) //��ʮ����ת��λm���� 
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
	for(int i = 0; i < len; i++)//��n����ת��Ϊʮ���� 
	{
		tot = box.find(s[i]) + tot * n;
	}
	print(tot);
	return 0;
} 
