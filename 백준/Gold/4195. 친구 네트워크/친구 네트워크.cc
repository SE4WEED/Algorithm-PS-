#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
int N;
int dp[200001];
void input()
{
    cin >> N;
}
int Find(vector<int> &par, int i)
{
    if (par[i] == i)
    {
        return i;
    }
    return par[i] = Find(par, par[i]);
}
int Union(vector<int> &par, vector<int> &height, int i, int j)
{
    // cout << i << ' ' << j << '\n';
    int pi = Find(par, i);
    int pj = Find(par, j);
    int ret;
    if (pi == pj)
        return dp[pi];
    if (height[pi] == height[pj])
    {
        par[pi] = pj;
        height[pj]++;
        dp[pj] += dp[pi];
        ret = dp[pj];
    }
    else if (height[pi] > height[pj])
    {
        // pi가 더 높을때 -> pj를 pi자식으로 넣어주기
        dp[pi] += dp[pj];
        par[pj] = pi;
        ret = dp[pi];
    }
    else
    {
        dp[pj] += dp[pi];
        par[pi] = pj;
        ret = dp[pj];
    }
    return ret;
}
void solve()
{
    unordered_map<string, int> mp;
    vector<int> par(N * 2);
    vector<int> height(N * 2);

    string str1, str2;
    int cnt = 0;
    int ans, now;
    for (int i = 0; i < N; i++)
    {
        cin >> str1 >> str2;
        if (mp.find(str1) == mp.end())
        {
            par[cnt] = cnt;
            dp[cnt] = 1;
            mp[str1] = cnt++;
        }

        if (mp.find(str2) == mp.end())
        {
            par[cnt] = cnt;
            dp[cnt] = 1;
            mp[str2] = cnt++;
        }
        cout << Union(par, height, mp[str1], mp[str2]) << '\n';
    }
}
// 두개 사이에 엣지를 만들기 -> Union
// n개 돌면서 find값 같은거 뱉기?
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        input();
        solve();
    }
    return 0;
}