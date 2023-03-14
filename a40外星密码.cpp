#include <bits/stdc++.h>
using namespace std;
bool f;
string read()
{
    char c;
    string s = "";
    while(cin >> c)
    {
        if(c >= 'A' && c <= 'Z')
        {
            s += c;
            //cout << s << endl; 
        }
    
    else
    {
        if(c == '[')
        {
            int n;
            cin >> n;
            string str = read();
            while(n--)
            {
                s += str;
                //cout << s << endl;
            }
        }
        if(c == ']')
        {
            return s;
        }
    }
}
    return s;
}
int main()
{
    string s1 = read();
    cout << s1;
    return 0;
}
