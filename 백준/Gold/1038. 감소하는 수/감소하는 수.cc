#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#define ill pair<ll, ll>
#define ll long long
using namespace std;
ll N;
ll cnt;
bool exist;
void backt(ll nownum, ll size)
{
    if (size == 0 && N == cnt)
    {
        cout << nownum << '\n';
        exit(0);
    }
    if (size == 0 && N != cnt)
    {
        cnt++; // 몇번째 감소수인지
    }
    // 아직 자리수 더해야되면
    ll tail = nownum % 10;
    ll next = nownum * 10;
    if (nownum == 0)
    {
        tail = 10;
    }
    for (int i = 0; i < tail; i++)
    {
        if (next + i != 0)
        {
            backt(next + i, size - 1);
        }
    }
}
void input()
{
    cin >> N;
    cnt = 0;
}
void solve()
{
    for (ll i = 0; i <= 10; i++)
    {
        // max가 9876543210 즉 10자리수
        backt(0, i);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll try__ = 1;
    // cin >> try__ ;
    while (try__--)
    {
        input();
        solve();
        cout << "-1\n";
    }

    return 0;
}