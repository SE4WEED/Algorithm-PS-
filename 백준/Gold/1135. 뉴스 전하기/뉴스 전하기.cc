#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> arr;
vector<int> edge[51];
int dp[51];
void input()
{
    cin >> N;
    int tmpN = N, tmp;
    while (tmpN--)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
}
void dfs(int x)
{
    // 트리라서 visit필요없는거같은디
    if (dp[x] != -1)
    {
        return;
    }
    int ret = 0;
    vector<int> tmpV;
    for (auto k : edge[x])
    {
        // k는 x의 부하
        dfs(k);
        tmpV.push_back(dp[k]);
    }
    sort(tmpV.begin(), tmpV.end());
    int time = 1;
    for (int i = tmpV.size() - 1; i >= 0; i--)
    {
        tmpV[i] += time;
        time++;
        ret = max(ret, tmpV[i]);
    }
    dp[x] = ret;
    return;
}
void solve()
{
    dp[0] = -1;
    for (int i = 1; i < N; i++)
    {
        edge[arr[i]].push_back(i);
        dp[i] = -1;
    } // edge[상사].push_back(부하)
    dfs(0);
    cout << dp[0] << '\n';
    // for (int i = 0; i < N; i++)
    // {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
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