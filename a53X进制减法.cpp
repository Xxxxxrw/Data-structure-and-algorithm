#include <iostream>
#include <cstdio>
using namespace std;
const long long int MAX = 1e5 + 5;
const long long MOD = 1000000007;

int main()
{
    int N;                    //最高为N进制
    cin >> N;
    int Ma, Mb;                //数A、数B的位数
    cin >> Ma;
    int Xa[MAX], Xb[MAX];    //数A、数B再十进制下的表示
    long long int answer = 0, base = 1;

    //输入A、B  低位0 高位Ma/Mb
    for (int i = Ma; i >= 1; i--)
        cin >> Xa[i];

    cin >> Mb;
    for (int i = Mb; i >= 1; i--)
        cin >> Xb[i];


    for (int i = 1; i <= Ma; i++)
    {
        //weight: 该位该取多少进制
        int weight = max(Xa[i], Xb[i]) + 1;
        if (weight < 2)
            weight = 2;

        //规则：X[i]与后面的所有进制逐个相乘
        //base: 根据规则，最后该位数值转换成10进制后乘的倍数
        answer = (answer + (Xa[i] - Xb[i]) * base) % MOD;
        base = (base * weight) % MOD;
    }
    cout << answer % MOD << endl;

    return 0;
}
