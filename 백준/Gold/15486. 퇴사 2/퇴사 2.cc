#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#define iint pair<int, int>
#define ll long long
using namespace std;
int N;
int t[1500001];
int p[1500001];
int dp[1500001];
vector<int> last[1500001];
void input()
{
    cin >> N;
    int i = 1;
    while (i <= N)
    {
        cin >> t[i] >> p[i];
        if (i + t[i] - 1 <= N)
        {
            last[i + t[i] - 1].push_back(i);
        }
        i++;
    }
}
void solve()
{
    for (int i = 1; i <= N; i++)
    {
        for (auto tt : last[i])
        {
            dp[i] = max(dp[i], dp[i - t[tt]] + p[tt]);
        }
        dp[i] = max(dp[i], dp[i - 1]);
    }
    cout << dp[N] << '\n';
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