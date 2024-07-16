#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, K;
int primeNum[200001];
void input()
{
    cin >> N >> K;
    // N보다 작은 수 중 소인수 최대가 k안넘는 개수
}
void solve()
{
    // k보다 큰놈으로 분해되면 안되는거
    vector<int> pV;
    for (int i = 2; i <= 100000; i++)
    {
        if (primeNum[i] != 1)
        {
            for (int j = i * 2; j <= 100000; j += i)
            {
                primeNum[j] = 1;
            }
            if (i > K)
            {
                pV.push_back(i);
                // cout << i << '\n';
            }
        }
    }
    int nonSejun = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < pV.size(); j++)
        {
            if (i % pV[j] == 0)
            {
                nonSejun++;
                break;
            }
            if (i <= pV[j])
            {
                break;
            }
        }
    }
    cout << N - nonSejun << '\n';
}
int main()
{
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        input();
        solve();
    }
    return 0;
}