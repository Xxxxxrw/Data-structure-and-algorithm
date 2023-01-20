#include <iostream>
#include <set>

using namespace std;

int main()
{
	//set 嵌套 set 对内层set的排序会按内层set的数据依次进行比较，null最小 
    int n;
    int a[n];
    set<set<int> >s2t;
    set<int> set1;
	set1.insert(1);
	set1.insert(2); 
	set1.insert(4);
	set1.insert(5);
	s2t.insert(set1);
	
	
	set1.clear();
	set1.insert(1);
	set1.insert(3);
	s2t.insert(set1);
	
	set1.clear();
	set1.insert(1);
	set1.insert(2);
	s2t.insert(set1);
	
	set1.clear();
	set1.insert(1);
	set1.insert(2);
	s2t.insert(set1);
	for(set<set<int> >::iterator it1 = s2t.begin(); it1 != s2t.end(); it1++)
	{
		for(set<int>::iterator it = (*it1).begin(); it != (*it1).end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	
	cout << s2t.size() << endl;
	
    return 0;
}
