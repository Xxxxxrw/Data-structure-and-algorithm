#include <iostream>
#include <set> 
using namespace std;
int total = 0, X;
int favor[22][2];
set<int> book;
int func(int x, int b)
{
	int t = favor[x][b];
    book.insert(t);
    cout << "½øÈë" << endl;
    return 0;
    if(x == 1)
    {
        if(book.size() == X)
        {
            total++;
            book.erase(x);
            return 0;
        }
    }
    func(x-1, 0);
    func(x-1, 1);
    book.erase(x);
    return 0;
}
int main()
{
    cin >> X;
    favor[0][0]=0;
    favor[0][1]=1;
    for(int i = 1; i <= X; i++)
    {
        cin >> favor[i][0] >> favor[i][1];
    }
    func(X, 0);
    func(X, 1); 
    cout << total;
    return 0;
}
