#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
long long N, M, K;
long long MAX = -1;
long long cnt[200001] = {
    0,
};
long long sumCnt[200001] = {
    0,
};
long long sumAll[200001] = {
    0,
};
long long ans[200001] = {
    0,
};
long long sum;
void input()
{
    cin >> N >> M;
    long long tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        for (int j = 0; j < K; j++)
        {
            cin >> tmp;
            if (j == 0 || j == K - 1)
            {
                // cout << tmp << '\n';

                cnt[tmp]++;
                MAX = max(MAX, tmp);
            }
        }
    }
}
//
// 누적합으로
// 해당번까지 몇개인지랑
// 해당번까지 값이 얼마인지 ( 개수 * 방번호 )
void solve()
{
    sumCnt[0] = 0;
    sumAll[0] = 0;
    sumCnt[1] = cnt[1];
    sumAll[1] = cnt[1] * 1;
    for (int i = 2; i <= MAX; i++)
    {
        sumCnt[i] = sumCnt[i - 1] + cnt[i];
        sumAll[i] = sumAll[i - 1] + cnt[i] * i;
        // cout << "i " << i << " - " << cnt[i] << " " << sumCnt[i] << " " << sumAll[i] << " \n";
    }
    long long minAns = -1;
    long long ret;
    for (int i = 1; i <= MAX; i++)
    {
        ans[i] = (i * sumCnt[i - 1] - sumAll[i - 1]) + ((sumAll[MAX] - sumAll[i]) - (i * (sumCnt[MAX] - sumCnt[i])));
        if (i == 1 || ans[i] < minAns)
        {
            minAns = ans[i];
            ret = i;
        }
        // cout << ans[i] << '\n';
    }
    cout << ret << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;
    // cin >> tt;
    while (tt--)
    {
        input();
        solve();
    }
    return 0;
}