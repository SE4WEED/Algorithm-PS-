#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define iint pair<int, int>
#define iintint pair<iint, int>
#define ll long long
using namespace std;
struct cmp
{
    bool operator()(iintint a, iintint b)
    {
        return a.second > b.second;
    }
};
int N, M, p, q;
int par[100001];
int find(int x)
{
    if (par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
void merge(int x, int y)
{
    int px = find(x);
    int py = find(y);
    if (px == py)
        return;
    if (px < py)
    {
        par[py] = px;
    }
    else
    {
        par[px] = py;
    }
}
vector<iintint> ans;
priority_queue<iintint, vector<iintint>, cmp> edge;
void input()
{

    int u, v, w;
    cin >> N >> M >> p >> q;
    int i = 0;

    while (!edge.empty())
    {
        edge.pop();
    }
    while (i < M)
    {
        cin >> u >> v >> w;
        edge.push({{u, v}, w});

        i++;
    }
}
void solve()
{

    for (int i = 0; i <= N; i++)
    {
        par[i] = i;
    }
    ans.clear();
    bool ok = false;
    iintint tmp;
    while (!edge.empty())
    {
        tmp = edge.top();
        edge.pop();
        // cout << tmp.first.first << ' ' << tmp.first.second << ' ' << find(tmp.first.first) << ' ' << find(tmp.first.second) << '\n';
        if (find(tmp.first.first) != find(tmp.first.second))
        {
            merge(tmp.first.first, tmp.first.second);
            ans.push_back(tmp);
            if (tmp.first.first == p && tmp.first.second == q)
            {
                ok = true;
            }
            if (tmp.first.first == q && tmp.first.second == p)
            {
                ok = true;
            }
        }
        // 하나라도 방문 안한게 있으면 ㅇㅇ
    }
    if (ok)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int try__ = 1;
    cin >> try__;
    while (try__--)
    {
        input();
        solve();
    }

    return 0;
}