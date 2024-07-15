#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
int primeNumber[1000001];
// 골드바흐의 추측.
// 모든 두 짝수는 소수의 합으로 나타낼 수 있다.
void input()
{
    cin >> N;
}
void findPrime(int maxNum)
{
    primeNumber[1] = 1;
    for (int i = 2; i <= maxNum; i++)
    {
        if (primeNumber[i] == 0)
        { // 소수라면
            for (int j = i * 2; j <= maxNum; j += i)
            {
                primeNumber[j] = 1;
            }
        }
    }
}
void findTwoPrime(int goal)
{
    for (int i = 2; i <= goal; i++)
    {
        if (primeNumber[i] == 0 && primeNumber[goal - i] == 0)
        {
            cout << i << ' ' << goal - i << '\n';
            return;
        }
    }
    return;
}
void solve()
{
    findPrime(N);
    if (N < 8)
    {
        cout << "-1\n";
    }
    else if (N % 2 == 0)
    { // 이미 짝수면
        cout << "2 2 ";
        findTwoPrime(N - 4);
    }
    else
    {
        cout << "2 3 ";
        findTwoPrime(N - 5);
    }
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