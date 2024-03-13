#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
int dp[100001][2];
int hum[10001];
int vis[10001];
vector<int> edge[100001];
void input()
{
    int i = 1;
    cin >> N;
    while (i <= N)
    {
        cin >> hum[i++];
    }
    i = 1;
    int a, b;
    while (i <= N - 1)
    {
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        i++;
    }
    return;
}
void dfs(int x)
{
    vis[x] = 1;
    dp[x][0] = 0;
    dp[x][1] = hum[x];
    for (int i = 0; i < edge[x].size(); i++)
    {
        int xx = edge[x][i];
        if (vis[xx] == 1)
        {
            continue;
        }
        dfs(xx);
        dp[x][0] += max(dp[xx][0], dp[xx][1]);
        dp[x][1] += dp[xx][0];
    }
    return;
}
void solve()
{
    dfs(1);
    int ans = max(dp[1][0],dp[1][1]);
    cout << ans << '\n';
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