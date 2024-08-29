#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>
using namespace std;
int N;
int numGroup;
int allHuman;
int ans;
bool firstAns;
int v[11];
int human[11];
int comb[11];
int ok[11];
vector<int> edge[11];
void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> human[i];
        allHuman += human[i];
    }
    int tmp;
    int M;
    for (int i = 1; i <= N; i++)
    {
        cin >> M;
        for (int j = 0; j < M; j++)
        {
            cin >> tmp;
            edge[i].push_back(tmp);
        }
    }
}
int bfs(int start)
{
    int sum = 0;
    v[start] = 1;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int now = q.front();
        sum += human[now];
        int next;
        q.pop();
        for (int i = 0; i < edge[now].size(); i++)
        {
            next = edge[now][i];
            if (v[next] == 0)
            {
                v[next] = 1;
                q.push(next);
            }
        }
    }
    return sum;
}
void initV()
{
    for (int i = 1; i <= N; i++)
    {
        v[i] = 0;
    }
}
void calGroup()
{
    // 그룹 수.
    // 1개 -> 1
    // 2개 -> 2
    // 3개 이상 -> 3
    int cnt = 0;
    initV();
    for (int i = 1; i <= N; i++)
    {
        if (v[i] == 0)
        {
            cnt++;
            bfs(i);
        }
    }
    numGroup = cnt;
    if (numGroup >= 3)
    {
        cout << -1 << '\n';
        exit(0);
    }
}
void realSolve(int m)
{
    int tmpans, nowH = 0;

    initV();
    for (int i = 1; i <= m; i++)
    {
        v[comb[i]] = 2;
        nowH += human[comb[i]];
    }
    bool firstBfs = true;
    for (int i = 1; i <= N; i++)
    {
        if (firstBfs && v[i] == 0)
        {
            firstBfs = false;
            bfs(i);
        }
        else if (!firstBfs && v[i] == 0)
        { // v[i]가 0인놈을 찾았는데 이전에 이미 했었다면
            // 갈라진거임
            return;
        }
    }
    // 여기까지 왔으면 이제 2인놈들을 다시해결
    for (int i = 1; i <= N; i++)
    {
        if (v[i] == 2)
            v[i] = 0;
    }

    firstBfs = true;
    for (int i = 1; i <= N; i++)
    {
        if (firstBfs && v[i] == 0)
        {
            firstBfs = false;
            bfs(i);
        }
        else if (!firstBfs && v[i] == 0)
        { // v[i]가 0인놈을 찾았는데 이전에 이미 했었다면
            // 갈라진거임
            return;
        }
    }
    // 나가리면 이전에 리턴해주고
    tmpans = abs(allHuman - 2 * nowH);
    // cout << ans << " " << tmpans << "\n";
    if (firstAns)
    {
        firstAns = false;
        ans = tmpans;
    }
    else
    {
        ans = min(ans, tmpans);
    }
}
void backt(int last, int num)
{
    if (last == num)
    {
        realSolve(last);
    }
    for (int i = comb[num] + 1; i <= N; i++)
    {
        if (ok[i])
        {
            continue;
        }
        ok[i] = true;
        comb[num + 1] = i;
        backt(last, num + 1);
        ok[i] = false;
    }
}
void solve()
{
    // 우선 순회돌아서
    // 세묶음 이상으로 쪼개진다면 -> 불가능
    // 두묶음 이라면 -> 걔네가 걍 답
    // 한묶음일 때, 복잡해짐 N이 최대 10개밖에 없으니 그냥 2^10 완전탐색 하는게 나을거같기도?
    // ex) 파란당에 1이 가장 작은 구역이면서 가능한 모든 경우의수 ( 백트래킹처럼 돌면서 하면 될거같은데? )
    // ex) 파란당에 2가 가장 작은 구역 ''
    // ... 이렇게
    calGroup();
    if (numGroup == 2)
    {
        int tmp;
        initV();
        for (int i = 1; i <= N; i++)
        {
            if (v[i] == 0)
            {
                tmp = bfs(i);
                break;
            }
        }
        cout << abs(allHuman - 2 * tmp) << '\n';
    }
    else
    { // 한개짜리 그룹일 때,
        // 조합을 따져봐야?
        // 10C1 10C2 10C3 10C4 ... 10C9까지 해서?
        // 아니면 그래프탐색식 백트래킹
        // 1을 포함하면서 bfs해서 하나씩 포함시켜주기
        // 걍 조합으로 하고
        // 거기로 갔을 때 단절이 생기는지를 확인하는게
        // 나을듯?
        // ㅇㅋ 조합으로 경우들 찾고
        // 조합으로 찾은 경우들을 2로 마킹해
        // 그리고 0인애들을 그래프탐색해서 한번만에 1로 만드는게 가능한지 확인
        // 2로 마킹한애들 다시 0으로 바꿔주고
        // 한번만에 0을 다 1로만드는게 가능한지 확인
        ans = 0;
        firstAns = true;
        for (int i = 1; i < N; i++)
        { // NC1부터 NCN-1
            comb[0] = 0;
            backt(i, 0);
        }
        if (firstAns)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans << '\n';
        }
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