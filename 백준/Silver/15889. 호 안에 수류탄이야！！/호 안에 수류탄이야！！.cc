#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<int> pos;
vector<int> range;
int v[300000];
void input()
{
    int tmp;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        pos.push_back(tmp);
    }
    for (int i = 0; i < N - 1; i++)
    {
        cin >> tmp;
        range.push_back(tmp);
    }
}
void throwFun(int x)
{ // x가 던질때
    if (x == N - 1)
        return;
    int nowPos = pos[x];
    int nowRange = range[x];
    for (int i = x + 1; i < pos.size(); i++)
    {
        if (pos[i] - pos[x] <= range[x])
        {
            if (v[i] == 1)
                continue;
            v[i] = 1;
            throwFun(i);
        }
    }
}
void solve()
{
    v[0] = 1;
    throwFun(0);
    if (v[N - 1] == 0)
    {
        cout << "엄마 나 전역 늦어질 것 같아\n";
    }
    else
    {
        cout << "권병장님, 중대장님이 찾으십니다\n";
    }
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