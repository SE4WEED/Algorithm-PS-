#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#define iint pair<int, int>
#define ll long long
using namespace std;

// 10159 저울
// direct 그래프 만들고
// 아래방향, 윗방향 dfs 각각
// v 안한거 개수 세기
// dd?
int N;
int M;
vector<int> edge[101];
vector<int> revedge[101];
int v[101];
void input()
{
    cin >> N >> M;
    int i = 1;
    int s, e;
    while (i++ <= M)
    {
        cin >> s >> e;
        edge[s].push_back(e);
        revedge[e].push_back(s);
    }
}
void findFunrev(int start)
{
    v[start] = 1;
    queue<int> q;
    q.push(start);
    int now;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (auto next : edge[now])
        {
            if (v[next] == 0)
            {
                v[next] = 1;
                q.push(next);
            }
        }
    }
    return;
}
void findFun(int start)
{
    v[start] = 1;
    queue<int> q;
    q.push(start);
    int now;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        for (auto next : revedge[now])
        {
            if (v[next] == 0)
            {
                v[next] = 1;
                q.push(next);
            }
        }
    }
    return;
}
void printans()
{
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        if (v[i] == 0)
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return;
}
void initvis()
{
    for (int i = 1; i <= N; i++)
    {
        v[i] = 0;
    }
}
void solve()
{
    for (int i = 1; i <= N; i++)
    {
        initvis();
        findFun(i);
        findFunrev(i);
        printans();
    }
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