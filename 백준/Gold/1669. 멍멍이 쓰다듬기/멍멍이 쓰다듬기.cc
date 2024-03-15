#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
ll monkey, dog;
ll dif;
void input()
{
    cin >> monkey >> dog;
    dif = dog - monkey;
}
void solve()
{
    ll n = 1;
    while (n * n < dif)
    {
        n++;
    }
    ll r = n * n - dif;
    ll c = 0;
    if (r >= n)
    {
        c = -1;
    }
    cout << n * 2 - 1 + c << '\n';
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int try__ = 1;
    //cin >> try__;
    while (try__--)
    {
        input();
        solve();
    }

    return 0;
}