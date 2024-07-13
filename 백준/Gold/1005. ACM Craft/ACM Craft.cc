#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int N, M;
vector<int> revNode[1001];
vector<int> node[1001];
int buildTime[1001];
int cnt[1001];
int tmpCnt[1001];
int finTime[1001];
int findexMax(int idx)
{
    int ret = 0;
    for (auto k : revNode[idx])
    {
        ret = max(ret, finTime[k]);
    }
    return ret;
}
void build()
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        tmpCnt[i] = cnt[i];
        if (cnt[i] == 0)
        {
            q.push(i);
        }
    }
    int nowCnt = 0;
    int exTime;
    int now;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        exTime = findexMax(now);
        // 내가 지어지기 위해서 필요한, 직전 건물 중 가장 늦게 세워진놈의 빌드 종료시간
        finTime[now] = exTime + buildTime[now];
        for (auto k : node[now])
        {
            tmpCnt[k]--;
            if (tmpCnt[k] == 0)
            {
                q.push(k);
            }
        }
    }
}
void solve()
{
    // 목적지
    // cnt 0 부터 출발을 하는데.
    // cnt 들을 굳이 깎으며 가지 않는거지
    // 그러면서, 내 직전노드로 연결 되어 있으면서 cnt 내 직전인놈들 중에 최대였던놈의 시간 + 내 건설시간
    // 이렇게 하는거 어떤가?
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        finTime[i] = 0;
        cnt[i] = 0;
        node[i].clear();
        revNode[i].clear();
        cin >> buildTime[i];
    }
    int pre, suc;
    for (int i = 0; i < M; i++)
    {
        cin >> pre >> suc;
        node[pre].push_back(suc);
        revNode[suc].push_back(pre);
        cnt[suc]++;
    }
    int goal;
    cin >> goal;
    build();
    // for (int i = 1; i <= N; i++)
    // {
    //     cout << i << ' ' << finTime[i] << '\n';
    // }
    cout << finTime[goal] << '\n';
}
int main()
{
    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}