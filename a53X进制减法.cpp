#include <iostream>
#include <cstdio>
using namespace std;
const long long int MAX = 1e5 + 5;
const long long MOD = 1000000007;

int main()
{
    int N;                    //���ΪN����
    cin >> N;
    int Ma, Mb;                //��A����B��λ��
    cin >> Ma;
    int Xa[MAX], Xb[MAX];    //��A����B��ʮ�����µı�ʾ
    long long int answer = 0, base = 1;

    //����A��B  ��λ0 ��λMa/Mb
    for (int i = Ma; i >= 1; i--)
        cin >> Xa[i];

    cin >> Mb;
    for (int i = Mb; i >= 1; i--)
        cin >> Xb[i];


    for (int i = 1; i <= Ma; i++)
    {
        //weight: ��λ��ȡ���ٽ���
        int weight = max(Xa[i], Xb[i]) + 1;
        if (weight < 2)
            weight = 2;

        //����X[i]���������н���������
        //base: ���ݹ�������λ��ֵת����10���ƺ�˵ı���
        answer = (answer + (Xa[i] - Xb[i]) * base) % MOD;
        base = (base * weight) % MOD;
    }
    cout << answer % MOD << endl;

    return 0;
}
