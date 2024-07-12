#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> v[32001];
int cnt[32001];
void input()
{
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        cnt[b]++; // b보다 먼저와야하는 놈 개수
        // 이게 작은애부터 쓰면 된다
    }
}
void solve()
{
    // cnt0인놈을 찾아서, 걔부터 시작을 한다
    // 이렇게 하기 위해서 한번 순회하면서 cnt==0에 대해서 큐에 넣어버린다
    // 넣고나서 벡터 타고 가면서, 꽂는곳에 cnt 줄여주고, 0되면 큐에 넣어준다
    // ㅇㅇ
    queue<int> q;
    queue<int> ans;
    for (int i = 1; i <= N; i++)
    {
        if (cnt[i] == 0)
            q.push(i);
    }
    int a;
    while (!q.empty())
    {
        a = q.front();
        cout << a << " ";
        q.pop();
        for (auto b : v[a])
        {
            cnt[b]--;
            if (cnt[b] == 0)
                q.push(b);
        }
    }
    cout << '\n';
}
int main()
{
    int tt = 1;
    // cin >> tt;
    input();
    while (tt--)
    {
        solve();
    }
    return 0;
}