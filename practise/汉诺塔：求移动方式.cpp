#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    
    vector<string> getSolution(int n) {
        // write code here
        helper(n, "left", "mid", "right");
        return ans;
    }
    int helper(int n,string left, string mid, string right){
        if(n==0)
            return 0;
        if(n==1){
            ans.push_back("move from "+left+" to "+right);
            return 0;
        }
        helper(n-1, left, right, mid);
        ans.push_back("move from "+left+" to "+right);
        helper(n-1, mid, left, right);
            
        return 0;
            
    }
private:
    vector<string> ans;
};
int main()
{
	Solution s1;
	int n;
	cin >> n;
	vector<string> vec(s1.getSolution(n));
	for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
