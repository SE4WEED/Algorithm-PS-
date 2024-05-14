#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <string.h>
#define ll long long
#define iint pair<int, int>
#define INF 999999999
using namespace std;
int N, M, X;
int ans[1001];
vector<pair<int, int>> dis[1001];
struct cmp
{
    bool operator()(iint a, iint b) // 비용, 목적지
    {
        return a.first > b.first;
    }
};

void input()
{
    int s, e, cost;
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        cin >> s >> e >> cost;
        dis[s].push_back({cost, e});
    }
}
int dijkstra(int start, int desti)
{
    int ans[1001];
    for (int i = 1; i <= N; i++)
    {
        ans[i] = INF;
    }
    priority_queue<iint, vector<iint>, cmp> pq;
    pq.push({0, start});
    ans[start] = 0;
    while (!pq.empty())
    {
        auto [cost, end] = pq.top();
        if (end == desti)
        {
            return ans[desti];
        }
        pq.pop();
        for (int i = 0; i < dis[end].size(); i++)
        {
            int nextnode = dis[end][i].second;
            int cc = dis[end][i].first;
            if (ans[end] + cc < ans[nextnode])
            {
                ans[nextnode] = ans[end] + cc;
                pq.push({ans[nextnode], nextnode});
            }
        }
    }
    return ans[desti];
}
void solve()
{
    // 목적지는 X
    int ans = -1;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, dijkstra(i, X) + dijkstra(X, i));
    }
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