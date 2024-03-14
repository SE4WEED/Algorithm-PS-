#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> vt;
vector<int> ans;
void input()
{
    cin >> N;
    int i = N;
    int tmp;
    while (i--)
    {
        cin >> tmp;
        vt.push_back(tmp);
    }
}
int bisearch(int size, int num)
{
    int l = 0;
    int r = size;
    int m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (ans[m] < num)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    return r;
}
void solve()
{
    int insert;
    ans.push_back(vt[0]);
    for (int i = 1; i < N; i++)
    {
        if (vt[i] > ans.back())
        {
            ans.push_back(vt[i]);
        }
        else
        {
            insert = bisearch(ans.size(), vt[i]);
            ans[insert] = vt[i];
        }
    }

    cout << ans.size() << '\n';
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