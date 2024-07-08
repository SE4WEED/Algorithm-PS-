#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
int arr[11];
int ans[11];
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}
void solve()
{
    for (int i = 0; i < N; i++)
    {
        ans[i] = -1;
    }
    for (int i = 0; i < N; i++)
    {
        int nowcnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (nowcnt >= arr[i]) // 원하는 빈자리보다 지금까지 카운팅한게 많으면
            {
                if (ans[j] == -1)
                {
                    // 나보다 큰놈이 들어갈수 있는 자리가 i개
                    ans[j] = i + 1;
                    break;
                }
                else
                {
                    nowcnt++;
                }
            }
            else
            {
                if (ans[j] == -1) // 빈자리면
                {
                    nowcnt++; // 빈자리카운트 늘리기
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
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