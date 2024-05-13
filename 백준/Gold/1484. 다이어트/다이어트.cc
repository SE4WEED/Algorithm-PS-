#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <math.h>
#define iint pair<int, int>
#define ll long long
using namespace std;
ll N;
void input()
{
    cin >> N;
}
void solve()
{
    ll cur;
    ll now;
    bool exist = false;
    now = 1;
    cur = 0;
    ll sq;
    while (true)
    {
        if (now * now - cur * cur > N + 100)
            break;
        if (sqrt(now * now + N) == (int)sqrt(now * now + N))
        {
            cout << (int)sqrt(now * now + N) << '\n';
            exist = true;
        }
        cur = now;
        now++;
    }
    if (!exist)
        cout << "-1\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int try__ = 1;
    // cin >> try__ ;
    while (try__--)
    {
        input();
        solve();
    }

    return 0;
}