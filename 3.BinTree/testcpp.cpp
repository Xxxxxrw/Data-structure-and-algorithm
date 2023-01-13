#include <iostream>

#include <string> 

using namespace std;
string a[10];
bool cmp(string x,string y)
{
	
	cout << x << " " << y << endl;
	printf("hello");
	return 1;
}
int main()
{
	cin>>a[0]>>a[1];
	cmp(a[0],a[1]);
	
    return 0;
}
